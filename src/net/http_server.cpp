#include "net/http_server.h"
#include "net/http_proxy.h"
namespace luckyDaily
{
	http_server::http_server(const uint32_t & thread_num)
	{
		_svr.reset(new evpp::http::Server(thread_num));
	}
	http_server::~http_server()
	{
	}
	bool http_server::Init(int listen_port)
	{
		if (!_svr.get())
		{
			//todo:@str set log
			return false;
		}
		return _svr->Init(listen_port);
	}
	bool http_server::Init(const std::vector<int>& listen_ports)
	{
		if (!_svr.get())
		{
			//todo:@str set log
			return false;
		}
		return _svr->Init(listen_ports);
	}
	bool http_server::Init(const std::string & listen_ports)
	{
		if (!_svr.get())
		{
			//todo:@str set log
			return false;
		}
		return _svr->Init(listen_ports);
	}
	bool http_server::Start()
	{
		if (!_svr.get())
		{
			//todo:@str set log
			return false;
		}
		return _svr->Start();
	}
	void http_server::Stop()
	{
		if (!_svr.get())
		{
			//todo:@str set log
			return;
		}
		_svr->Stop();
	}
	void http_server::Pause()
	{
		if (!_svr.get())
		{
			//todo:@str set log
			return;
		}
		_svr->Pause();
	}
	void http_server::Continue()
	{
		if (!_svr.get())
		{
			//todo:@str set log
			return;
		}
		_svr->Continue();
	}
	void http_server::AfterFork()
	{
		if (!_svr.get())
		{
			//todo:@str set log
			return;
		}
		_svr->AfterFork();
	}

	bool http_server::IsRunning()
	{
		if (!_svr.get())
		{
			//todo:@str set log
			return false;
		}
		return _svr->IsRunning();
	}
	
	void http_server::RegisterHandler(const std::string & uri, HTTPRequestCB callback)
	{
		if (!_svr.get())
		{
			//todo:@str set log
			return;
		}
		auto f = [uri, callback](evpp::EventLoop* loop,
			const evpp::http::ContextPtr& evpp_ctx,
			const evpp::http::HTTPSendResponseCallback& cb) {
			LFCtxPtr ctx(new context(evpp_ctx));
			callback(ctx);
			string proxy_url = ctx->original_uri();
			uint32_t index = proxy_url.find(uri);
			if (proxy_url[index + uri.size() + 1] != '?'||ctx->get_response_handler_type() == ResponseHandlerType::kNormal)
			{
				ctx->AddResponseHeader("Content-Length", std::to_string(ctx->get_response_http_body().length()));
				cb(ctx->get_response_http_body());
				return;
			}
			else if(ctx->get_response_handler_type() == ResponseHandlerType::kProxy)
			{
				http_proxy::proxy_by_svr_name(std::move(uri),std::move(ctx),
					loop,std::move(cb));
			}
		};
		_svr->RegisterHandler(uri,f);
	}
#ifndef LF_TASKSVR_NAME
#define LF_TASKSVR_NAME "task"
#endif // !LF_TASKSVR_NAME

	void http_server::RegisterDefaultHandler(HTTPRequestCB callback)
	{
		if (!_svr.get())
		{
			//todo:@str set log
			return;
		}
		string uri(LF_TASKSVR_NAME);
		auto f = [uri,callback](evpp::EventLoop* loop,
			const evpp::http::ContextPtr& evpp_ctx,
			const evpp::http::HTTPSendResponseCallback& cb) {
			LFCtxPtr ctx(new context(evpp_ctx));
			callback(ctx);
			string proxy_url = ctx->original_uri();
			uint32_t index = proxy_url.find(uri);
			if (proxy_url[index + uri.size() + 1] != '?' || ctx->get_response_handler_type() == ResponseHandlerType::kNormal)
			{
				ctx->AddResponseHeader("Content-Length", std::to_string(ctx->get_response_http_body().length()));
				cb(ctx->get_response_http_body());
				return;
			}
			else if (ctx->get_response_handler_type() == ResponseHandlerType::kProxy)
			{
				http_proxy::proxy_by_svr_name(std::move(uri), std::move(ctx),
					loop, std::move(cb));
			}
		};
		_svr->RegisterDefaultHandler(f);
	}
}

