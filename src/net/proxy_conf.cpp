#include "net/proxy_conf.h"
namespace LF
{
	OBJ_SINGLETON_INIT(proxy_conf);
	proxy_conf g_proxy_conf;
	bool proxy_conf::add_host(const string & url, const string & host)
	{
		lock_instance::scoped_lock scoped_mutex(_mutex);
		auto it = _conf_map.find(url);
		if (it == _conf_map.end())
		{
			_conf_map.insert(std::make_pair(url,host));
			return true;
		}
		it->second.assign(host);
		return true;
	}

	bool proxy_conf::find_host(const string & url, string & host)
	{
		lock_instance::scoped_lock scoped_mutex(_mutex);
		auto it = _conf_map.find(url);
		if (it == _conf_map.end())
		{
			return false;
		}
		host.assign(it->second);
		return true;
	}

	void proxy_conf::del_host(const string & url)
	{
		lock_instance::scoped_lock scoped_mutex(_mutex);
		auto it = _conf_map.find(url);
		if (it == _conf_map.end())
		{
			return ;
		}
		_conf_map.erase(it);
		return ;
	}
}

