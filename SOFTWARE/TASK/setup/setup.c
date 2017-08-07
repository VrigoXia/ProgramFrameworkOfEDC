/************************************************************
* 组织名称：
* 文件名称: K:\单片机相关\电子大赛程序框架\SOFTWARE\TASK\SETUP.C
* 作者:     周晨阳
* 版本:
* 日期:     2017/07/18
* 描述:		初始化器件和测试器件使用
* 历史修改记录:
* <作者> <时间> <版本 > <描述>
*
***********************************************************/

#include "setup.h"

/*************  串口1初始化函数 *****************/
/*************************************************
* 函数名称: void    UART1_init(unsigned long BandRate)
* 描述: 串口1初始化函数
* 输入: unsigned long BandRate ：串口的波特率，请在数值后加字母"L"，防止出问题
* 输出: 调用此函数会发送一段测试语句 “ STC15w4k58s4 UART1 is open ”
* 返回值: 无
* 其他说明: 无
*************************************************/
void    UART1_init(unsigned long BandRate)
{
	COMx_InitDefine     COMx_InitStructure;
	COMx_InitStructure.UART_Mode = UART_8bit_BRTx;
	COMx_InitStructure.UART_BRT_Use = BRT_Timer1;
	COMx_InitStructure.UART_BaudRate = BandRate;
	COMx_InitStructure.UART_RxEnable = ENABLE;
	COMx_InitStructure.BaudRateDouble = DISABLE;
	COMx_InitStructure.UART_Interrupt = ENABLE;
	COMx_InitStructure.UART_Polity = PolityHigh;
	COMx_InitStructure.UART_P_SW = UART1_SW_P30_P31;
	COMx_InitStructure.UART_RXD_TXD_Short = DISABLE;
	USART_Configuration(USART1, &COMx_InitStructure);
	PrintString1("STC15w4k58s4's UART1 is open \r\n");   //串口测试
}
void test(void)//器件测试
{
	u8 i = 0;
	Ds1302_Init();
	USART1_printf("this is a test\r\n");
	for (i = 0; i < 8; i++)
	{
		time_buf[i] = 1;
	}
	while (1)
	{
		{
			Ds1302_Read_Time();
			USART1_printf("%d-%d-%d-%d \r\n", (int)time_buf1[3], (int)time_buf1[4], (int)time_buf1[5], (int)time_buf1[6]);//年月日  %02d 十进制整数 
			delay_ms(200);
		}
	}
}
void setup(void)
{

	UART1_init(9600);
	timerInit();
	Board_LED_Init();
	LCD5510_Init();
	LCD_printsl(0, 0, "Hello!");
	os_wait(K_TMO, 250, 0);
	LCD_clr_scr();
	Button_config();
	Speaker_Init();

 
	//InitJY901(JY901_1);
	//EnableJY901(JY901_1);
	//openJY901SbufMode(JY901_1);
	ADC_config(ADC_P10, ADC_540T);
	ADS1115_Config();
	HC_SR04_init();
	open_HC_SR04(HC_SR04_1);
	open_ADS1115(CHANNEL_1);
	open_ADS1115(CHANNEL_2);
	open_ADS1115(CHANNEL_3);
	open_ADS1115(CHANNEL_4);
	// test();

}

