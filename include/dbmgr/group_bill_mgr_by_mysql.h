#ifndef GROUP_BILL_MGR_H
#define GROUP_BILL_MGR_H
#include"util/base_def.h"
#include"dbmgr/db_mgr.h"
#include"dbmgr/bill_meta.h"
namespace LF
{
#define GBILL_STATUS_ALL_MASK 0X3  //（默认）组账单所有状态掩码
	//个人账单查询可选项
	struct group_bill_query_options
	{
		string _gbid; //组账单id，可选（默认不限id）；
		uint32_t _status;  //结算状态，1：未结算；2：已结算。可选，默认不限结算状态
		string _uid;   //账单所属者id。可选，默认不限账单所属者
		uint32_t _btype;	 //资源类型，掩码格式（具体值待定），可选，默认返回不限类型
		uint32_t _ptype;	//支付方式，掩码格式（具体值待定），可选，默认返回不限支付方式
		uint64_t _sdate;	//查询起始日期，可选，默认返回不限起始日期
		uint64_t _edate;	//查询结束日期，可选，默认返回不限结束日期
		string _keyword;	 // “sign”关键字查询，可选，默认返回不限“sign”关键字
		uint64_t _summin;		 //金额最小值，可选，默认返回不限最小金额
		uint64_t _summax;		 //金额最大值，可选，默认返回不限最大金额
		uint32_t _begin;       //返回起始位置，可选，默认为0
		uint32_t _count;		 //单次返回最大个数，可选，默认为10000
		group_bill_query_options()
			:_gbid(""), _btype(MAX_MASK_DEFAULT_32), _ptype(MAX_MASK_DEFAULT_32),
			_sdate(0), _edate(MAX_MASK_DEFAULT_64), _keyword(""),
			_summin(0), _summax(MAX_MASK_DEFAULT_64),
			_status(GBILL_STATUS_ALL_MASK), _uid(""), _begin(0), _count(MAX_RETURN_RECODE_COUNT)
		{}
	};
	class group_bill_mgr
	{
	public:
		static uint32_t add_recode(db_object* db, group_bill_meta meta);
		static uint32_t del_recode(const string& gid, db_object* db, const string& bill_id);
		static bool has_recode(const string& gid, db_object* db, const string& bill_id);
		static uint32_t find_recode(const string& gid, db_object* db, const string& bill_id, group_bill_meta& meta);
		static uint32_t find_recode(const string& gid, db_object* db, const group_bill_query_options& filter_options, GroupBillList& out_list);
		static uint32_t get_bill_status(const string& gid, db_object* db, const string& bill_id, uint32_t& bill_status);
		static uint32_t update_bill_status(const string& gid, db_object* db, const string& bill_id, const uint32_t& bill_status);
	private:

	};

}
#endif // !GROUP_BILL_MGR_H
