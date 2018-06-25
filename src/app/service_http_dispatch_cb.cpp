#include"app/service_http_dispatch_cb.h"
#include"net/http_def.h"
#include"net/slice.h"
#include"util/string_util.h"
#include"util/name_value_collection.h"
#include"app/service_cmd_mgr.h"
#include"util/code_util.h"
namespace luckyDaily
{
	static void ParserURI(std::string& in_uri/*, std::string& out_theme, std::string& out_layer*/, name_value_collection& out_nv)
	{
		std::string name;
		std::string value;
		name.reserve(64);
		value.reserve(64);
		std::string::const_iterator it = in_uri.begin();
		std::string::const_iterator end = in_uri.end();
		while (it != end)
		{
			name.clear();
			value.clear();
			while (it != end && *it != '=') { name += *it++; }
			while (it != end && *it == '=') { it++; }    //escape '='
			while (it != end && *it != '&') { value += *it++; }    //escape '/';
			while (it != end && *it == '&') { it++; }    //escape '&'
														 //keep the key to lower.
			out_nv.add(string_util::toLowerInPlace(name), value);
		}
	}
	static void get_query_paramter(const std::string& orig_uri, std::string& out_str)
	{
		std::string::size_type pos = orig_uri.find('?');
		if (pos != std::string::npos)
		{
			out_str = orig_uri.substr(pos + 1);
			return;
		}
		out_str.append("");
	}
	static bool is_basic(const string& auth)
	{
		if (auth.length() <= 5)
		{
			return false;
		}
		string basic = auth.substr(0, 5);
		if (basic == "Basic")
		{
			return true;
		}
		return false;
	}

	static string decode_base64(string auth)
	{
		if (auth.length() < 6)
		{
			return string();
		}
		string user_data = auth.substr(6, auth.length() - 6);
		if (user_data.empty())
		{
			return string();
		}
		string out_user_data;
		code_util::base64_decode(user_data, out_user_data);
		return out_user_data;
	}
	void service_http_dispatch_cb::service_http_handler_callback(const LFCtxPtr & ctx)
	{
		std::string query;
		//ctx->AddResponseHeader
		if ((http_def::http_method_type)(ctx->get_req_type()) == http_def::HTTP_REQ_GET
			|| (http_def::http_method_type)(ctx->get_req_type()) == http_def::HTTP_REQ_POST)
		{
			string orig_uri = (ctx->original_uri() == nullptr) ? "" : ctx->original_uri();
			get_query_paramter(orig_uri, query);

		}
		else
		{
			ctx->set_response_http_code(http_def::HTTP_NOT_IMPLEMENTED);
			ctx->AddResponseHeader("Content-Type", "text/html");
			ctx->AddResponseHeader("Server", "LF_TASK");
			ctx->AddResponseHeader("Access-Control-Allow-Origin", "*");
			ctx->AddResponseHeader("Transfer-Encoding", "utf-8");
			string err = "Not Implemented£¡";
			ctx->AddResponseHeader("Content-Length", std::to_string(err.length()));
			ctx->set_response_http_body(err); 
			return;
		}
		name_value_collection name_value;
		ParserURI(query, name_value);

		std::string op = name_value.get("op", "");
		if (op.empty())
		{
			ctx->set_response_http_code(http_def::HTTP_BAD_REQUEST);
			ctx->AddResponseHeader("Content-Type", "text/html");
			ctx->AddResponseHeader("Server", "LF_TASK");
			ctx->AddResponseHeader("Access-Control-Allow-Origin", "*");
			ctx->AddResponseHeader("Transfer-Encoding", "utf-8");
			string err = "Bad Request£¡";
			ctx->AddResponseHeader("Content-Length", std::to_string(err.length()));
			ctx->set_response_http_body(err);
			return;
		}
		service_http_dispatch::http_service_handler_dispath(ctx,name_value, op);
	}
	void service_http_dispatch_cb::default_http_handler_callback(const LFCtxPtr & ctx)
	{
		ctx->set_response_http_code(http_def::HTTP_NOT_FOUND);
		ctx->AddResponseHeader("Content-Type", "text/html");
		ctx->AddResponseHeader("Server", "LF_TASK");
		ctx->AddResponseHeader("Access-Control-Allow-Origin", "*");
		ctx->AddResponseHeader("Transfer-Encoding", "utf-8");
		string err = "Not Found£¡";
		ctx->AddResponseHeader("Content-Length", std::to_string(err.length()));
		ctx->set_response_http_body(err);
		return;
	}
	void service_http_dispatch::http_service_handler_dispath(const LFCtxPtr & ctx, const name_value_collection & params, const string & op)
	{
		uint32_t cmd = service_cmd_map::singleton_obj().get_cmd(op);
		bool ret = false;
		string body;
		ResponseHandlerType rht = ResponseHandlerType::kNormal;
		switch (cmd)
		{
		case SVR_CMD_LOGIN:
		{
			string name, password;
			string str = "Authenticate";
			const char* auth = ctx->FindRequestHeader(str.c_str());
			if (auth == NULL)
			{
				ret = false;
				body.append("Not Authenticate!");
			}
			else
			{
				if (!is_basic(auth))
				{
					ret = false;
					body.append("Not Auth!");
				}
				else
				{
					string user_info = decode_base64(auth);
					if (user_info.empty())
					{
						ret = false;
						body.append("Not UserInfo!");
					}
					else
					{
						int index = user_info.find_first_of(":");
						name = user_info.substr(0, index);
						password = user_info.substr(index + 1, user_info.length() - index - 1);
					//	ret = lf_task_service_handler::login(name, password, body);
					}
				}
			}
			ctx->set_response_http_code(ret ? http_def::HTTP_OK : http_def::HTTP_UNAUTHORIZED);
			ctx->AddResponseHeader("Content-Type", "text/html");
			ctx->AddResponseHeader("Server", "LF_TASK");
			ctx->AddResponseHeader("Access-Control-Allow-Origin", "*");
			ctx->AddResponseHeader("Transfer-Encoding", "utf-8");
			ctx->AddResponseHeader("Content-Length", std::to_string(body.length()));
			ctx->set_response_http_body(body);
			return;
		}
		case SVR_CMD_LOGOUT:
		{
			std::string token = params.get("token", "?");
			//lf_task_service_handler::logout(token, body);
			break;
		}
		case SVR_CMD_REGISTER:
		{
			std::string param = ctx->body();
			//ret = lf_task_service_handler::user_register(param, body);
			break;
		}
		case SVR_CMD_CONFIRM:
		{
			std::string param = ctx->body();
			//ret = lf_task_service_handler::register_confirm(param, body);
			break;
		}
		default:
			break;
		}
		if (rht == ResponseHandlerType::kNormal)
		{
			ctx->set_response_http_code(ret ? http_def::HTTP_OK : http_def::HTTP_BAD_REQUEST);
			ctx->AddResponseHeader("Content-Type", "text/html");
			ctx->AddResponseHeader("Server", "LF_TASK");
			ctx->AddResponseHeader("Access-Control-Allow-Origin", "*");
			ctx->AddResponseHeader("Transfer-Encoding", "utf-8");
			ctx->AddResponseHeader("Content-Length", std::to_string(body.length()));
			ctx->set_response_http_body(body);
			ctx->set_response_hander_type(rht);
		}
		return;
	}
}