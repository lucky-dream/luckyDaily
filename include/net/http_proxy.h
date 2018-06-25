#ifndef HTTP_PROXY_H
#define HTTP_PROXY_H
#include"util/base_def.h"
#include"net/context.h"
namespace LF
{
	class http_proxy
	{
	public:
		static void proxy_by_svr_name(const string && uri, const LFCtxPtr && ctx,
			evpp::EventLoop * loop, const evpp::http::HTTPSendResponseCallback && cb);

	};
}
#endif // !HTTP_PROXY_H

