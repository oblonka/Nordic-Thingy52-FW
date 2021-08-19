#ifndef __LINUX_AXP_CFG_H_
#define __LINUX_AXP_CFG_H_

/*
���ƽ̨��ص�ͷ�ļ�
			*/


#include "axp-mfd-216.h"

#include <stdint.h>//*

/*�豸��ַ*/
/*
	һ�㲻�ı䣺
	AXP216: д��ַ ��0x68	����ַ��0x69
*/
#define	AXP_DEVICES_ADDR	0x68 



/*AXP216 ������	*/
uint8_t AXP216_read( uint8_t readAddr, uint8_t byteNum , uint8_t *readData);//*
/*AXP216 д����	*/
uint8_t AXP216_write(const uint8_t writeAddr, const uint8_t writeData);
/*AXP216 ��ʱ����*/
void delay_ms(uint16_t nms);//*
/*AXP216 λ��1����*/
void axp_set_bits(int reg, uint8_t bit_mask);
/*AXP216 λ��0����*/
void  axp_clr_bits(int reg, uint8_t bit_mask);
/*AXP216 ��*/
void  axp_update(int reg, uint8_t val, uint8_t mask);



/*debug���ܿ��أ�1:�� 0 ���ر�*/
#define axp_debug		1		



/*���������mAh������ʵ�ʵ�����������壬�Կ��ؼƷ�����˵
�����������Ҫ����������*/
#define BATCAP				3000

/*��ʼ��������裬m����һ����100~200֮�䣬������ø���ʵ��
���Գ�����ȷ���������Ǵ򿪴�ӡ��Ϣ�����ӵ���պù̼���
�ϵ�أ����ӳ����������������1���Ӻ󣬽��ϳ��������
1~2���ӣ�����ӡ��Ϣ�е�rdcֵ����������*/
#define BATRDC				100

/*��·��ѹ�����еĵ�ص�ѹ�Ļ���*/
//#define AXP_VOL_MAX			1
/*
	��繦��ʹ�ܣ�
        AXP:0-�رգ�1-��
*/
#define CHGEN       1

/*
	���������ã�uA��0Ϊ�رգ�
		AXP:300~2550,100/step
*/
/*��������uA*/
#define STACHGCUR			900*1000


/*Ŀ�����ѹ��mV*/
/*
	AXP:4100000/4200000/4240000/4350000
*/
#define CHGVOL				4200000

/*������С�����õ�����ENDCHGRATE%ʱ��ֹͣ��磬%*/
/*
	AXP:10\15
*/
#define ENDCHGRATE			10
/*�ػ���ѹ��mV*/
/*
	ϵͳ��ƵĹػ�����ĵ�ض˵�ѹ����Ҫ��ػ��ٷֱȡ�
	��·��ѹ��Ӧ�ٷֱȱ��͵羯���ѹ�໥��ϲŻ�������
*/
#define SHUTDOWNVOL			3300

/*adc���������ã�Hz*/
/*
	AXP:100\200\400\800
*/
#define ADCFREQ				100

/*Ԥ��糬ʱʱ�䣬min*/
/*
	AXP:40\50\60\70
*/
#define CHGPRETIME			50
/*������糬ʱʱ�䣬min*/
/*
	AXP:360\480\600\720
*/
#define CHGCSTTIME			480


/*pek����ʱ�䣬ms*/
/*
	��power��Ӳ������ʱ�䣺
		AXP:128/1000/2000/3000
*/
#define PEKOPEN				1000
/*pek����ʱ�䣬ms*/
/*
	��power���������жϵ�ʱ�䣬���ڴ�ʱ���Ƕ̰������̰���irq��
	���ڴ�ʱ���ǳ�������������irq��
		AXP:1000/1500/2000/2500
*/
#define PEKLONG				1500
/*pek�����ػ�ʹ��*/
/*
	��power�������ػ�ʱ��Ӳ���ػ�����ʹ�ܣ�
		AXP:0-���أ�1-�ػ�
*/
#define PEKOFFEN			1
/*pek�����ػ�ʹ�ܺ󿪻�ѡ��*/
/*
	��power�������ػ�ʱ��Ӳ���ػ���������ѡ��:
		AXP:0-ֻ�ػ���������1-�ػ�������
*/
#define PEKOFFRESTART			0
/*pekpwr�ӳ�ʱ�䣬ms*/
/*
	������powerok�źŵ��ӳ�ʱ�䣺
		AXP20:8/16/32/64
*/
#define PEKDELAY			32
/*pek�����ػ�ʱ�䣬ms*/
/*
	��power���Ĺػ�ʱ����
		AXP:4000/6000/8000/10000
*/
#define PEKOFF				6000
/*���¹ػ�ʹ��*/
/*
	AXP�ڲ��¶ȹ���Ӳ���ػ�����ʹ�ܣ�
		AXP:0-���أ�1-�ػ�
*/
#define OTPOFFEN			0
/* ����ѹ����ʹ��*/
/*
	AXP:0-�رգ�1-��
*/
#define USBVOLLIMEN		1
/*  �����ѹ��mV��0Ϊ������*/
/*
	AXP:4000~4700��100/step
*/
#define USBVOLLIM			4500
/*  USB�����ѹ��mV��0Ϊ������*/
/*
	AXP:4000~4700��100/step
*/
//#define USBVOLLIMPC			4700

/* ����������ʹ��*/
/*
	AXP:0-�رգ�1-��
*/
#define USBCURLIMEN		1
/* ���������mA��0Ϊ������*/
/*
	AXP:500/900
*/
#define USBCURLIM			0
/* usb ���������mA��0Ϊ������*/
/*
	AXP:500/900
*/
#define USBCURLIMPC			500
/* PMU �жϴ�������ʹ��*/
/*
	AXP:0-�����ѣ�1-����
*/
#define IRQWAKEUP			0
/* N_VBUSEN PIN ���ܿ���*/
/*
	AXP:0-���������OTG��ѹģ�飬1-���룬����VBUSͨ·
*/
#define VBUSEN			1
/* ACIN/VBUS In-short ��������*/
/*
	AXP:0-AC VBUS�ֿ���1-ʹ��VBUS��AC,�޵���AC
*/
#define VBUSACINSHORT			0
/* CHGLED �ܽſ�������*/
/*
	AXP:0-������1-�ɳ�繦�ܿ���
*/
#define CHGLEDFUN			0
/* CHGLED LED ��������*/
/*
	AXP:0-���ʱled������1-���ʱled��˸
*/
#define CHGLEDTYPE			0
/* ���������У��ʹ��*/
/*
	AXP:0-�رգ�1-��
*/
#define BATCAPCORRENT			0
/* �����ɺ󣬳�����ʹ��*/
/*
	AXP:0-�رգ�1-��
*/
#define BATREGUEN			0
/* ��ؼ�⹦��ʹ��*/
/*
	AXP:0-�رգ�1-��
*/
#define BATDET		1
/* PMU����ʹ��*/
/*
	AXP:0-�رգ�1-�򿪰���Դ��16������PMU����
*/
#define PMURESET		0
/*�͵羯���ѹ1��%*/
/*
	����ϵͳ���������
	AXP:5%~20%
*/
#define BATLOWLV1    15
/*�͵羯���ѹ2��%*/
/*
	����ϵͳ���������
	AXP:0%~15%
*/
#define BATLOWLV2    0

#define ABS(x)				((x) >0 ? (x) : -(x) )


/*��ʼ����·��ѹ��Ӧ�ٷֱȱ�*/
/*
	����ʹ��Ĭ��ֵ��������ø���ʵ�ʲ��Եĵ����ȷ��ÿ��
	��Ӧ��ʣ��ٷֱȣ��ر���Ҫע�⣬�ػ���ѹSHUTDOWNVOL�͵��
	������ʼУ׼ʣ�������ٷֱ�BATCAPCORRATE��������׼ȷ��
	AXP����
*/
#define OCVREG0				0		 //3.13V
#define OCVREG1				0		 //3.27V
#define OCVREG2				0		 //3.34V
#define OCVREG3				0		 //3.41V
#define OCVREG4				0		 //3.48V
#define OCVREG5				0		 //3.52V
#define OCVREG6				0		 //3.55V
#define OCVREG7				0		 //3.57V
#define OCVREG8				5		 //3.59V
#define OCVREG9				8		 //3.61V
#define OCVREGA				9		 //3.63V
#define OCVREGB				10		 //3.64V
#define OCVREGC				13		 //3.66V
#define OCVREGD				16		 //3.7V
#define OCVREGE				20		 //3.73V
#define OCVREGF				33		 //3.77V
#define OCVREG10		 	41                //3.78V
#define OCVREG11		 	46                //3.8V
#define OCVREG12		 	50                //3.82V
#define OCVREG13		 	53                //3.84V
#define OCVREG14		 	57                //3.85V
#define OCVREG15		 	61                //3.87V
#define OCVREG16		 	67                //3.91V
#define OCVREG17		 	73                //3.94V
#define OCVREG18		 	78                //3.98V
#define OCVREG19		 	84                //4.01V
#define OCVREG1A		 	88                //4.05V
#define OCVREG1B		 	92                //4.08V
#define OCVREG1C		 	93                //4.1V
#define OCVREG1D		 	94                //4.12V
#define OCVREG1E		 	95                //4.14V
#define OCVREG1F		 	100                //4.15V



/*ѡ����Ҫ�򿪵��ж�ʹ��*/
static const uint64_t AXP_NOTIFIER_ON = (AXP_IRQ_USBIN |AXP_IRQ_USBRE |AXP_IRQ_USBOV|
				       		             AXP_IRQ_ACIN  |AXP_IRQ_ACRE  |AXP_IRQ_ACOV	|
				       		             AXP_IRQ_BATIN |AXP_IRQ_BATRE |
				       		             AXP_IRQ_CHAST |AXP_IRQ_CHAOV |AXP_IRQ_POKSH|
										 AXP_IRQ_POKLO | AXP_IRQ_POKSH|
						                (uint64_t)AXP_IRQ_PEKFE |(uint64_t)AXP_IRQ_PEKRE);

/* ��Ҫ�������ţ��usb�ػ�������bootʱpower_start����Ϊ1������Ϊ0*/
//#define POWER_START 0


#endif
