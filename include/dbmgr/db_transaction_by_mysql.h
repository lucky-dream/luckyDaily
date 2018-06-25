#ifndef DB_TRANSACTION_BY_MYSQL
#define DB_TRANSACTION_BY_MYSQL
#include"util/base_def.h"
#include"dbmgr/db_mgr.h"
namespace LF
{
	class db_transaction
	{
	public:
		static uint32_t start_transaction(db_object* db);
		
		static uint32_t rollback(db_object* db);
		
		static uint32_t commit(db_object* db);
	private:
	};

}
#endif // !DB_TRANSACTION_BY_MYSQL

