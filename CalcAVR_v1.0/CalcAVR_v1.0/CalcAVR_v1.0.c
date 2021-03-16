/*
 * CalcAVR_v1.0.c
 *
 * Created: 28-05-2020 13:30:50
 *  Author: Abhinav Lal
 */ 

/*** Connections 16x2 LCD ***
 * PORTD to LCD Data lines D0-D7
 * Enable pin to PINB0
 * RS pin to PINB1
 * RW to ground
 * VSS:ground VDD:+5V
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int main(void)
{
	DDRD = 0xFF;
	DDRB = 0b00000011;
	DDRC = 0;
	uint8_t l[10] = {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};
	uint8_t n[10] = {0,1,2,3,4,5,6,7,8,9};
	uint8_t o[4] = {0x2B,0x2D,0x2A,0x2F};
	static char buff[4];
	uint8_t i=-1;
	uint8_t j=-1;
	uint8_t k=-1;
	uint8_t m=0,p=0,op=5;
	unsigned int *r=0;
	lcdInit();
	sendString("  CalcAVR v1.0");
	sendCmd(0xC0);
	sendString("    LAL Tech   ");
	_delay_ms(750);
	sendCmd(0x01);
    while(1)
    {
		if (i == 9)
		{
			i=-1;
		}
		else if (PINC & (1<<7))
		{
			i++;
			m=i;
			sendCmd(0x80);
			sendData(l[m]);
			_delay_ms(200);
			
		}
		if (j == 9)
		{
			j=-1;
		}
		else if (PINC & (1<<1))
		{
			j++;
			p=j;
			sendCmd(0x80);
			sendCmd(0x14);
			sendCmd(0x14);
			sendCmd(0x14);
			sendCmd(0x14);
			sendData(l[p]);
			_delay_ms(200);
		}
		if (k == 3)
		{
			k=-1;
		}
		else if (PINC & (1<<6))
		{
			k++;
			op=k;
			sendCmd(0x80);
			sendCmd(0x14);
			sendCmd(0x14);
			sendData(o[op]);
			_delay_ms(200);
		}
		else if (PINC & (1<<0))
		{
			switch (o[op])
			{
				case 0x2B:           // +
				r = n[m] + n[p];
				sendCmd(0xC0);
				sprintf(buff,"= %d           ",r);
				sendString(buff);
				r=0;
				break;
				
				case 0x2D:         // -
				r = n[m] - n[p];
				sendCmd(0xC0);
				sprintf(buff,"= %d           ",r);
				sendString(buff);
				r=0;
				break;
				
				case 0x2A:         // *
				r = n[m] * n[p];
				sendCmd(0xC0);
				sprintf(buff,"= %d           ",r);
				sendString(buff);
				r=0;
				break;
				
				case 0x2F:        // /
				r = n[m] / n[p];
				sendCmd(0xC0);
				sprintf(buff,"= %d           ",r);
				sendString(buff);
				r=0;
				break;
				
				default:
				sendCmd(0xC0);
				sendString("operator error");
				break;
			}			
			
			
		}			
	}
}