#include "PHOTOELECTRIC.H"

typedef struct//���ģ��ṹ��
{
	u8 state;//����ŵ�״̬���Ƿ�������������Ϊ1����Ϊ0
	u8 switcher;//�����ʹ�ܿ���
}PhotoElectricModular;

static PhotoElectricModular s_PhotoEle[PHOTOELE_NUM];

/*************************************************
 *�������ƣ�void openPhotoEleMod(u8 PHOTOELE_N)
 *������u8 PHOTOELE_N������豸�ı��
 *����ֵ����
 *���ã�����ָ���Ĺ���豸
 *************************************************/
void openPhotoEleMod(u8 PHOTOELE_N)
{
	s_PhotoEle[PHOTOELE_N].switcher = ON;
}

/*************************************************
 *�������ƣ�void openPhotoEleMod(u8 PHOTOELE_N)
 *������u8 PHOTOELE_N������豸�ı��
 *����ֵ����
 *���ã�����ָ���Ĺ���豸
 *************************************************/
void closePhotoEleMod(u8 PHOTOELE_N)
{
	s_PhotoEle[PHOTOELE_N].switcher = OFF;
	s_PhotoEle[PHOTOELE_N].state = 0;
}

/*************************************************
 *�������ƣ�void openAllPhotoEleMod()
 *��������
 *����ֵ����
 *���ã��������й���豸
 *************************************************/
void openAllPhotoEleMod()
{
	u8 i;
	for(i = 0;i < PHOTOELE_NUM;i++)
	{
		s_PhotoEle[i].switcher = ON;
	}
}

/*************************************************
 *�������ƣ� void closeAllPhotoEleMod()
 *��������
 *����ֵ����
 *���ã��������й���豸
 *************************************************/
void closeAllPhotoEleMod()
{
	u8 i;
	for(i = 0;i < PHOTOELE_NUM;i++)
	{
		s_PhotoEle[i].switcher = OFF;
		s_PhotoEle[i].state = 0;
	}
}

/*************************************************
 *�������ƣ�u8 getPhotoEleState(u8 PHOTOELE_N)
 *������u8 PHOTOELE_N������豸�ı��
 *����ֵ��unsigned char
 *���ã�����ָ���Ĺ���豸��״̬
 *************************************************/
u8 getPhotoEleState(u8 PHOTOELE_N)
{
	return s_PhotoEle[PHOTOELE_N].state;
}

/*************************************************
 *�������ƣ�u8 getNightEleState(void)
 *��������
 *����ֵ��unsigned char����
 *���ã�������ʹ�õĹ���豸��״̬
 *************************************************/
u8 getNightEleState(void)
{
	u8 EleState = 0,i;
	for(i = PHOTOELE_NUM;i >= 0;i--)
	{
		if(s_PhotoEle[i].state == 1)
		{	
			EleState <<= 1;
			EleState |= 0x01;
		}
	}
	return EleState;
}

/*************************************************
 *�������ƣ�void PhotoElectricScan(void)
 *��������
 *����ֵ����
 *���ã�����豸״̬ɨ��
 *************************************************/
void PhotoElectricScan(void)
{
	if(ELECTRTIC_1 == 0 && (s_PhotoEle[PHOTOELE_1].switcher == ON))
	{
		s_PhotoEle[PHOTOELE_1].state = 1;
	}
		else
	{
		s_PhotoEle[PHOTOELE_1].state = 0;
	}
	if(ELECTRTIC_2 == 0 && (s_PhotoEle[PHOTOELE_2].switcher == ON))
	{
		s_PhotoEle[PHOTOELE_2].state = 1;
	}
		else
	{
		s_PhotoEle[PHOTOELE_2].state = 0;
	}
	if(ELECTRTIC_3 == 0 && (s_PhotoEle[PHOTOELE_3].switcher == ON))
	{
		s_PhotoEle[PHOTOELE_3].state = 1;
	}
		else
	{
		s_PhotoEle[PHOTOELE_3].state = 0;
	}
	if(ELECTRTIC_4 == 0 && (s_PhotoEle[PHOTOELE_4].switcher == ON))
	{
		s_PhotoEle[PHOTOELE_4].state = 1;
	}
		else
	{
		s_PhotoEle[PHOTOELE_4].state = 0;
	}
	if(ELECTRTIC_5 == 0 && (s_PhotoEle[PHOTOELE_5].switcher == ON))
	{
		s_PhotoEle[PHOTOELE_5].state = 1;
	}
		else
	{
		s_PhotoEle[PHOTOELE_5].state = 0;
	}
	if(ELECTRTIC_6 == 0 && (s_PhotoEle[PHOTOELE_6].switcher == ON))
	{
		s_PhotoEle[PHOTOELE_6].state = 1;
	}
		else
	{
		s_PhotoEle[PHOTOELE_6].state = 0;
	}
	if(ELECTRTIC_7 == 0 && (s_PhotoEle[PHOTOELE_7].switcher == ON))
	{
		s_PhotoEle[PHOTOELE_7].state = 1;
	}
		else
	{
		s_PhotoEle[PHOTOELE_7].state = 0;
	}
	if(ELECTRTIC_8 == 0 && (s_PhotoEle[PHOTOELE_8].switcher == ON))
	{
		s_PhotoEle[PHOTOELE_8].state = 1;
	}
		else
	{
		s_PhotoEle[PHOTOELE_8].state = 0;
	}
	delay_ms(20);
}