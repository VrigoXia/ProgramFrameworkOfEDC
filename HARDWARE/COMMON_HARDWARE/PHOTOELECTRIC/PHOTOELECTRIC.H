#ifndef __PHOTOELECTRIC_H__
#define __PHOTOELECTRIC_H__

#include "../BSP/BSP.H"

/*************************************************ʹ��ǰ���趨�����������Ӧ������********************************************/
#define ELECTRTIC_1 P50//������豸��Ӧ������
#define ELECTRTIC_2 P31//
#define ELECTRTIC_3 P32//
#define ELECTRTIC_4 P33//
#define ELECTRTIC_5 P34//
#define ELECTRTIC_6 P35//
#define ELECTRTIC_7 P36//
#define ELECTRTIC_8 P37//
#define PHOTOELE_NUM 1//����豸��������ֹ����8
#define PHOTOELE_1 0//
#define PHOTOELE_2 1//
#define PHOTOELE_3 2//
#define PHOTOELE_4 3//
#define PHOTOELE_5 4//
#define PHOTOELE_6 5//
#define PHOTOELE_7 6//
#define PHOTOELE_8 7//

/*
ʹ�÷���:

  PhotoElectricScan(void);//�˺�������ʵʱ���н���
	����
	void task_N(void) _task_ PhotoElectScan
	{
		while(1)
		{
			PhotoElectricScan();
			os_wait(K_TMO,5,0);
		}
	}
	
	����ɨ���ʹ�����ú���openPhotoEleMod()��openAllPhotoEleMod(u8 PHOTOELE_N)����������Ч
	
*/

void PhotoElectricScan(void);//����豸״̬ɨ��
u8 getNightEleState(void);//��ȡȫ������豸��״̬
u8 getPhotoEleState(u8 PHOTOELE_N);//��ȡĳ������ŵ�״̬
void closeAllPhotoEleMod();//�������й����
void openAllPhotoEleMod();//�������й����
void closePhotoEleMod(u8 PHOTOELE_N);//���õ��������
void openPhotoEleMod(u8 PHOTOELE_N);//����ĳ�������