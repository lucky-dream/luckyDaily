#ifndef GROUP_BILL_MGR_H
#define GROUP_BILL_MGR_H
#include"util/base_def.h"
#include"dbmgr/db_mgr.h"
#include"dbmgr/bill_meta.h"
namespace luckyDaily
{
#define GBILL_STATUS_ALL_MASK 0X3  //��Ĭ�ϣ����˵�����״̬����
	//�����˵���ѯ��ѡ��
	struct group_bill_query_options
	{
		string _gbid; //���˵�id����ѡ��Ĭ�ϲ���id����
		uint32_t _status;  //����״̬��1��δ���㣻2���ѽ��㡣��ѡ��Ĭ�ϲ��޽���״̬
		string _uid;   //�˵�������id����ѡ��Ĭ�ϲ����˵�������
		uint32_t _btype;	 //��Դ���ͣ������ʽ������ֵ����������ѡ��Ĭ�Ϸ��ز�������
		uint32_t _ptype;	//֧����ʽ�������ʽ������ֵ����������ѡ��Ĭ�Ϸ��ز���֧����ʽ
		uint64_t _sdate;	//��ѯ��ʼ���ڣ���ѡ��Ĭ�Ϸ��ز�����ʼ����
		uint64_t _edate;	//��ѯ�������ڣ���ѡ��Ĭ�Ϸ��ز��޽�������
		string _keyword;	 // ��sign���ؼ��ֲ�ѯ����ѡ��Ĭ�Ϸ��ز��ޡ�sign���ؼ���
		uint64_t _summin;		 //�����Сֵ����ѡ��Ĭ�Ϸ��ز�����С���
		uint64_t _summax;		 //������ֵ����ѡ��Ĭ�Ϸ��ز��������
		uint32_t _begin;       //������ʼλ�ã���ѡ��Ĭ��Ϊ0
		uint32_t _count;		 //���η�������������ѡ��Ĭ��Ϊ10000
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
