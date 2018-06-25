#ifndef IF_CONTEXT_H
#define IF_CONTEXT_H
#include"util/base_def.h"
#include "evpp/http/context.h"
#include "net/slice.h"
#include "evpp/libevent.h"
#include "util/name_value_collection.h"
#include<memory>
namespace luckyDaily
{
	enum ResponseHandlerType
	{
		kNormal,
		kProxy,
		kProxyWithHandler
	};
	class context
	{
	public:
		context(const evpp::http::ContextPtr& ctx, const string rsp_body = "",const ResponseHandlerType rsp_type = ResponseHandlerType::kNormal);
		~context();
		bool Init();

		void AddResponseHeader(const std::string& key, const std::string& value);

		// Finds the value belonging to a header.
		//
		// @param key the name of the header to find
		// @returns a pointer to the value for the header or nullptr if the header
		// could not be found.
		const char* FindRequestHeader(const char* key);

		// The original URI, with original parameters, e.g. : /status.html?code=utf8
		const char* original_uri() const;

		// The URI without any parameters
		const  std::string& uri() const;

		const std::string& remote_ip() const;

		const string& body() const;

		struct evhttp_request* req() const;

		void set_response_http_code(int code);

		int response_http_code() const;

		void set_response_http_body(const string& body);

		string get_response_http_body() {
			return _rsp_body;
		}

		void set_response_hander_type(const ResponseHandlerType handler_type)
		{
			_rsp_type = handler_type;
		}

		ResponseHandlerType get_response_handler_type()
		{
			return _rsp_type;
		}
		uint32_t get_req_type()
		{
			return _ctx->req()->type;
		}
		bool add_fwd_http_head(const string& name,const string& value);
		name_value_collection get_fwd_http_heads()
		{
			return _inside_head;
		}
		void clear_fwd_http_head()
		{
			_inside_head.clear();
		}
		void del_fwd_http_head(const string& name)
		{
			_inside_head.erase(name);
		}
		// Get the first value associated with the given key from the URI.
		std::string GetQuery(const char* query_key, size_t key_len);
		std::string GetQuery(const std::string& query_key);
	public:
		static std::string FindClientIPFromURI(const char* uri, size_t uri_len);

		// @brief Get the first value associated with the given key from the URI.
		//  If there are no values associated with the key, returns an empty string.
		// @param[IN] uri - The uri with parameters
		// @param[IN] uri_len - The uri length
		// @param[IN] key -
		// @param[IN] key_len -
		// @return std::string -
		static std::string FindQueryFromURI(const char* uri, size_t uri_len, const char* key, size_t key_len);
		static std::string FindQueryFromURI(const char* uri, const char* key);
		static std::string FindQueryFromURI(const std::string& uri, const std::string& key);
		
	private:
		evpp::http::ContextPtr _ctx;
		string _rsp_body;
		ResponseHandlerType _rsp_type;
		name_value_collection _inside_head;
	};
	typedef std::shared_ptr<context> LFCtxPtr;
	typedef std::function <void(const LFCtxPtr& ctx) > HTTPRequestCB;
}
#endif // !IF_CONTEXT

