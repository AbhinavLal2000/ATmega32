/*
 * LCD_7segment.c
 *
 * Created: 16-05-2020 20:00:55
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
	DDRA = 0xFF;
	DDRB = 0b00000011;
	int n[10] = {0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x3F};
	int l[10] = {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};
	//char k[10][5] = {"zero ","one  ","two  ","three","four ","five ","six  ","seven","eight","nine "};
	int i=0;
	int j=0;
	int d=500;
	lcdInit();
	sendString("      LAL");
	sendCmd(0xC0); // force cursor to line 2
	sendString("  Technologies  ");
	_delay_ms(2000);
	sendCmd(0x01);
    while(1)
    {
		switch (j)
		{
			case 10:
				j=0;
				sendCmd(0xC0);
				sendString("Reset j   ");
				_delay_ms(d);
			
			default:
				sendCmd(0x80);
				sendString("Iterate: ");
				sendData(l[j]);
				sendCmd(0xC0);
				sendString("Reset Null");
				j++;
				_delay_ms(d);
		}
		switch (i)
		{
			case 10:
			i=0;
			sendCmd(0xC0);
			sendString("Reset i   ");
			_delay_ms(d);
			
			default:
			PORTA = n[i];
			sendCmd(0xC0);
			sendString("Reset Null");
			i++;
			_delay_ms(d);
		}
		
    }
}