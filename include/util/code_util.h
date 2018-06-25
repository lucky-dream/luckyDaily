#ifndef CODE_UTIL_H
#define CODE_UTIL_H
#include"util/base_def.h"
namespace LF
{
	class code_util
	{
	public:
		static void base64_encode(const string& data, string& out_data);
		static void base64_decode(const string& data, string& out_data);
		static void uint64_to_hex(uint64_t val, string& out_data,bool low_case = false);
	};

} //end unispace
#endif //CODE_UTIL_H