#ifndef USER_MGR_BY_MYSQL_H
#define USER_MGR_BY_MYSQL_H
#include "util/base_def.h"
#include"dbmgr/db_mgr.h"
namespace LF
{
	class user_mgr
	{
	public:
		static uint32_t find_name(const string& uid, db_object* db, string& uname);
		static uint32_t find_id(const string& uname, db_object* db, string& uid);
	};
	
	class group_mgr
	{
	public:
		typedef std::vector<string> UserList;
		static uint32_t find_name(const string& gid, db_object* db, string& gname);
		static uint32_t find_id(const string& gname, db_object* db, string& gid);
		static uint32_t find_users(const string& gid, db_object* db, UserList& list);
	};
}
#endif // !USER_MGR_BY_MYSQL_H

