/*------------------------------------------------------------------
 *
 *	main.c
 *	
 *Description:
 *		16*32LED��������Ƶ�ף����ٸ���Ҷ�任
 *		
 *Author:
 *		hulinkang
 *Date:
 *		2015-4-20
 *------------------------------------------------------------------*/
#include "main.h"
#include "FFT.h"
#include "LED32x16.h"

/*˽�к�������*/
void Timer0Init(void);
void PWM_duty(uint8 );

/*����ȫ�ֱ���*/
uint8 Line = 0;

void main(void)
{
	InitADC();
	Timer0Init();
	PWM_duty(50);//led������Ļ50%����
	EA = 1; 	
	//OE = 0;
	while(1){
		FFT();//��ʱ60ms
	}
}

/*��ʱ����ʼ������ʱ3ms,3ms�����һ��led����ʾ*/
void Timer0Init(void)		//30ms@24.000MHz
{
	AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = (65536 - OSC_FREQ / OSC_PER_INST / 1000 * 3);	
	TH0 = (65536 - OSC_FREQ / OSC_PER_INST / 1000 * 3) >> 8;
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��T0��ʼ����
	
	ET0 = 1;
}

/*PWM���ȵ��ں���*/
void PWM_duty(uint8 n)//11.7KHz,�ٷֱ�ռ�ձ�,P1.3����
{
	uint8 i = 0;
	CCON = 0;             	//Initial PCA control register
							//PCA timer stop running
							//Clear CF flag
                            //Clear all module interrupt flag
    CL = 0;           		//Reset PCA base timer
    CH = 0;
    CMOD = 0x0e;           	//Set PCA timer clock source as Fosc/8  3MHz
							//Disable PCA timer overflow interrupt
	i = n*255/100;//��
	
    CCAP0H = CCAP0L = 255 - i;  //PWM0 port output 50% duty cycle square wave
    CCAPM0 = 0x42;      //PCA module-0 work in 8-bit PWM mode and no PCA interrupt

    CR = 1;         	//PCA timer start run
}


void Timer0_Isr(void) interrupt ISR_T0
{
	TL0 = (65536 - OSC_FREQ / OSC_PER_INST / 1000 * 3);	
	TH0 = (65536 - OSC_FREQ / OSC_PER_INST / 1000 * 3) >> 8;
	sendData(Line);
	scan(Line);
	STCP=1;
	Line++;
	Line = Line % 16;
	STCP=0;
}

	
	
