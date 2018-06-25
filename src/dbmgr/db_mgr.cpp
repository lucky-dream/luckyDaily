#include"dbmgr/db_mgr.h"

#define  bulidCount    10    //�������ݿ���������
namespace LF
{
	db_object::db_object(const db_info & db_info)
	{
		connect(db_info);
	}
	db_object::db_object(MYSQL * mysql)
	{
		if (mysql)
		{
			_mysql = mysql;
		}
		else
		{
			_mysql = NULL;
		}
	}
	bool db_object::close()
	{
		mysql_close(_mysql);
		_mysql = NULL;
		//if(_mysql)
		//    return false;
		return false;
	}
	bool db_object::connect(const db_info & db_info)
	{
		MYSQL* mysql = NULL;
		mysql_init(mysql);
		mysql = mysql_real_connect(mysql, db_info._host.c_str(), db_info._user_name.c_str(), db_info._password.c_str(),
			db_info._dbname.c_str(), db_info._port, NULL, CLIENT_MULTI_STATEMENTS);
		if (mysql != NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	OBJ_SINGLETON_INIT(db_mgr);
	db_mgr g_db_object;
	bool db_mgr::enqueue(db_object* db)
	{
		lock_instance::scoped_lock scoped_mutex(_mutex);
		if (db != NULL)
		{
			_db_conns.push(db);
			return true;
		}
		else
		{
			return false;
		}
	}

	db_object * db_mgr::dequeue()
	{
		lock_instance::scoped_lock scoped_mutex(_mutex);
		db_object* m_db = _db_conns.front();
		if (m_db&&m_db->mysql())
		{
			_db_conns.pop(); // ��ȡ��Ԫ�غ󣬳���
			return m_db;
		}
		else
		{
			//����ͷ����Ԫ��
			return NULL;
		}
	}

	void db_mgr::clear()
	{
		//�ڵ��øú���ʱ����ָ��Żض�����
		
	}

	bool db_module::init(const db_info & db_info)
	{
		if (db_info._host.empty() || db_info._dbname.empty()
			|| db_info._user_name.empty())
		{
			return false;
		}
		for (int i = 0; i < bulidCount; ++i)
		{
			db_object*  m_pdb_object = new db_object(db_info);
			db_mgr::singleton_obj().enqueue(m_pdb_object);
		}
		
		return false;
	}
	db_object * db_module::get_conn()
	{
		if (db_mgr::singleton_obj().dequeue())
		{
			return db_mgr::singleton_obj().dequeue();
		}
		else {
			//�����ڶ���û��Ԫ��ʱ���ȴ�����
			return NULL;
		}
		   
	}
	bool db_module::give_back(db_object * db)
	{
		//����
		if(!db_mgr::singleton_obj().enqueue(db))
		    return false;
		return true;
	}
	bool db_module::destroy()
	{
		db_mgr::singleton_obj().clear();
		return false;
	}
	
	//MYSQL* db_object::openDB()  //�ⲿ����
	//{
	//	//�����������������ݿ�ʱ������һ��mysqlָ��
	//	//�������е�����
	//	if (_db_conns.empty())//������Ϊ��ʱ
	//	{
	//		return NULL;
	//	}
	//	else
	//	{
	//		//����������ָ��ʱ
	//		//MYSQL* mysql = _db_conns.front;
	//		//return mysql;
	//	}
	//}
}