#include"util/base_def.h"
#include"net/http_server.h"
#include"util/os_type.h"
#include"config/service_config_mgr.h"
#include"app/service_http_dispatch_cb.h"



#define FMIS_THREAD_NUM 4

using namespace LF;
int main(int argc, char* argv[])
{
	string path("./lucky_daily.conf");
	//todo:@str get path
	if (!service_config_mgr::singleton_obj().read_config_file(path))
	{
		return 1;
	}
	string svr_port = service_config_mgr::singleton_obj().get_value("http_svr_prot");
	if (svr_port.empty())
	{
		svr_port.assign("8000");
	}
	http_server http_svr(FMIS_THREAD_NUM);
	http_svr.RegisterDefaultHandler(&service_http_dispatch_cb::default_http_handler_callback);
	http_svr.RegisterHandler("luckydaily", &service_http_dispatch_cb::service_http_handler_callback);
	http_svr.Init(svr_port);
	http_svr.Start();
	while (http_svr.IsRunning()) {
		millisleep(1);
	}
	return 0;
}