/*
 * Function_Generator_v1.c
 *
 * Created: 23-09-2020 18:22:16
 *  Author: Abhinav
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int main(void)
{
	DDRB = 0b00000011;
	DDRD = 0xFF;
	DDRC = 0b00011100;
	int i = 0;
	int j = 0;
	int o = 0;
	lcdInit();
	sendString("Function");
	sendCmd(0xC0);
	sendString("Generator v1.0");
	_delay_ms(1000);
	sendCmd(0x01);
	sendCmd(0x80);
	sendString("Generator: ");
	sendCmd(0xC0);
	sendString("Wave: ");
	
	while(1)
	{
		if (i == 2)
		{
			i = 0;
		}
		if (j == 2)
		{
			j = 0;
		}
		else if (PINC & (1<<0))
		{
			if (i == 1)
			{	
				sendCmd(0x80);
				for (int k=0;k<=10;k++)
				{
					sendCmd(0x14);
				}
				sendString("ON ");
				PORTC = 0b00000100;
				i++;
				o = i;
				
			}
			else if (i == 0)
			{
				sendCmd(0x80);
				for (int l=0;l<=10;l++)
				{
					sendCmd(0x14);
				}
				sendString("OFF");
				PORTC = 0;
				i++;
				o = i;
			}
							
		}
		
		else if (PINC & (1<<1))
		{
			if (j == 1)
			{
				sendCmd(0xC0);
				for (int m=0;m<=5;m++)
				{
					sendCmd(0x14);
				}
				sendString("Square");
				if (o == 1)
				{
					PORTC = 0;
				}
				else if (o == 2)
				{
					PORTC = 0b00001100;
				}
				j++;
			}
			else if (j == 0)
			{
				sendCmd(0xC0);
				for (int n=0;n<=5;n++)
				{
					sendCmd(0x14);
				}
				sendString("Sine  ");
				if (o == 1 )
				{
					PORTC = 0;
				}
				else if (o == 2)
				{
					PORTC = 0b00010100;
				}
				j++;
			}
		}
	}
}	