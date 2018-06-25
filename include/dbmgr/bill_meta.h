#ifndef BILL_META_H
#define BILL_META_H
#include"util/base_def.h"
#include<vector>
namespace LF
{
#define MAX_MASK_DEFAULT_32 0XFFFFFFFF     //32λ�������
#define MAX_MASK_DEFAULT_64 0XFFFFFFFFFFFFFFFF  //64λ�������
#define MAX_NUM_64 0XFFFFFFFFFFFFFFFF   //64λ���ֵ
#define MAX_RETURN_RECODE_COUNT 10000   //���ݿⵥ�η������ֵ
	enum BILL_PAYMENT_MASK
	{
		kPtypePayOut = 0X0,    //֧��
		kPtypePayIn = 0X1,   //����
		kPtypeZiFuBao = 0X2, //֧����
		kPtypeWeiXin = 0X4, //΢��
		kPtypeBankCard = 0X8, //���п�
		kPtypeOther = 0X80000000 //����
	};
	enum LF_BILL_TYPE
	{
		kBtypeGroupBillCast = 0X1, //���˵�����
		kBtypeFoodAndBeverage = 0X2, //����
		kBtypeTransportation = 0X4, //��ͨ
		kBtypeDailyUse = 0X8,  //��������
		kBtypeCommuication = 0X10,  //ͨѶ
		kBtypeCostume = 0X20,   //����
		kBtypeHousingPayment = 0X40, //ס���ɷ�
		kBtypeCulturalConsumption = 0X80, //��������
		kBtypeOther = 0X80000000 //����
	};
	struct owner_bill_meta
	{
		string _owner_bill_id; //�����ʵ�id
		string _owner_id;   //�����û�id
		uint32_t _owner_bill_type;		//�����ʵ�����
		uint32_t _ptype;				//֧������
		uint64_t _create_date;       //�˵���������
		int64_t _sum;            //�˵����
		string _sign;        //�˵�����
		owner_bill_meta() :_owner_bill_id(""), _owner_id(""),
			_owner_bill_type(LF_BILL_TYPE::kBtypeGroupBillCast),
			_ptype(BILL_PAYMENT_MASK::kPtypePayOut),
			_create_date(0), _sum(0), _sign("")
		{}
	};
	typedef std::vector<owner_bill_meta> OwnerBillList;
	struct group_bill_meta
	{
		string _group_bill_id;  //���˵�id
		string _group_id;  //������id
		string _owner_id;  //֧����id
		uint32_t _group_bill_type;		//�����ʵ�����
		uint32_t _ptype;				//֧������
		uint64_t _create_date;       //�˵���������
		uint64_t _sum;            //�˵����
		string _sign;        //�˵�����
		uint32_t _status;   //����״̬��1��δ���㣻2���ѽ��㡣
	};
	typedef std::vector<group_bill_meta> GroupBillList;
}
#endif // !BILL_META_H

