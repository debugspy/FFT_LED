/*------------------------------------------------------------------
 *
 *	LED32x16.c
 *	
 *Description:
 *		32x16ledģ����ʾ����
 *Author:
 *		hulinkang
 *Date:
 *		2015-4-22
 *------------------------------------------------------------------*/
#include "LED32x16.h"
#include "fft.h"

/*����FFT.c�е�ȫ�ֱ���*/
extern xdata volatile uint8 result[FREQ_TAB]; //��ɫ��״��32��
extern xdata volatile uint8 topPoint[FREQ_TAB];//��ɫ�㣬32��
	
/*-------------------------------------------------------------------
 *��������32x16LED��ʾ����
 *˵����
 *		SHCP��������λ����һ������
 *
 *���룺
 *�����
---------------------------------------------------------------------*/
void sendData(uint8 line)
{
	uint8 i;
	for(i = 0; i < 32; i++) {
		SHCP = 0;
		
		GREEN = 1;
		RED   = 1;
		//��һ��Ƶ��������
		if(result[i] > line) {
			GREEN = 0;//green
			RED   = 1;
			
		}
		//��һ��Ư��������
		if(topPoint[i] == line) {
			GREEN = 1;	//RED point
			RED   = 0;
		}
		SHCP = 1;
	}
}

/*��ѡ*/
void scan(uint8 value)
{
	switch(value){
		case  0: line0;break;
		case  1: line1;break;
		case  2: line2;break;
		case  3: line3;break;
		case  4: line4;break;
		case  5: line5;break;
		case  6: line6;break;
		case  7: line7;break;
        case  8: line8;break;
		case  9: line9;break;
		case 10:line10;break;
		case 11:line11;break;
        case 12:line12;break;
		case 13:line13;break;
		case 14:line14;break;
	    case 15:line15;break;
		default:break;
	}
}

