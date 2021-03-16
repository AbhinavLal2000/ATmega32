/*
 * Alarm_clock.c
 *
 * Created: 06-11-2020 16:36:11
 *  Author: Abhinav
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int main(void)
{
	DDRB = 0b00000011;
	DDRD = 0xFF;
	lcdInit();
	sendString("Alarm clock");
	_delay_ms(2000);
	sendCmd(0x01);
	unsigned char *num[11] = {'0','1','2','3','4','5','6','7','8','9'};
		
	while(1)
    {
    }
}