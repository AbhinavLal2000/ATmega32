/*
 * Nokia_5110_LCD.c
 *
 * Created: 23-2-21 22:45:13
 *  Author: Abhinav
 */ 

#define F_CPU 1000000

#define BL		1	// BackLight PB1
#define DC		2	// DC        PB2
#define RST		3	// RESET     PB3
#define SS		4	// SS/CE     PB4
#define MOSI	5	// MOSI/DIN  PB5
#define MISO	6	// MISO      PB6
#define SCK		7	// SCK/CLK   PB7

#include <avr/io.h>
#include <util/delay.h>
#include "ascii_char.h"

void pinmode(void)
{
	// MOSI SCK RST DC BL SS as output, all others as input
	DDRB |= (1<<MOSI) | (1<<SCK) | (1<<RST) | (1<<DC) | (1<<BL) | (1<<SS);
}

void spi_init(void)
{
	// enable SPI in MASTER mode with fosc/128
	SPCR |= (1<<SPE) | (1<<MSTR) | (1<<SPR0) | (1<<SPR1);
	
	// SS HIGH
	PORTB |= (1<<SS);
}

void spi_tx(char data)
{
	// SS LOW
	PORTB &= ~(1<<SS);
	
	// sending data in register
	SPDR = data;
	
	// wait till TX completes
	while(!(SPSR & (1<<SPIF)));
	
	// SS HIGH
	PORTB |= (1<<SS);
	
}

void nokiaLCD_init(void)
{
	// set pins
	pinmode();
	
	// RST pattern
	PORTB &= ~(1<<RST);
	_delay_ms(10);
	PORTB |= (1<<RST);
	
	// DC LOW
	PORTB &= ~(1<<DC);
	
	// BL ON
	PORTB |= (1<<BL);
	
	// initialize SPI
	spi_init();
	
	// extended instruction set PD = 0, V = 0, H = 1
	spi_tx(0x21);
	
	// temp. coefficient TC1 = 0, TC0 = 1
	spi_tx(0x06);
	
	// set bias
	spi_tx(0x17);
	
	// V op contrast
	spi_tx(0x92);
	
	// basic instruction set PD = 0, V = 0, H = 0
	spi_tx(0x20);
	
	// normal display
	spi_tx(0x0C);
	
}

void nokiaLCD_pos(short ypos, short xpos)
{
	// DC LOW
	PORTB &= ~(1<<DC);
	
	// basic mode
	spi_tx(0x20);
	
	// making position
	spi_tx(0x40 | ypos);
	spi_tx(0x80 | xpos);
}

void nokiaLCD_print(short ypos, short xpos, char str[])
{
	int i = 0, j = 0;
	nokiaLCD_pos(ypos,xpos);
	
	// DC HIGH
	PORTB |= (1<<DC);
	
	// print string acc. to ASCII table in header
	while (str[i])
	{
		for (j=0;j<5;j++)
		{
			spi_tx(ASCII[str[i]-32][j]);
		}
		i++;
	}
	
	// DC LOW
	PORTB &= ~(1<<DC);
}	

void nokiaLCD_clear(void)
{
	// start from pos 0,0
	nokiaLCD_pos(0,0);
	
	// DC ON
	PORTB |= (1<<DC);
	
	// iterate 0x00 in whole display
	for (int i=0;i<504;i++)
	{
		spi_tx(0x00);
	}
	
	// DC OFF
	PORTB &= ~(1<<DC);
}

char* nums[60] = {"00","01","02","03","04","05","06","07","08","09"
				,"10","11","12","13","14","15","16","17","18","19"
				,"20","21","22","23","24","25","26","27","28","29"
				,"30","31","32","33","34","35","36","37","38","39"
				,"40","41","42","43","44","45","46","47","48","49"
				,"50","51","52","53","54","55","56","57","58","59"};

int main(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int y = 1;
	
	nokiaLCD_init();
	nokiaLCD_clear();
	nokiaLCD_print(3,15," STOPWATCH ");
	nokiaLCD_print(5,15,"     AL    ");
	nokiaLCD_print(y,58,"00");
	nokiaLCD_print(y,51,":");
	nokiaLCD_print(y,38,"00");
	nokiaLCD_print(y,31,":");
	nokiaLCD_print(y,18,"00");
	
	while (1)
	{
		for (i=0;i<60;i++)
		{
			nokiaLCD_print(y,58,nums[i]);
			_delay_ms(999);
			
			if (i == 59)
			{
				j++;
				nokiaLCD_print(y,38,nums[j]);
			}
			
			if (j == 59)
			{
				k++;
				nokiaLCD_print(y,18,nums[k]);
				j = 0;
			}
		}			
	}
}

