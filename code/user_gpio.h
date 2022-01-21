#ifndef _USER_GPIO_H_
#define _USER_GPIO_H_

#include "cms32f033x.h"
#include "define.h"


//######################################################################//
//######################### ���ö��� ####################################//
extern void GPIO_Config(void);
//sbit SWDIO 			= P3^5;			//������¼���ڣ�TXD��
//sbit SWCLK 			= P2^1;
//sbit MCU_TXD 		= P2^5;			//��λ��ͨ�Ŵ���
//sbit MCU_RXD 		= P2^6;
//######################################################################//
//######################################################################//
//######################################################################//

//######################### DU4L_WS_W03 ####################################//
#if defined LAIYK_001
#define LAIYK_001					1
#ifdef LAIYK_001
#define VERSION_F			"CF033-LAIYK_35.1.0"			//��¼�汾��
#define	VERSION_DATA		"20211220"				//�汾����ʱ��
#define PRODUCT_KEY 		"trnkjvvd8b1qknnl"    	//����ƽ̨������Ʒ�����ɵ�16λ�ַ���ƷΨһ��ʶ
#define MCU_VER 			"35.1.0"         		//�û��������汾,����MCU�̼�����,MCU�����汾���޸�

#endif

#define RTC_TIME			1		//ʱ�Ӽ�ʱ
#define MOTOR_REVERSE		1		//�����ת����
#define NO_RECORD_FUNC		1		//û��¼������
#define BATTERY_DETECT		1		//��ص�������⹦��

#define LINK_LED_FUNC		1		//����ƹ���
#define KEY_BUZZER_FUNC		1		//�����������칦��
#define ONE_KEY_RECORD      1		//������¼������ 
#define SFN_BEEP			1		//��Դ������
#define DOOR_CONTROL		1		//�Ųֿ���

#define IR_FEED_TUBE		1		//��ʳ�����
#define IR_FOOD_TUBE		1		//���������������
#define MOTOR_DET_ADDR		1		//������Ƶ�λֹͣλ�ã�ѡ�о����ɿ�ֹͣ��

#define ADC_CHANNEL			ADC1_CH_0		//ADCͨ��ѡ��

#define DC_DET				GPIO0->DI_f.P1			//�����
#define BAT_DET				GPIO0->DI_f.P0			//��ص���ADC����

#define WIFI_PWR			GPIO4->DO_f.P0			//wifi��Դ����
#define BUZZER_EN			GPIO0->DO_f.P4			//���������ƽ�
#define SWITCH_DRIVER		GPIO0->DO_f.P5			//��ŷ�����
#define MOTOR_DRIVER		GPIO0->DO_f.P6			//��ձÿ���
#define IR_LED_CTRL			GPIO0->DO_f.P7			//����Թܼ�⣨���жԹܣ�

#define MOTOR_FEED_G		GPIO1->DO_f.P0			//ιʳ�����ת
#define MOTOR_FEED_B		GPIO1->DO_f.P2			//ιʳ�����ת
#define MOTOR_DOOR_G		GPIO1->DO_f.P4			//�Ųֵ����ת
#define MOTOR_DOOR_B		GPIO1->DO_f.P3			//�Ųֵ����ת

#define LED_DRIVER			GPIO3->DO_f.P6			//��Χ��
#define BAT_LED				GPIO1->DO_f.P5			//���ָʾ��
#define LINK_LED			GPIO4->DO_f.P3			//����ָʾ��
#define PUMP_LED			GPIO3->DO_f.P0			//���ù���ָʾ��
#define FEED_LED			GPIO4->DO_f.P4			//����ָʾ��
#define MOTOR_LED			GPIO3->DO_f.P1			//����ָʾ��
#define FOOD_LED			GPIO3->DO_f.P2			//����ָʾ��

#define MOTOR_DET			GPIO2->DI_f.P1			//ιʳ��λ
#define FEED_DET			GPIO3->DI_f.P4			//�����Թܵ�λ
#define FOOD_DET			GPIO3->DI_f.P5			//�����Թܵ�λ
#define DOOR_DET_P			GPIO2->DI_f.P3			//�Ųֵ�λP
#define DOOR_DET_N			GPIO2->DI_f.P2			//�Ųֵ�λN
#define AIR_DET				GPIO2->DI_f.P4			//���õ�λ

#define FEED_KEY			GPIO2->DI_f.P6			//ιʳ����
#define RESET_KEY			GPIO2->DI_f.P5			//��λ����


#define FEED_KEY_INT_PIN			0x10		//ιʳ�����ж�PIN��
//#define FEED_TUBE_INT_PIN			0x08		//�����Թ��ж�PIN��
//#define LOCK_KEY_INT_PIN				0x10		//��������PIN��-P1
#define FEED_KEY_INT_EN			(P0EXTIE |=  FEED_KEY_INT_PIN)		//ιʳ�����ж�ʹ��
#define RECORD_KEY_INT_PIN			0x80		//ιʳ�����ж�PIN��
#define RECORD_KEY_INT_EN		(P1EXTIE |=  RECORD_KEY_INT_PIN)		//ιʳ�����ж�ʹ��

#define MOTOR_DELAY			delay_ms(0)			//ιʳ������ʱֹͣ���ʱ��

#endif

//######################### AI_B20 ####################################//
//######################### AI_B20 ####################################//
//######################### AI_B20 ####################################//



//######################################################################//
//######################### ���ܶ��� ####################################//
//#define IR_FEED_TUBE			1		//��ʳ�����
//#define IR_CHECK_FOOD			1		//��ʳ����ܼ������
//#define IR_FOOD_TUBE			1		//���������������
//#define IR_FOOD_TUBE_TWO		1		//2�����������������
//#define IR_FOOD_TUBE_NOW		1		//��������������������
//#define FOOD_TUBE_LED			1		//����������ʾ��
//#define BATTERY_DETECT		1		//��ص�������⹦��
//#define BATTERY_DC_DETECT		1		//û�е�ع���
//#define DC_POWER_CONTROL		1		//��ع����WiFi��Դ
//#define RTC_TIME				1		//ʱ�Ӽ�ʱ
//#define MOTOR_DET_ADDR		1		//������Ƶ�λֹͣλ�ã�ѡ�о����ɿ�ֹͣ��
//#define MOTOR_REVERSE			1		//�����ת����
//#define DOOR_CONTROL			1		//�Ųֿ���
//#define LOCAL_RECORD			1		//����¼������
//#define LOCAL_RECORD_LOW		1		//����¼������:��IC���͵�ƽ����
//#define TY_DP_RECORD			1		//ͿѻDP��¼������
//#define PLAY_KEY_RECORD		1		//�̰�¼������¼������
//#define ONE_KEY_RECORD		1		//������¼������ 
//#define NO_RECORD_FUNC		1		//û��¼������
//#define LOCK_KEY_E			1		//ιʳ������Ϊ��������
//#define LOCK_KEY_KEY_E		1		//����������Ϊ��������
//#define RELOCK_KEY_KEY_E		1		//������������Ϊ��������
//#define TY_DP_LOCK			1		//ͿѻDP����������
//#define THREE_KEY_FUNC		1		//3��������
//#define LS_FEED_INFO			1		//����Ĭ��ιʳ�ƻ�
//#define LED_HIGH_ON			1		//�Ƹߵ�ƽ��
//#define MOTOR_BU_FUNC			1		//��̨����������ƹ���
//#define MOTOR_BU_FUNC			1		//��̨����������ƹ���
//#define FEEDED_ALLOW_ERROR	1		//ιʳ������������
//#define ERROR_LIGHT_ONE_MIN	1		//ιʳ�쳣1���Ӻ�رպ��
//#define KEY_BUZZER_FUNC		1		//�����������칦��
//#define POWER_BEEP			1		//��Դ������
//#define SFN_BEEP				1		//��Դ������
//#define ERROR_LINK_LED_ON		1		//������ڴ�������˸��ʱ������
//#define MACHINE_DUMP_E		1		//����豸�㵹����
//#define OFFLINE_RECORD		1		//����ιʳ��¼
//#define LINK_LED_FUNC			1		//����ƹ���

//#define LOCK_KEY_E_P0			1		//����������Ϊ��������-P0��
//#define LOCK_KEY_E_P1			1		//����������Ϊ��������-P1��
//#define LOCK_KEY_E_P2			1		//����������Ϊ��������-P2��
//#define LOCK_KEY_E_P3			1		//����������Ϊ��������-P3��
//#define FEED_KEY_E_P0			1		//ιʳ��������-P0��
//#define FEED_KEY_E_P1			1		//ιʳ��������-P1��
//#define FEED_KEY_E_P2			1		//ιʳ��������-P2��
//#define FEED_KEY_E_P3			1		//ιʳ��������-P3��
//#define RECORD_KEY_E_P0		1		//¼�������ж�-P0��
//#define RECORD_KEY_E_P1		1		//¼�������ж�-P1��
//#define RECORD_KEY_E_P2		1		//¼�������ж�-P2��
//#define RECORD_KEY_E_P3		1		//¼�������ж�-P3��


//#define FEED_KEY_INT_PIN			0x10		//ιʳ�����ж�PIN��
//#define FEED_TUBE_INT_PIN			0x08		//�����Թ��ж�PIN��
//#define LOCK_KEY_INT_PIN			0x80		//���������ж�PIN��

//#define FEED_KEY_INT_EN			(P0EXTIE |=  FEED_KEY_INT_PIN)		//ιʳ�����ж�ʹ��
//#define RECORD_KEY_INT_EN			1		//¼�������ж�ʹ��

//#define FEED_INFO_ONE_DEL			1				//ιʳ�ƻ���һ�Σ�ιʳ��ɾ��
//#define NEW_FEED_REPORT			1				//����ιʳ�������DP
//#define TY_DP_DESICCANT			1				//ͿѻDP���������ѹ���

//#########################   ���Ŷ���  ####################################//
//##########################################################################//
//sbit MOTOR_DOOR_G 	= P1^7;			//�Ųֵ���Ƴ�
//sbit MOTOR_DOOR_B 	= P1^6;			//�Ųֵ������
//sbit MOTOR_FEED_G 	= P1^4;			//ιʳ�����ת
//sbit MOTOR_FEED_B 	= P1^5;			//ιʳ�����ת
//sbit MOTOR_DET 		= P2^4; 		//ιʳ�г̿��ؼ��   

//sbit IR_DET_F1 		= P3^1;			//����Ͱ�������Թܵ�λ1
//sbit IR_DET_F2		= P3^2;			//����Ͱ�������Թܵ�λ2

//sbit IR_DET 		= P0^3;			//����Թܼ���
//sbit IR_DET_D 		= P0^5;			//�Ųֹ��ŵ�λ�����ųɹ�det�Ŵ�����
//sbit IR_DET_D2 		= P0^6;			//�Ųֿ��ųɹ���λ����
//sbit IR_LED 		= P0^3;			//������ιʳ����Թܵ�

//sbit PWR_LED 		= P3^6;			//��Դ��
//sbit LINK_LED 		= P3^2;			//����״̬��

//sbit FEED_KEY 		= P3^1;			//����ιʳ
//sbit RESET_KEY 		= P1^7;			//��������λ
//sbit RECODE_KEY 	= P1^6;			//¼��

//sbit DC_DET 		= P0^0;			//�����
//sbit BAT_DET 		= P0^1;			//��ص���ADC����

//sbit PLAYE	 		= P3^0;			//������
//sbit RECORD 		= P3^1;			//¼����

//sbit WIFI_PWR_EN	= P2^3;			//wifi��Դ����

//sbit RGB_PWR_CTRL 	= P2^3;			//RGB�Ƶ�Դ����
//sbit DATA 			= P2^2;			//RGB�ƿ���

//sbit SWDIO 			= P3^5;			//������¼���ڣ�TXD��
//sbit SWCLK 			= P2^1;

//sbit MCU_TXD 		= P2^5;			//��λ��ͨ�Ŵ���
//sbit MCU_RXD 		= P2^6;
//##########################################################################//
//##########################################################################//


#ifndef RESET_KEY_TIME_U
#define RESET_KEY_TIME_U		700				//��λ��������λ����ʱ��
#endif

#ifndef RECORD_TIME_MAX_U
#define RECORD_TIME_MAX_U		1000				//¼����ʱʱ��
#endif






#endif
