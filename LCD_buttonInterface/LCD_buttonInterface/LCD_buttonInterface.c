/*
 * LCD_buttonInterface.c
 *
 * Created: 16-05-2020 19:45:53
 *  Author: Abhinav Lal
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int main(void)
{
	DDRD = 0xFF;
	DDRB = 0b00000011;
	DDRA = 0b00000000;
	lcdInit();
    while(1)
    {
		if (PINA & (1<<0))
		{
			sendCmd(0x80);
			sendString("HIGH");
		}
		else
		{
			sendCmd(0x80);
			sendString("LOW ");
		}			
    }
}