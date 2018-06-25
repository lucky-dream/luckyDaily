#ifndef ERROR_CODE_H
#define ERROR_CODE_H
#include"util/base_def.h"
#include<string>
#define DECLARE_NON_COPYABLE(className) \
	className(const className&); \
	className& operator= (const className&)
namespace luckyDaily {
#define _CHECK_JSON(Doc,Key,Type) (((Doc).HasMember(Key)?true:false)&&(Doc)[Key].Is##Type())
#if defined(_DEBUG) 
#define	_SET_ERR_CODE(out_err,out_code,us_err_code)   \
       out_err.append(__FILE__).append(" ").append(std::to_string(__LINE__)).append(":"); \
	   out_code = us_err_code; \
       out_err.append(error_code_mgr::get_error_msg(out_code));
#else
#define _SET_ERR_CODE(out_err,out_code,us_err_code)   \
	   out_code = us_err_code; \
       out_err.append(error_code_mgr::get_error_msg(out_code));
#endif
	#define USER_MSG_CODE_ERROR_MAP(XX)                                         \
			XX(0X100,		USER_INVALID_JSON,		"Json语法错误")			\
			XX(0X101,		USER_JSON_KEY_ERROR,		"Json键值错误")         \
			XX(0X102,		USER_JSON_VALUE_ERROR,	"无效的Json参数")       \
			XX(0X103,		USER_NO_RECODE,			"记录不存在")			\
			XX(0X104,		USER_RECODE_EXISTED,		"记录已存在")

#define SYSTEM_MSG_CODE_ERROR_MAP(XX)                                                                                        \
			XX(0X200,		SYSTEM_DB_CONNECT_ERROR,		"获取数据库连接失败")			                                     \
			XX(0X201,       SYSTEM_DB_NOT_FOUND,			"不存在：")                                  \
			XX(0X202,		SYSTEM_DB_ERROR,				"数据库异常")                
	enum LF_ERROR_CODE
	{
	#define XX(num, name, string) name = num,
		USER_MSG_CODE_ERROR_MAP(XX)
		USER_ERROR_END,
		SYSTEM_MSG_CODE_ERROR_MAP(XX)
		SYSTEM_ERROR_END
	#undef XX
	};
	class error_code_mgr {
	public:
		static const char* get_error_msg(uint32_t err_code);
		static bool get_error_msg(uint32_t err_code,string &err_msg);
	private:
		DECLARE_NON_COPYABLE(error_code_mgr);
	};
}
#endif // !ERROR_CODE_H

