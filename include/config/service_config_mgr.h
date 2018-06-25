#ifndef SERVICE_CONFIG_MGR_H
#define SERVICE_CONFIG_MGR_H
#include"util/singleton.h"
#include<map>
namespace luckyDaily
{
	struct service_config_info 
	{
		string ip;
		string port;
	};
	class service_config_mgr :public singleton<service_config_mgr>
	{
	public:
		bool read_config_file(const string& path);
		string get_value(const string& key);
	private:
		string _config;
	};
}
#endif // !SERVICE_CONFIG_MGR_H

