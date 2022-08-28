/*!
 * \file WTSTypes.h
 * \project	WonderTrader
 *
 * \author Wesley
 * \date 2020/03/30
 * 
 * \brief WonderTrader�����������Ͷ����ļ�
 */
#pragma once
#include "WTSMarcos.h"
#include <stdint.h>

NS_WTP_BEGIN

/*
 *	��Լ����
 */
//��CTP���ƹ�����
typedef enum tagContractCategory
{
	CC_Stock,			//��Ʊ
	CC_Future,			//�ڻ�
	CC_FutOption,		//�ڻ���Ȩ����Ʒ��Ȩ���������
	CC_Combination,		//���
	CC_Spot,			//����
	CC_EFP,				//��ת��
	CC_SpotOption,		//�ֻ���Ȩ����ָ��Ȩ���������
	CC_ETFOption,		//������Ȩ��ETF��Ȩ���������

	CC_DC_Spot	= 20,	//�����ֻ�
	CC_DC_Swap,			//��������
	CC_DC_Future,		//�����ڻ�
	CC_DC_Margin,		//���Ҹܸ�
	CC_DC_Option,		//������Ȩ

	CC_UserIndex = 90	//�Զ���ָ��
} ContractCategory;

/*
 *	��Ȩ����
 */
typedef enum tagOptionType
{
	OT_None = 0,
	OT_Call = '1',		//������Ȩ
	OT_Put	= '2'		//������Ȩ
} OptionType;

/*
 *	ƽ������
 */
typedef enum tagCoverMode
{
	CM_OpenCover,		//��ƽ
	CM_CoverToday,		//��ƽ��ƽ��
	CM_UNFINISHED,		//ƽδ�˽��
	CM_None			//�����ֿ�ƽ
} CoverMode;

/*
 *	����ģʽ
 */
typedef enum tagTradingMode
{
	TM_Both,	//��ն�֧��
	TM_Long,	//ֻ������
	TM_LongT1,	//����T+1
	TM_None = 9	//���ܽ���
} TradingMode;

/*
*	�۸�ģʽ
*/
typedef enum tagPriceMode
{
	PM_Both,		//�м��޼۶�֧��
	PM_Limit,		//ֻ֧���޼�
	PM_Market,		//ֻ֧���м�
	PM_None	= 9		//��֧�ֽ���
} PriceMode;

/*
 *	K����������
 *	�����ߡ��͡��ա����������
 */
typedef enum tagKlineFieldType
{
	KFT_OPEN,
	KFT_HIGH,
	KFT_LOW,
	KFT_CLOSE,
	KFT_DATE,
	KFT_VOLUME,
	KFT_SVOLUME
} WTSKlineFieldType;

/*
 *	K������
 */
typedef enum tagKlinePeriod
{
	KP_Tick,
	KP_Minute1,
	KP_Minute5,
	KP_Minute60,
	KP_DAY,
	KP_Week,
	KP_Month
} WTSKlinePeriod;

static const char* PERIOD_NAME[] = 
{
	"tick",
	"min1",
	"min5",
	"day",
	"week",
	"month"
};

/*
 *	��־����
 */
typedef enum tagLogLevel
{
	LL_ALL	= 100,
	LL_DEBUG,
	LL_INFO,
	LL_WARN,
	LL_ERROR,
	LL_FATAL,
	LL_NONE
} WTSLogLevel;

/*
 *	�۸�����
 */
typedef enum tagPriceType
{
	WPT_ANYPRICE	= 0,			//�м۵�
	WPT_LIMITPRICE,					//�޼۵�
	WPT_BESTPRICE,					//���ż�
	WPT_LASTPRICE,					//���¼�

	//////////////////////////////////////////////////////////////////////////
	//���¶Ա�CTP�ļ۸�����
	WPT_CTP_LASTPLUSONETICKS = 20,	//���¼�+1ticks
	WPT_CTP_LASTPLUSTWOTICKS,		//���¼�+2ticks
	WPT_CTP_LASTPLUSTHREETICKS,		//���¼�+3ticks
	WPT_CTP_ASK1,					//��һ��
	WPT_CTP_ASK1PLUSONETICKS,		//��һ��+1ticks
	WPT_CTP_ASK1PLUSTWOTICKS,		//��һ��+2ticks
	WPT_CTP_ASK1PLUSTHREETICKS,		//��һ��+3ticks
	WPT_CTP_BID1,					//��һ��
	WPT_CTP_BID1PLUSONETICKS,		//��һ��+1ticks
	WPT_CTP_BID1PLUSTWOTICKS,		//��һ��+2ticks
	WPT_CTP_BID1PLUSTHREETICKS,		//��һ��+3ticks
	WPT_CTP_FIVELEVELPRICE,			//�嵵�ۣ��н����м�

	//////////////////////////////////////////////////////////////////////////
	//���¶Ա�DC�ļ۸�����
	WPT_DC_POSTONLY	= 100,			//ֻ��maker��
	WPT_DC_FOK,						//ȫ���ɽ�������ȡ��
	WPT_DC_IOC,						//�����ɽ���ȡ��ʣ��
	WPT_DC_OPTLIMITIOC				//�м�ί�������ɽ���ȡ��ʣ��
} WTSPriceType;

/*
 *	ʱ������
 */
typedef enum tagTimeCondition
{
	WTC_IOC		= '1',	//�������,������
	WTC_GFS,			//������Ч
	WTC_GFD,			//������Ч
} WTSTimeCondition;

/*
 *	������־
 */
typedef enum tagOrderFlag
{
	WOF_NOR = '0',		//��ͨ����
	WOF_FAK,			//fak
	WOF_FOK,			//fok
} WTSOrderFlag;

/*
 *	��ƽ����
 */
typedef enum tagOffsetType
{
	WOT_OPEN			= '0',	//����
	WOT_CLOSE,					//ƽ��,����Ϊƽ��
	WOT_FORCECLOSE,				//ǿƽ
	WOT_CLOSETODAY,				//ƽ��
	WOT_CLOSEYESTERDAY,			//ƽ��
} WTSOffsetType;

/*
 *	��շ���
 */
typedef enum tagDirectionType
{
	WDT_LONG			= '0',	//����
	WDT_SHORT,					//����
	WDT_NET						//��
} WTSDirectionType;

/*
 *	ҵ������
 */
typedef enum tagBusinessType
{
	BT_CASH		= '0',	//��ͨ����,
	BT_ETF		= '1',	//ETF����
	BT_EXECUTE	= '2',	//��Ȩ��Ȩ
	BT_QUOTE	= '3',	//��Ȩ����
	BT_FORQUOTE = '4',	//��Ȩѯ��
	BT_FREEZE	= '5',	//��Ȩ����
	BT_CREDIT	= '6',	//������ȯ
	BT_UNKNOWN			//δ֪ҵ������
} WTSBusinessType;

/*
 *	������������
 */
typedef enum tagActionFlag
{
	WAF_CANCEL			= '0',	//����
	WAF_MODIFY			= '3',	//�޸�
} WTSActionFlag;

/*
 *	����״̬
 */
typedef enum tagOrderState
{
	WOS_AllTraded				= '0',	//ȫ���ɽ�
	WOS_PartTraded_Queuing,				//���ֳɽ�,���ڶ�����
	WOS_PartTraded_NotQueuing,			//���ֳɽ�,δ�ڶ���
	WOS_NotTraded_Queuing,				//δ�ɽ�
	WOS_NotTraded_NotQueuing,			//δ�ɽ�,δ�ڶ���
	WOS_Canceled,						//�ѳ���
	WOS_Submitting				= 'a',	//�����ύ
	WOS_Nottouched,						//δ����
} WTSOrderState;

/*
 *	��������
 */
typedef enum tagOrderType
{
	WORT_Normal			= 0,		//��������
	WORT_Exception,					//�쳣����
	WORT_System,					//ϵͳ����
	WORT_Hedge						//�Գ嶩��
} WTSOrderType;

/*
 *	�ɽ�����
 */
typedef enum tagTradeType
{
	WTT_Common				= '0',	//��ͨ
	WTT_OptionExecution		= '1',	//��Ȩִ��
	WTT_OTC					= '2',	//OTC�ɽ�
	WTT_EFPDerived			= '3',	//��ת�������ɽ�
	WTT_CombinationDerived	= '4'	//��������ɽ�
} WTSTradeType;


/*
 *	�������
 */
typedef enum tagErrorCode
{
	WEC_NONE			=	0,		//û�д���
	WEC_ORDERINSERT,				//�µ�����
	WEC_ORDERCANCEL,				//��������
	WEC_EXECINSERT,					//��Ȩָ�����
	WEC_EXECCANCEL,					//��Ȩ��������
	WEC_UNKNOWN			=	9999	//δ֪����
} WTSErroCode;

/*
 *	�Ƚ��ֶ�
 */
typedef enum tagCompareField
{
	WCF_NEWPRICE			=	0,	//���¼�
	WCF_BIDPRICE,					//��һ��
	WCF_ASKPRICE,					//��һ��
	WCF_PRICEDIFF,					//�۲�,ֹӯֹ��ר��
	WCF_NONE				=	9	//���Ƚ�
} WTSCompareField;

/*
 *	�Ƚ�����
 */
typedef enum tagCompareType
{
	WCT_Equal			= 0,		//����
	WCT_Larger,						//����
	WCT_Smaller,					//С��
	WCT_LargerOrEqual,				//���ڵ���
	WCT_SmallerOrEqual				//С�ڵ���
}WTSCompareType;

/*
 *	����������¼�
 */
typedef enum tagParserEvent
{
	WPE_Connect			= 0,		//�����¼�
	WPE_Close,						//�ر��¼�
	WPE_Login,						//��¼
	WPE_Logout						//ע��
}WTSParserEvent;

/*
 *	����ģ���¼�
 */
typedef enum tagTraderEvent
{
	WTE_Connect			= 0,		//�����¼�
	WTE_Close,						//�ر��¼�
	WTE_Login,						//��¼
	WTE_Logout						//ע��
}WTSTraderEvent;

/*
 *	����״̬
 */
typedef enum tagTradeStatus
{
	TS_BeforeTrading	= '0',	//����ǰ
	TS_NotTrading		= '1',	//�ǽ���
	TS_Continous		= '2',	//��������
	TS_AuctionOrdering	= '3',	//���Ͼ����µ�
	TS_AuctionBalance	= '4',	//���Ͼ���ƽ��
	TS_AuctionMatch		= '5',	//���Ͼ��۴��
	TS_Closed			= '6'	//����
}WTSTradeStatus;

/*
 *	������������
 */
typedef uint32_t WTSBSDirectType;
#define BDT_Buy		'B'	//����	
#define BDT_Sell	'S'	//����
#define BDT_Unknown ' '	//δ֪
#define BDT_Borrow	'G'	//����
#define BDT_Lend	'F'	//���

/*
 *	�ɽ�����
 */
typedef uint32_t WTSTransType;
#define TT_Unknown	'U'	//δ֪����
#define TT_Match	'M'	//��ϳɽ�
#define TT_Cancel	'C'	//����

/*
 *	ί����ϸ����
 */
typedef uint32_t WTSOrdDetailType;
#define ODT_Unknown		0	//δ֪����
#define ODT_BestPrice	'U'	//��������
#define ODT_AnyPrice	'1'	//�м�
#define ODT_LimitPrice	'2'	//�޼�

NS_WTP_END