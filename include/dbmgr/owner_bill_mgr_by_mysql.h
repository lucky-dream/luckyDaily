#ifndef OWNER_BILL_MGR_H
#define OWNER_BILL_MGR_H
#include"util/base_def.h"
#include"dbmgr/db_mgr.h"
#include"dbmgr/bill_meta.h"
namespace LF 
{
	//个人账单查询可选项
	struct owner_bill_query_options
	{
		string _obid; //个人账单id，可选（默认不限id）；
		uint32_t _btype;	 //资源类型，掩码格式（具体值待定），可选，默认返回不限类型
		uint32_t _ptype;	//支付方式，掩码格式（具体值待定），可选，默认返回不限支付方式
		uint64_t _sdate;	//查询起始日期，可选，默认返回不限起始日期
		uint64_t _edate;	//查询结束日期，可选，默认返回不限结束日期
		string _keyword;	 // “sign”关键字查询，可选，默认返回不限“sign”关键字
		uint64_t _summin;		 //金额最小值，可选，默认返回不限最小金额
		uint64_t _summax;		 //金额最大值，可选，默认返回不限最大金额
		uint32_t _begin;       //返回起始位置，可选，默认为0
		uint32_t _count;		 //单次返回最大个数，可选，默认为10000
		owner_bill_query_options()
			:_obid(""), _btype(MAX_MASK_DEFAULT_32),_ptype(MAX_MASK_DEFAULT_32),
			_sdate(0),_edate(MAX_NUM_64), _keyword(""),
			_summin(0),_summax(MAX_NUM_64),_begin(0),_count(MAX_RETURN_RECODE_COUNT)
		{}
	};
	class owner_bill_mgr
	{
	public:
		static uint32_t add_recode(db_object* db,owner_bill_meta meta);
		static uint32_t del_recode(const string& uid,db_object* db,const string& bill_id);
		static bool has_recode(const string& uid,db_object* db, const string& bill_id);
		static uint32_t find_recode(const string& uid, db_object* db, const string& bill_id, owner_bill_meta& meta);
		static uint32_t find_recode(const string& uid, db_object* db, const owner_bill_query_options& filter_options,OwnerBillList& out_list);
	private:

	};
}
#endif // !OWNER_BILL_MGR_H

