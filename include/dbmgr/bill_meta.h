#ifndef BILL_META_H
#define BILL_META_H
#include"util/base_def.h"
#include<vector>
namespace luckyDaily
{
#define MAX_MASK_DEFAULT_32 0XFFFFFFFF     //32位最大掩码
#define MAX_MASK_DEFAULT_64 0XFFFFFFFFFFFFFFFF  //64位最大掩码
#define MAX_NUM_64 0XFFFFFFFFFFFFFFFF   //64位最大值
#define MAX_RETURN_RECODE_COUNT 10000   //数据库单次返回最大值
	enum BILL_PAYMENT_MASK
	{
		kPtypePayOut = 0X0,    //支出
		kPtypePayIn = 0X1,   //收入
		kPtypeZiFuBao = 0X2, //支付宝
		kPtypeWeiXin = 0X4, //微信
		kPtypeBankCard = 0X8, //银行卡
		kPtypeOther = 0X80000000 //其他
	};
	enum LF_BILL_TYPE
	{
		kBtypeGroupBillCast = 0X1, //组账单清算
		kBtypeFoodAndBeverage = 0X2, //餐饮
		kBtypeTransportation = 0X4, //交通
		kBtypeDailyUse = 0X8,  //生活日用
		kBtypeCommuication = 0X10,  //通讯
		kBtypeCostume = 0X20,   //服饰
		kBtypeHousingPayment = 0X40, //住房缴费
		kBtypeCulturalConsumption = 0X80, //文娱消费
		kBtypeOther = 0X80000000 //其他
	};
	struct owner_bill_meta
	{
		string _owner_bill_id; //个人帐单id
		string _owner_id;   //所属用户id
		uint32_t _owner_bill_type;		//个人帐单类型
		uint32_t _ptype;				//支付类型
		uint64_t _create_date;       //账单创建日期
		int64_t _sum;            //账单金额
		string _sign;        //账单描述
		owner_bill_meta() :_owner_bill_id(""), _owner_id(""),
			_owner_bill_type(LF_BILL_TYPE::kBtypeGroupBillCast),
			_ptype(BILL_PAYMENT_MASK::kPtypePayOut),
			_create_date(0), _sum(0), _sign("")
		{}
	};
	typedef std::vector<owner_bill_meta> OwnerBillList;
	struct group_bill_meta
	{
		string _group_bill_id;  //组账单id
		string _group_id;  //所属组id
		string _owner_id;  //支付者id
		uint32_t _group_bill_type;		//个人帐单类型
		uint32_t _ptype;				//支付类型
		uint64_t _create_date;       //账单创建日期
		uint64_t _sum;            //账单金额
		string _sign;        //账单描述
		uint32_t _status;   //结算状态，1：未结算；2：已结算。
	};
	typedef std::vector<group_bill_meta> GroupBillList;
}
#endif // !BILL_META_H

