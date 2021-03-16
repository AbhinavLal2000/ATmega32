/*
 * UartRx.c
 *
 * Created: 07-11-2020 18:29:55
 *  Author: Abhinav
 */ 


#include <avr/io.h>
#define F_CPU 1000000

void UART_init(unsigned int p)
{
	UCSRB |= (1 << RXEN);
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	UBRRL = (unsigned char)p;
	UBRRH = (unsigned char)(p >> 8);
}


int main(void)
{
	DDRB = 0b00000110;
	unsigned int ubr = 25;
	UART_init(ubr);
	unsigned char r;
    while(1)
    {
		 while(!(UCSRA & (1 << RXC)));
		 r = UDR;
		 if (r == 'A')
		 {
			 PORTB = 0b00000010;
		 }
		 else if (r == 'B')
		 {
			 PORTB = 0b00000100;;
		 }			 
		  
    }
}