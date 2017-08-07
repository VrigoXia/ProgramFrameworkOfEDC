/************************************************************
* �ļ�����: ���Ӵ���������\HARDWARE\COMMON_HARDWARE\BSP\IIC\STC15_IIC.C
* ����:
* �汾:
* ����:     2017/08/03
* ����:iic�������������
* ��ʷ�޸ļ�¼:
* <����> <ʱ��> <�汾 > <����>
*
***********************************************************/

#include    "stc15_iic.h"
#include <stdio.h>
#include "../USART1/USART1.h"
/* ***************************************************** */
// �������ƣ�Delay5US()
// �������ܣ�5΢����ʱ,����Լ�����Ƶ�б䣬�������޸�
// ��ڲ�������
// ���ڲ�������
/* ***************************************************** */
void Delay5US(void)     //@24MHz
{

	unsigned char i;

	_nop_();
	_nop_();
	i = 57;
	while (--i);
}
/* ***************************************************** */
// �������ƣ�IIC_Start()
// �������ܣ�IIC��
// ��ڲ�������
// ���ڲ�������
/* ***************************************************** */
void IIC_Start(void)
{
	SDA = 1;
	Delay5US();
	SCL = 1;
	Delay5US();
	SDA = 0;
	Delay5US();
}
/* ***************************************************** */
// �������ƣ�IIC_Stop()
// �������ܣ�IICֹͣ
// ��ڲ�������
// ���ڲ�������
/* ***************************************************** */
void IIC_Stop(void)
{
	SDA = 0;
	Delay5US();
	SCL = 1;
	Delay5US();
	SDA = 1;
}
/* ***************************************************** */
// �������ƣ�IIC_Ack()
// �������ܣ�IICӦ��
// ��ڲ�������
// ���ڲ�������
/* ***************************************************** */
void IIC_Ack(void)
{
	SCL = 0;                // Ϊ��������׼��
	SDA = 0;                // ����Ӧ���ź�
	Delay5US();             // ��ʱ�㶮��
	SCL = 1;
	Delay5US();
	SCL = 0;
	Delay5US();     // ����������
	SDA = 1;                // �ͷ�����
}
/* ***************************************************** */
// �������ƣ�IIC_RdAck()
// �������ܣ���IICӦ��
// ��ڲ�������
// ���ڲ������Ƿ�Ӧ����ֵ
/* ***************************************************** */
BOOL IIC_RdAck(void)
{
	BOOL AckFlag;
	u8 uiVal = 0;
	SCL = 0;
	Delay5US();
	SDA = 1;
	SCL = 1;
	Delay5US();
	while ((1 == SDA) && (uiVal < 255))
	{
		uiVal++;
		AckFlag = SDA;
	}
	SCL = 0;
	return AckFlag;     // Ӧ�𷵻أ�0;��Ӧ�𷵻أ�1
}
/* ***************************************************** */
// �������ƣ�IIC_Nack()
// �������ܣ�IIC��Ӧ��
// ��ڲ�������
// ���ڲ�������
/* ***************************************************** */
void IIC_Nack(void)
{
	SDA = 1;
	SCL = 0;
	Delay5US();
	SCL = 1;
	Delay5US();
	SCL = 0;
}
/* ***************************************************** */
// �������ƣ�OutputOneByte()
// �������ܣ���IIC�����ж���һ���ֽ�
// ��ڲ�������
// ���ڲ�����������һ���ֽڣ�uByteVal��
/* ***************************************************** */
u8 OutputOneByte(void)
{
	//    u8 uByteVal = 0;
	//    u8 iCount;
	//    SDA = 1;
	//    for (iCount = 0; iCount < 8; iCount++)
	//    {
	//        SCL = 0;
	//        Delay5US();
	//        SCL = 1;
	//        Delay5US();
	//        uByteVal <<= 1;
	//        if(SDA)
	//        {
	//            uByteVal |= 0x01;
	//        }
	//    }
	//    SCL = 0;
	//    return(uByteVal);
	u8 str[8];
	unsigned char i;
	unsigned char Data = 0;       //����һ������Ĵ�����
	for (i = 0; i < 8; i++)//��8λ����
	{
		SCL = 1;//����ʱ���ߣ�Ϊ��ȡ��һλ������׼����
		Delay5US();
		Data = Data << 1;//�������ֽڵ���������һλ��׼����ȡ���ݡ�
		Delay5US();
		if (SDA == 1)//���������Ϊ��ƽ��ƽ��
		{
			Data = Data | 0x1;//��������ֽڵ����λд1��
		}
		else
		{
			Data = Data | 0x0;//
		}

		SCL = 0;//����ʱ���ߣ�Ϊ��ȡ��һλ������׼����
		Delay5US();
	}

	return Data;//���ض�ȡ��һ���ֽ����ݡ�
}
/* ***************************************************** */
// �������ƣ�InputOneByte()
// �������ܣ���IIC����д��һ���ֽ�
// ��ڲ�������д���һ���ֽڣ�uByteVal��
// ���ڲ�������
/* ***************************************************** */
void InputOneByte(u8 uByteVal)
{
	u8 iCount;
	for (iCount = 0; iCount < 8; iCount++)
	{
		SCL = 0;
		Delay5US();
		SDA = (uByteVal & 0x80) >> 7;
		Delay5US();
		SCL = 1;
		Delay5US();
		uByteVal <<= 1;
	}
	SCL = 0;
}
/* ***************************************************** */
// �������ƣ�IIC_WrDevAddAndDatAdd()
// �������ܣ���IIC����д�����������ݵ�ַ
// ��ڲ�����������ַ��uDevAdd�������ݵ�ַ��uDatAdd��
// ���ڲ�����д���Ƿ�ɹ���ֵ
/* ***************************************************** */
BOOL IIC_WrDevAddAndDatAdd(u8 uDevAdd, u8 uDatAdd)
{
	IIC_Start();            // ���Ϳ�ʼ�ź�
	InputOneByte(uDevAdd);  // ����������ַ
	IIC_RdAck();            // ��Ӧ���ź�
	InputOneByte(uDatAdd);  // �������ݵ�ַ
	IIC_RdAck();            // ��Ӧ���ź�
	return TRUE;
}
/* ***************************************************** */
// �������ƣ�IIC_WrDatToAdd()
// �������ܣ���IIC����д����
// ��ڲ���������ID(uDevID)�����ݴ洢��ʼ��ַ(uStaAddVal)
//           ��������(*p)�������洢���ݵĸ���(uiLenVal)
// ���ڲ�������
/* ***************************************************** */
void IIC_WrDatToAdd(u8 uDevID, u8 uStaAddVal, u8 *p, u8 ucLenVal)
{
	u8 iCount;
	IIC_WrDevAddAndDatAdd(uDevID | IIC_WRITE, uStaAddVal);
	// IIC_WRITE Ϊд�����׺��
	for (iCount = 0; iCount < ucLenVal; iCount++)
	{
		InputOneByte(*p++);
		IIC_RdAck();
	}
	IIC_Stop();
}
/* ***************************************************** */
// �������ƣ�IIC_RdDatFromAdd()
// �������ܣ���IIC����������
// ��ڲ���������ID(uDevID)�����ݴ洢��ַ(uStaAddVal)
//           ��������(*p)�������洢���ݵĸ���(uiLenVal)
// ���ڲ�������
/* ***************************************************** */
void IIC_RdDatFromAdd(u8 uDevID, u8 uStaAddVal, u8 *p, u8 uiLenVal)
{
	u8 iCount;
	IIC_WrDevAddAndDatAdd(uDevID | IIC_WRITE, uStaAddVal);
	IIC_Start();
	InputOneByte(uDevID | IIC_READ);
	// IIC_READ Ϊд�����׺��
	IIC_RdAck();
	for (iCount = 0; iCount < uiLenVal; iCount++)
	{
		*p++ = OutputOneByte();
		if (iCount != (uiLenVal - 1))
		{
			IIC_Ack();
		}
	}
	IIC_Nack();
	IIC_Stop();
}
