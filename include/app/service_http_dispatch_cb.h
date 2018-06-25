#ifndef SERVICE_HTTP_DISPATCH_CB_H
#define SERVICE_HTTP_DISPATCH_CB_H
#include"net/context.h"
#define LF_TASKSVR_NAME "task"
namespace luckyDaily
{
	class service_http_dispatch_cb
	{
	public:
		static void service_http_handler_callback(const LFCtxPtr& ctx);
		static void default_http_handler_callback(const LFCtxPtr& ctx);
	};

	class service_http_dispatch
	{
	public:
		static void http_service_handler_dispath(const LFCtxPtr & ctx, const name_value_collection& params,
			const string& op);
	private:

	};
}
#endif // !SERVICE_HTTP_DISPATCH_CB_H

