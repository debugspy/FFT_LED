/*-----------------------------------------------------------
 *		FFT.h�ļ�
 *
 *Description��
 *		���ٸ���Ҷ�任��ͷ�ļ�
 *Author��
 *		hulinkang
 *Data��
 *		2015-4-20
 *----------------------------------------------------------*/
 
#ifndef _FFT_H
#define _FFT_H

#include "main.h"


/*-------------------------------------------------------------------------------------------------------
	��Ƶ�����������Ե�ż������FFT֮��ᷢ��ͼ���ǶԳƵġ�����FFT�任�õ�������һ��Ҫȥ��һ�롣
	������Ƶ�ʵ����ֵ�ǲ���Ƶ�ʣ�ÿ�����Ӧ��f(k) = [n/(N/2)]*fs  (fs����Ƶ�ʣ�N����������n�ǵ�n��)
---------------------------------------------------------------------------------------------------------*/
#define SAMPLE_NUM 	128
#define LAYER		7	//2��LAYER�η����� SAMPLE_NUM
#define FREQ_TAB	32	//32*16�ĵ�����Ļ��32��Ƶ�ʵ�
#define RESULT_NUM  64	//SAMPLE_NUM��һ��

/*ADCת��ͨ�� P1.0��*/
#define ADC_CHANNEL 0
 
/*Define ADC operation const for ADC_CONTR*/
#define ADC_POWER   0x80            //ADC power control bit
#define ADC_FLAG    0x10            //ADC complete flag
#define ADC_START   0x08            //ADC start control bit
#define ADC_SPEEDLL 0x00            //420 clocks
#define ADC_SPEEDL  0x20            //280 clocks
#define ADC_SPEEDH  0x40            //140 clocks
#define ADC_SPEEDHH 0x60            //70 clocks


void FFT(void);
uint16 sqrt_16(uint32 );

void InitADC(void);
int16 GetADCResult(void);
static void Delay(uint16 );


#endif
 