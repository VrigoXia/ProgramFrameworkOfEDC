/************************************************************
* ��֯���ƣ�
* �ļ�����: BUTTON.c
* ����:  �ܳ���
* �汾 : v1.0
* ����:
* ����: ������ʼ������غ���
* ��Ҫ�������书�� : 

* ��ʷ�޸ļ�¼: // ��ʷ�޸ļ�¼
* <����> <ʱ��> <�汾 > <����>
* �ܳ���
***********************************************************/
#include "BUTTON.h"

#define BUTTON
#ifdef BUTTON
////extern  struct PID pid;
///*************************************************
//* ��������: void Button_config()
//* ����: Ƭ�ϰ���io��ʼ������
//* ����˵��: ��ʼ�� P23,24,25,26Ϊ����
//*************************************************/
//void Button_config(void)
//{
//    GPIO_InitTypeDef    GPIO_InitStructure;     //�ṹ����
//    GPIO_InitStructure.Pin  = BUTTON1_GPIO_PIN | BUTTON2_GPIO_PIN | BUTTON3_GPIO_PIN|BUTTON4_GPIO_PIN;      //ָ��Ҫ��ʼ����IO, GPIO_Pin_0 ~ GPIO_Pin_7, �����
//    GPIO_InitStructure.Mode = GPIO_PullUp;       //ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
//    GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);  //��ʼ��
//    P23=1;
//    P24=1;
//    P25=1;
//    P26=1;
//}
///*************************************************
//* ��������:static bit digitalRead(pin)//��ȡ����״̬����,���°�������1��û���·���0
//* ����: �����������ŵ�ƽ��ȡ����
//* ����: ��Ҫ��ȡ��pin* ���:
//* ����ֵ: ���ŵ�ƽ�����·���1��δ���·���0
//* ����˵��: �ڲ��������ⲿ�������
//*************************************************/
///*static bit digitalRead(pin)//��ȡ����״̬����,���°�������1��û���·���0
//{
//    if(!pin)
//    {
//        return !pin;
//    }
//}
//static bit BUTTON1_bit=0;
//static bit BUTTON2_bit=0;
//static bit BUTTON3_bit=0;
//static bit BUTTON4_bit=0;*/
/*************************************************
* ��������: unsigned char getButtonState(u8 BUTTON_data)
* ����: ����״̬��ȡ
* ����: �������ź�
* ����ֵ: ����״̬�����·���1��δ���·���0
* ����˵��: �˺���Ϊ���ӿں���
*************************************************/
u8 getButtonState(u8 BUTTON_data)
{
   return g_Button[BUTTON_data];
}
/*************************************************
* ��������: void  buttonScan(void )//����ɨ�躯��
* ����: ����������
* ����: ��
* ���: ��
* ����ֵ: ��
* ����˵��: �˰���������û��ʹ�õ���ʱ����
*           ���ں����Ĺ����иĽ��˺���
*************************************************/
void  buttonScan(void )//����ɨ�躯��
{
	static unsigned char wait;
	u8 i,num;
	if(!getButtonNum())
	{
		num = getButtonNum();
		if(num)
		{
			g_Button[num] = 1;	
			wait = 0;
		}
		else
		{
			if(wait == 1000)
			{
				for(i = 0;i < 16;i++)
				{
					g_Button[i] = 0;
				}
			}
		}
		wait++;
	}
}
#endif