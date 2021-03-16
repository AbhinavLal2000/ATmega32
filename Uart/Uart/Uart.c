/*
 * Uart.c
 *
 * Created: 07-11-2020 15:49:15
 *  Author: Abhinav
 */ 


#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000

void UART_init(unsigned int pre)
{
	UCSRB |= (1 << TXEN);
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	UBRRL = (unsigned char)pre;
	UBRRH = (unsigned char)(pre >> 8);
}

void UART_send(unsigned int data)
{
	while(!(UCSRA & (1 << UDRE)));
	UDR = data;
}

int main(void)
{
	unsigned int ubr = 25;
	unsigned char *n[] = {'A','B','H','I','N','A','V',' '};
	unsigned char *m[] = {'0','1','2','3','4','5','6','7','8','9',' '};
	UART_init(ubr);
    while(1)
    {
		for (unsigned int i=0;i<8;i++)
		{
			UART_send(n[i]);
			_delay_ms(250);
		}
		for (unsigned int j=0;j<11;j++)
		{
			UART_send(m[j]);
			_delay_ms(250);
		}
		 
    }
}