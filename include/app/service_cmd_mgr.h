#ifndef SERVICE_COMMAND_MGR_H
#define SERVICE_COMMAND_MGR_H
#include"util/base_def.h"
#include"util/singleton.h"
#include<map>
namespace LF
{
#define SERVICE_ENUM_CMD_TYPE(XX)  \
	/*	����ö��ֵ				 ����op			 ����*/  \
	XX(SVR_CMD_LOGIN,		"login",		 "��½") \
	XX(SVR_CMD_LOGOUT,		"logout",		 "�˳�") \
	XX(SVR_CMD_REGISTER,	"register",		 "ע��") \
	XX(SVR_CMD_CONFIRM,		"confirm",		 "ע��ȷ��")

	enum svr_cmd_type
	{
		SVR_CMD_UNKNOW,
#define XX(cmd,op) cmd,
		SERVICE_ENUM_CMD_TYPE(XX)
#undef  XX
	};
	class service_cmd_map :public singleton<service_cmd_map>
	{
	public:
		service_cmd_map();
		uint32_t get_cmd(const string& op);
	private:
		typedef std::map<string, uint32_t> CmdMap;
		CmdMap cmds;
	};
}
#endif // !SERVICE_COMMAND_MGR_H

