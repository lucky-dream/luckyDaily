#include"net/context.h"
namespace luckyDaily
{

	context::context(const evpp::http::ContextPtr & ctx , const string rsp_body
		, const ResponseHandlerType rsp_type):_ctx(ctx),_rsp_body(rsp_body),
		_rsp_type(rsp_type)
		
	{
	}
	context::~context()
	{
	}
	bool context::Init()
	{
		if (!_ctx.get())
		{
			//todo:@str set log
			return false;
		}
		return _ctx->Init();
	}
	void context::AddResponseHeader(const std::string & key, const std::string & value)
	{
		if (!_ctx.get())
		{
			//todo:@str set log
			return ;
		}
		return _ctx->AddResponseHeader(key,value);
	}
	const char * context::FindRequestHeader(const char * key)
	{
		if (!_ctx.get())
		{
			//todo:@str set log
			return NULL;
		}
		return _ctx->FindRequestHeader(key);
	}
	const char * context::original_uri() const
	{
		if (!_ctx.get())
		{
			//todo:@str set log
			return NULL;
		}
		return _ctx->original_uri();
	}
	const std::string & context::uri() const
	{
		if (!_ctx.get())
		{
			//todo:@str set log
			return std::string();
		}
		return _ctx->uri();
	}
	const std::string & context::remote_ip() const
	{
		if (!_ctx.get())
		{
			//todo:@str set log
			return std::string();
		}
		return _ctx->remote_ip();
	}
	const string & context::body() const
	{
		if (!_ctx.get())
		{
			//todo:@str set log
			return string();
		}
		return string(_ctx->body().data(),_ctx->body().size());
	}
	evhttp_request * context::req() const
	{
		if (!_ctx.get())
		{
			//todo:@str set log
			return NULL;
		}
		return _ctx->req();
	}
	void context::set_response_http_code(int code)
	{
		if (!_ctx.get())
		{
			//todo:@str set log
			return;
		}
		_ctx->set_response_http_code(code);
	}
	int context::response_http_code() const
	{
		if (!_ctx.get())
		{
			//todo:@str set log
			return 0;
		}
		return _ctx->response_http_code();
	}
	void context::set_response_http_body(const string & body)
	{
		_rsp_body.assign(_rsp_body);
	}
	bool context::add_fwd_http_head(const string & name, const string & value)
	{
		if (_inside_head.has(name))
		{
			_inside_head.erase(name);
		}
		_inside_head.add(name,value);
		return true;
	}
	std::string context::GetQuery(const char * query_key, size_t key_len)
	{
		if (!_ctx.get())
		{
			//todo:@str set log
			return std::string();
		}
		return _ctx->GetQuery(query_key, key_len);
	}
	std::string context::GetQuery(const std::string & query_key)
	{
		if (!_ctx.get())
		{
			//todo:@str set log
			return std::string();
		}
		return _ctx->GetQuery(query_key);
	}
	std::string context::FindClientIPFromURI(const char * uri, size_t uri_len)
	{
		return evpp::http::Context::FindClientIPFromURI(uri,uri_len);
	}
	std::string context::FindQueryFromURI(const char * uri, size_t uri_len, const char * key, size_t key_len)
	{
		return evpp::http::Context::FindQueryFromURI(uri,uri_len,key,key_len);
	}
	std::string context::FindQueryFromURI(const char * uri, const char * key)
	{
		return evpp::http::Context::FindQueryFromURI(uri,key);
	}
	std::string context::FindQueryFromURI(const std::string & uri, const std::string & key)
	{
		return evpp::http::Context::FindQueryFromURI(uri,key);
	}
}