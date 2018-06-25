#include"app/service_cmd_mgr.h"
namespace luckyDaily
{
	OBJ_SINGLETON_INIT(service_cmd_map);
	service_cmd_map g_service_cmd_map;
	service_cmd_map::service_cmd_map()
	{
#define XX(cmd,op) cmds.insert(std::make_pair(op,cmd));
		SERVICE_ENUM_CMD_TYPE(XX)
#undef  XX
	}
	uint32_t service_cmd_map::get_cmd(const string & op)
	{
		auto it = cmds.find(op);
		if (it==cmds.end())
		{
			return svr_cmd_type::SVR_CMD_UNKNOW;
		}
		return it->second;
	}
}
