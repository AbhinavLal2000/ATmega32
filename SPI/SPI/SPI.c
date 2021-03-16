/*
 * SPI.c
 *
 * Created: 23-2-21 22:16:23
 *  Author: Abhinav
 */ 

/*
SPI Pins

PB6 MISO
PB5 MOSI
PB7 SCK
PB4 SS

*/

#define F_CPU 1000000
#define SS		4
#define MOSI	5
#define MISO	6
#define SCK		7

#include <avr/io.h>
#include <util/delay.h>

void spi_init(void)
{
	// MOSI SCK as output, all others as input
	DDRB |= (1<<MOSI) | (1<<SCK);
	
	// enable SPI in MASTER mode with fosc/128
	SPCR |= (1<<SPE) | (1<<MSTR) | (1<<SPR0) | (1<<SPR1);
}

void spi_tx(char data)
{
	// sending data in register
	SPDR = data;
	
	// wait till TX completes
	while(!(SPSR & (1<<SPIF)));
	
}	


int main(void)
{
    while(1)
    {
        //TODO:: Please write your application code 
    }
}