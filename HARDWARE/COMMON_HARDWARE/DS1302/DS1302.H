/************************************************************
* ��֯���ƣ�
* �ļ�����: K:\��Ƭ�����\���Ӵ���������\HARDWARE\COMMON_HARDWARE\DS1302\DS1302.H
* ����:
* �汾:
* ����:     2017/08/04
* ����:
* ��ʷ�޸ļ�¼:
* <����> <ʱ��> <�汾 > <����>
*
***********************************************************/
#ifndef _DS1302_H_
#define _DS1302_H_
#include "../BSP/BSP.H"

sbit DS_SCK = P1 ^ 1;
sbit DS_SDA = P1 ^ 3;
sbit RST = P1 ^ 2;
//��λ��
#define RST_CLR	RST=0//��ƽ�õ�
#define RST_SET	RST=1//��ƽ�ø�


//˫������
#define IO_CLR	DS_SDA=0//��ƽ�õ�
#define IO_SET	DS_SDA=1//��ƽ�ø�
#define IO_R	DS_SDA  //��ƽ��ȡ


//ʱ���ź�
#define DS_SCK_CLR	DS_SCK=0//ʱ���ź�
#define DS_SCK_SET	DS_SCK=1//��ƽ�ø�


#define ds1302_sec_add			0x80		//�����ݵ�ַ
#define ds1302_min_add			0x82		//�����ݵ�ַ
#define ds1302_hr_add			0x84		//ʱ���ݵ�ַ
#define ds1302_date_add			0x86		//�����ݵ�ַ
#define ds1302_month_add		0x88		//�����ݵ�ַ
#define ds1302_day_add			0x8a		//�������ݵ�ַ
#define ds1302_year_add			0x8c		//�����ݵ�ַ
#define ds1302_control_add		0x8e		//�������ݵ�ַ
#define ds1302_charger_add		0x90 					 
#define ds1302_clkburst_add		0xbe

#define shuju_1_add 0xc0
#define shuju_2_add 0xc2
#define shuju_3_add 0xc4

//�ڲ��ң��͵�ַ0xc0,0xc2,0xc4.....0xfc����8λ�洢�ռ�;0xfe�洢�ַ�

extern unsigned char time_buf1[8];//��������ʱ������
extern unsigned char time_buf[8];//��������ʱ������

 /*************************************************
 * ��������: Ds1302_Write_Byte
 * ����: ��DS1302д��һ�ֽ�����
 * ����: unsigned char addr, unsigned char d
 * ����ֵ: ��
 * ����˵��: ���ֹͣDS1302����
 *************************************************/
void Ds1302_Write_Byte(unsigned char addr, unsigned char d);

/*************************************************
* ��������: Ds1302_Read_Byte
* ����: ��DS1302����һ�ֽ�����
* ����: unsigned char addr
* ����ֵ: temp
* ����˵��: ����ԭʼ����
*************************************************/
unsigned char Ds1302_Read_Byte(unsigned char addr);

/*************************************************
* ��������: Ds1302_Write_Time
* ����: ��DS1302д��ʱ������
* ����: ��
* ����ֵ: �꣬�£��գ�ʱ���֣��룬��
* ����˵��: ��
*************************************************/
void Ds1302_Write_Time(void);

/*************************************************
* ��������: Ds1302_Read_Time
* ����: ��DS1302����ʱ������
* ����: ��
* ����ֵ:time_buf
* ����˵��: time_buf�����зֱ���{�꣬�£��գ�ʱ���֣��룬��}
*************************************************/
void Ds1302_Read_Time(void);

/*************************************************
* ��������: Ds1302_Init
* ����: DS1302��ʼ��
* ����: ��
* ����ֵ:��
* ����˵��: ds1302ģ���ʼ��
*************************************************/
void Ds1302_Init(void);


#endif