/*
 * Keypad.c
 *
 * Created: 27-10-2020 18:01:54
 *  Author: Abhinav
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int main(void)
{
	DDRA = 0b00001111;
	DDRC = 0b00000011;
	DDRD = 0xFF;
	lcdInit();
	sendString("Keypad");
	_delay_ms(2000);
	sendCmd(0x01);
    while(1)
    {
		PORTA = 0b00000001;
		_delay_ms(10);
		if (PINB & (1<<0))
		{
			sendCmd(0x80);
			sendString("1");
		}			
		else if (PINB & (1<<1))
		{
			sendCmd(0x80);
			sendString("4");
		}
		else if (PINB & (1<<2))
		{
			sendCmd(0x80);
			sendString("7");	
		}
		else if (PINB & (1<<3))
		{
			sendCmd(0x80);
			sendString("*");
		}		
		
		PORTA = 0b00000010;
		_delay_ms(10);
		if (PINB & (1<<0))
		{
			sendCmd(0x80);
			sendString("2");
		}
		else if (PINB & (1<<1))
		{
			sendCmd(0x80);
			sendString("5");
		}
		else if (PINB & (1<<2))
		{
			sendCmd(0x80);
			sendString("8");
		}
		else if (PINB & (1<<3))
		{
			sendCmd(0x80);
			sendString("0");
		}
		
		PORTA = 0b00000100;
		_delay_ms(10);
		if (PINB & (1<<0))
		{
			sendCmd(0x80);
			sendString("3");
		}
		else if (PINB & (1<<1))
		{
			sendCmd(0x80);
			sendString("6");
		}
		else if (PINB & (1<<2))
		{
			sendCmd(0x80);
			sendString("9");
		}
		else if (PINB & (1<<3))
		{
			sendCmd(0x80);
			sendString("=");
		}
		
		PORTA = 0b00001000;
		_delay_ms(10);
		if (PINB & (1<<0))
		{
			sendCmd(0x80);
			sendString("+");
		}
		else if (PINB & (1<<1))
		{
			sendCmd(0x80);
			sendString("-");
		}
		else if (PINB & (1<<2))
		{
			sendCmd(0x80);
			sendString("/");
		}
		else if (PINB & (1<<3))
		{
			sendCmd(0x80);
			sendString("*");
		}
				
			
    }
}