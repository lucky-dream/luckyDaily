#ifndef TOKEN_MGR_H
#define TOKEN_MGR_H
#include"util/singleton.h"
#include"util/lock.h"
#include<map>
namespace luckyDaily
{
	struct token_info
	{
		string uid;
		string username;
		string token;
		uint64_t period_validity;
		uint64_t create_time;
	};
	class token_manager:public singleton<token_manager>
	{
	public:
		string gen_token(const string& name,const string& password);
		bool add_token(const token_info& token_info);
		bool is_online_by_token(const string& token);
		bool is_online_by_name(const string& name);
		string get_uid_by_token(const string& token);
		void del_token_by_token(const string& token);
		void del_token_by_name(const string& token);
	private:
		typedef std::map<string, token_info> name_TokenMap;
		typedef std::map<string, token_info> token_TokenMap;
		name_TokenMap _name_token;
		token_TokenMap _token_token;
		lock_instance _mutex;
		token_info _token_info;
	};
}
#endif // !TOKEN_MGR_H

