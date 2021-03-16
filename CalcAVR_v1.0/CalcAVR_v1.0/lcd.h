/*
 * LCD.h
 *
 * Created: 14-05-2020 21:45:57
 *  Author: Abhinav Lal
 */ 

/*** Connections 16x2 LCD ***
 * PORTD to LCD Data lines D0-D7
 * Enable (E) pin to PINB0
 * RS pin to PINB1
 * RW to ground
 * VSS:ground VDD:+5V
 */ 
 
#define RS 1
#define E  0

void lcdInit()
{
	sendCmd(0x38); // LCD 8 bit mode
	sendCmd(0x01); // clear display
	sendCmd(0x0C); // display on cursor off
	sendCmd(0x80); // force cursor to line 1
}

void sendCmd(unsigned char cmd)
{
	PORTD = cmd;
	PORTB &= ~(1<<RS);
	PORTB |= (1<<E);
	_delay_ms(10);
	PORTB &= ~(1<<E);
	PORTB = 0;
}
void sendData(unsigned char data)
{
	PORTD = data;
	PORTB |= (1<<RS);
	PORTB |= (1<<E);
	_delay_ms(10);
	PORTB &= ~(1<<E);
	PORTD = 0;
}

void sendString(unsigned char *str)
{
	int i = 0;
	while(str[i]!='\0')
	{
		sendData(str[i]);
		i++;
	}
}




