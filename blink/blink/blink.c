/*
 * blink.c
 *
 * Created: 14-05-2020 20:16:42
 *  Author: Abhinav Lal
 */ 

// This program will blink PIN 0 of all the PORTS of ATmega32

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000

int main(void)
{
	DDRA = 0x01;
	DDRB = 0x01;
	DDRC = 0x01;
	DDRD = 0x01;
    while(1)
    {
		PORTA = 0x01;
		PORTB = 0x01;
		PORTC = 0x01;
		PORTD = 0x01;
		_delay_ms(250);
		PORTA = 0;
		PORTB = 0;
		PORTC = 0;
		PORTD = 0;
		_delay_ms(250); 
    }
}