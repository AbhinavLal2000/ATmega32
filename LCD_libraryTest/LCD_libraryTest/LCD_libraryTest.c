/*
 * LCD_libraryTest.c
 *
 * Created: 16-05-2020 19:27:59
 *  Author: Abhinav Lal
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#define F_CPU 1000000

int main(void)
{
	DDRD = 0xFF;
	DDRB = 0b00000011;
	lcdInit();
	sendString("Abhinav Lal");
	//sendCmd(0x80); // Force cursor to begin with 1 line
	sendCmd(0xC0); // Force cursor to begin with 2 line
	sendString("LCD.h build AVR");
}