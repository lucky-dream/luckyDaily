#include"service/token_manager.h"
#include "xxhash/xxhash.h"
#include "util/code_util.h"
#include <ctime>
namespace luckyDaily
{
	OBJ_SINGLETON_INIT(token_manager);
	token_manager g_token_manager;
	string token_manager::gen_token(const string & name, const string & password)
	{
		uint64_t now = time(NULL);
		string info = name + password + std::to_string(now);
		uint64_t token_num = XXH64(info.c_str(), info.length(),2018);
		string token;
		code_util::uint64_to_hex(token_num, token);
		return token;
	}
	bool token_manager::add_token(const token_info& token_info)
	{
		lock_instance::scoped_lock scoped(_mutex);
		auto it = _token_token.find(token_info.token);
		if (it== _token_token.end())
		{
			_token_token.insert(std::make_pair(token_info.token,token_info));
			return true;
		}
		return false;
	}
	bool token_manager::is_online_by_token(const string & token)
	{
		lock_instance::scoped_lock scoped(_mutex);
		auto it = _token_token.find(token);
		if (it == _token_token.end())
		{
			return true;
		}
		return false;
	}
	bool token_manager::is_online_by_name(const string & name)
	{
		lock_instance::scoped_lock scoped(_mutex);
		auto it = _name_token.find(name);
		if (it == _name_token.end())
		{
			return true;
		}
		return false;
	}
	string token_manager::get_uid_by_token(const string & token)
	{
		lock_instance::scoped_lock scoped(_mutex);
		auto it = _token_token.find(token);
		if (it == _token_token.end())
		{
			return string();
		}
		return it->second.uid;
	}
	void token_manager::del_token_by_token(const string & token)
	{
		lock_instance::scoped_lock scoped(_mutex);
		auto it = _token_token.find(token);
		if (it == _token_token.end())
		{
			return;
		}
		_token_token.erase(it);
	}
	void token_manager::del_token_by_name(const string & name)
	{
		lock_instance::scoped_lock scoped(_mutex);
		auto it = _name_token.find(name);
		if (it == _name_token.end())
		{
			return;
		}
		_name_token.erase(it);
	}
}