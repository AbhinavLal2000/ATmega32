/*
 * Test328p.c
 *
 * Created: 23-09-2020 18:11:06
 *  Author: Abhinav
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0b00000001;
    while(1)
    {
        PORTB = 0b00000001;
		_delay_ms(250);
		PORTB = 0b00000000;
		_delay_ms(250); 
    }
}