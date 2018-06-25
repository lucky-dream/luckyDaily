#ifndef PROXY_CONF_H
#define PROXY_CONF_H
#include"util/base_def.h"
#include"util/singleton.h"
#include"util/lock.h"
#include <map>
namespace luckyDaily
{
#define kProxy_DOMAIN "proxy"
	typedef std::map<string, string> ConfMap;
	class proxy_conf:public singleton<proxy_conf>
	{
	public:
		bool add_host(const string& url,const string& host);
		bool find_host(const string& url, string& host);
		void del_host(const string& url);
		void set_is_proxy_fwd(bool is_proxy_fwd)
		{
			_is_proxy_fwd = is_proxy_fwd;
		}
		bool is_proxy_fwd()
		{
			return _is_proxy_fwd;
		}
	private:
		ConfMap _conf_map;
		bool _is_proxy_fwd;
		lock_instance _mutex;
	};
}
#endif // !PROXY_CONF_H

