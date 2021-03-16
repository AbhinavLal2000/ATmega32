/*
 * _7_segment.c
 *
 * Created: 14-05-2020 21:14:21
 *  Author: Abhinav Lal
 */ 

// This code will display 0-9 numbers on a 7 segment display through PORTA 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{ 
	DDRA = 0xFF;
	int n[10] = {0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x3F};
    while(1)
    {
		for (int i=0;i<=9;i++)
		{
			PORTA = n[i];
			_delay_ms(250);
		}
	}
}