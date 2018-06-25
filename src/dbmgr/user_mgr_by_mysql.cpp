#include"dbmgr/user_mgr_by_mysql.h"
#include"util/error_code_mgr.h"
namespace LF
{
	uint32_t user_mgr::find_name(const string & uid, db_object * db, string & uname)
	{
		if (db == nullptr)
		{
			return LF_ERROR_CODE::SYSTEM_DB_CONNECT_ERROR;
		}
		MYSQL* m_mysql = db->mysql();
		if (m_mysql == nullptr)
		{
			return LF_ERROR_CODE::SYSTEM_DB_ERROR;
		}
		int32_t ret;
		char sql[2048] = "select name from user where id='";
		int len = strlen(sql);
		char* pbuf = (char*)sql + len;
		//------- id -------//
		ret = mysql_real_escape_string(m_mysql, pbuf,
			(const char*)(uid.data()), uid.size());
		pbuf[ret] = '\'';
		// ִ��sql���
		ret = mysql_real_query(m_mysql, sql, (pbuf + ret + 1) - sql);
		if (ret != 0) {
			//US_WARN("mysql_real_query failed:\nError %u (%s)\n",
			//	mysql_errno(mysql), mysql_error(mysql));
			//todo:@str set log
			printf("err:%s\n", mysql_error(m_mysql));
			return LF_ERROR_CODE::SYSTEM_DB_ERROR;
		}
		MYSQL_RES* res;
		MYSQL_ROW row;
		unsigned long *row_len;
		// ��ȡ���ؽ��
		res = mysql_store_result(m_mysql);
		if (res == NULL) {
			return LF_ERROR_CODE::SYSTEM_DB_NOT_FOUND;
		}
		if ((row = mysql_fetch_row(res)) != NULL &&
			(row_len = mysql_fetch_lengths(res)) != NULL)
		{
			uname.assign(row[0], row_len[0]);
			mysql_free_result(res);
			return 0;
		}
		mysql_free_result(res);
		return LF_ERROR_CODE::SYSTEM_DB_NOT_FOUND;
	}
	uint32_t user_mgr::find_id(const string & uname, db_object * db, string & uid)
	{
		if (db == nullptr)
		{
			return LF_ERROR_CODE::SYSTEM_DB_CONNECT_ERROR;
		}
		MYSQL* m_mysql = db->mysql();
		if (m_mysql == nullptr)
		{
			return LF_ERROR_CODE::SYSTEM_DB_ERROR;
		}
		int32_t ret;
		char sql[2048] = "select id from user where name='";
		int len = strlen(sql);
		char* pbuf = (char*)sql + len;
		//------- name -------//
		ret = mysql_real_escape_string(m_mysql, pbuf,
			(const char*)(uname.data()), uname.size());
		pbuf[ret] = '\'';
		// ִ��sql���
		ret = mysql_real_query(m_mysql, sql, (pbuf + ret + 1) - sql);
		if (ret != 0) {
			//US_WARN("mysql_real_query failed:\nError %u (%s)\n",
			//	mysql_errno(mysql), mysql_error(mysql));
			//todo:@str set log
			printf("err:%s\n", mysql_error(m_mysql));
			return LF_ERROR_CODE::SYSTEM_DB_ERROR;
		}
		MYSQL_RES* res;
		MYSQL_ROW row;
		unsigned long *row_len;
		// ��ȡ���ؽ��
		res = mysql_store_result(m_mysql);
		if (res == NULL) {
			return LF_ERROR_CODE::SYSTEM_DB_NOT_FOUND;
		}
		if ((row = mysql_fetch_row(res)) != NULL &&
			(row_len = mysql_fetch_lengths(res)) != NULL)
		{
			uid.assign(row[0], row_len[0]);
			mysql_free_result(res);
			return 0;
		}
		mysql_free_result(res);
		return LF_ERROR_CODE::SYSTEM_DB_NOT_FOUND;
	}
	uint32_t group_mgr::find_name(const string & gid, db_object * db, string & gname)
	{
		if (db == nullptr)
		{
			return LF_ERROR_CODE::SYSTEM_DB_CONNECT_ERROR;
		}
		MYSQL* m_mysql = db->mysql();
		if (m_mysql == nullptr)
		{
			return LF_ERROR_CODE::SYSTEM_DB_ERROR;
		}
		int32_t ret;
		char sql[2048] = "select groupname from groups where groupid='";
		int len = strlen(sql);
		char* pbuf = (char*)sql + len;
		//------- id -------//
		ret = mysql_real_escape_string(m_mysql, pbuf,
			(const char*)(gid.data()), gid.size());
		pbuf[ret] = '\'';
		// ִ��sql���
		ret = mysql_real_query(m_mysql, sql, (pbuf + ret + 1) - sql);
		if (ret != 0) {
			//US_WARN("mysql_real_query failed:\nError %u (%s)\n",
			//	mysql_errno(mysql), mysql_error(mysql));
			//todo:@str set log
			printf("err:%s\n", mysql_error(m_mysql));
			return LF_ERROR_CODE::SYSTEM_DB_ERROR;
		}
		MYSQL_RES* res;
		MYSQL_ROW row;
		unsigned long *row_len;
		// ��ȡ���ؽ��
		res = mysql_store_result(m_mysql);
		if (res == NULL) {
			return LF_ERROR_CODE::SYSTEM_DB_NOT_FOUND;
		}
		if ((row = mysql_fetch_row(res)) != NULL &&
			(row_len = mysql_fetch_lengths(res)) != NULL)
		{
			gname.assign(row[0], row_len[0]);
			mysql_free_result(res);
			return 0;
		}
		mysql_free_result(res);
		return LF_ERROR_CODE::SYSTEM_DB_NOT_FOUND;
	}
	uint32_t group_mgr::find_id(const string & gname, db_object * db, string & gid)
	{
		if (db == nullptr)
		{
			return LF_ERROR_CODE::SYSTEM_DB_CONNECT_ERROR;
		}
		MYSQL* m_mysql = db->mysql();
		if (m_mysql == nullptr)
		{
			return LF_ERROR_CODE::SYSTEM_DB_ERROR;
		}
		int32_t ret;
		char sql[2048] = "select groupid from groups where groupname='";
		int len = strlen(sql);
		char* pbuf = (char*)sql + len;
		//------- name -------//
		ret = mysql_real_escape_string(m_mysql, pbuf,
			(const char*)(gname.data()), gname.size());
		pbuf[ret] = '\'';
		// ִ��sql���
		ret = mysql_real_query(m_mysql, sql, (pbuf + ret + 1) - sql);
		if (ret != 0) {
			//US_WARN("mysql_real_query failed:\nError %u (%s)\n",
			//	mysql_errno(mysql), mysql_error(mysql));
			//todo:@str set log
			printf("err:%s\n", mysql_error(m_mysql));
			return LF_ERROR_CODE::SYSTEM_DB_ERROR;
		}
		MYSQL_RES* res;
		MYSQL_ROW row;
		unsigned long *row_len;
		// ��ȡ���ؽ��
		res = mysql_store_result(m_mysql);
		if (res == NULL) {
			return LF_ERROR_CODE::SYSTEM_DB_NOT_FOUND;
		}
		if ((row = mysql_fetch_row(res)) != NULL &&
			(row_len = mysql_fetch_lengths(res)) != NULL)
		{
			gid.assign(row[0], row_len[0]);
			mysql_free_result(res);
			return 0;
		}
		mysql_free_result(res);
		return LF_ERROR_CODE::SYSTEM_DB_NOT_FOUND;
	}

	uint32_t group_mgr::find_users(const string & gid, db_object * db, UserList & list)
	{
		if (db == nullptr)
		{
			return LF_ERROR_CODE::SYSTEM_DB_CONNECT_ERROR;
		}
		MYSQL* m_mysql = db->mysql();
		if (m_mysql == nullptr)
		{
			return LF_ERROR_CODE::SYSTEM_DB_ERROR;
		}
		int32_t ret;
		//ret = create_owner_bill_table(db, table_name);
		//if (ret != 0)
		//{
		//	return ret;
		//}
		char sql[2048] = "select userid from groupuser where groupid='";
		int len = strlen(sql);
		char* pbuf = (char*)sql + len;
		//------- id -------//
		ret = mysql_real_escape_string(m_mysql, pbuf,
			(const char*)(gid.data()), gid.size());
		pbuf[ret] = '\'';
		len = strlen(sql);
		// ִ��sql���
		ret = mysql_real_query(m_mysql, sql, len);
		if (ret != 0) {
			//US_WARN("mysql_real_query failed:\nError %u (%s)\n",
			//	mysql_errno(mysql), mysql_error(mysql));
			//todo:@str set log
			printf("err:%s\n", mysql_error(m_mysql));
			return LF_ERROR_CODE::SYSTEM_DB_ERROR;
		}
		MYSQL_RES* res;
		MYSQL_ROW row;
		unsigned long *row_len;
		// ��ȡ���ؽ��
		res = mysql_store_result(m_mysql);
		if (res == NULL) {
			return LF_ERROR_CODE::SYSTEM_DB_NOT_FOUND;
		}
		while ((row = mysql_fetch_row(res)) != NULL &&
			(row_len = mysql_fetch_lengths(res)) != NULL)
		{
			string uid(row[0], row_len[0]);
			if (uid.empty())
			{
				break;
			}
			list.push_back(uid);
		}
		mysql_free_result(res);
		return 0;
	}
}