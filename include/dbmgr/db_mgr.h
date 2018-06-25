#ifndef DB_MGR_H
#define DB_MGR_H
#include"util/singleton.h"
#include"util/lock.h"
#include"mysql.h"
#include<memory>
#include<queue>
namespace luckyDaily
{
	struct db_info
	{
		string _host;
		uint32_t _port;
		string _user_name;
		string _password;
		string _dbname;
		//const char * unix_socket;
		//unsigned long clientflag;        //一般情况下，unix_socket设置为空， 
		                               //clientflag 设为CLIENT_MULTI_STATEMENTS 用以支持同时查询多条语句，语句之间通过分号分割
	};

	class db_object
	{
	public:
		db_object(const db_info& db_info);
		db_object(MYSQL* mysql);
		bool close();
		MYSQL* mysql() {
			return _mysql;
		}
		
	private:
		bool connect(const db_info& db_info);
		MYSQL* _mysql;
	};

	class db_mgr :public singleton<db_mgr>
	{
	public:
		bool enqueue(db_object* db);
		db_object* dequeue();
		void clear();
	private:
		typedef std::queue<db_object*> DbConnQue;
		DbConnQue _db_conns;
		lock_instance _mutex;
	};

	class db_module
	{
	public:
		static bool init(const db_info& db_info);
		static db_object* get_conn();
		static bool give_back(db_object* db);
		static bool destroy(); //模块销毁
	};

}
#endif // !DB_MGR_H

