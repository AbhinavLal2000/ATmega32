/*
 * LCD.h
 *
 * Created: 14-05-2020 21:45:57
 *  Author: Abhinav Lal
 */ 
 
#define RS 0
#define E  1

void lcdInit()
{
	sendCmd(0x38); // LCD 8 bit mode
	sendCmd(0x01); // clear display
	sendCmd(0x0C); // display on cursor off
}

void sendCmd(unsigned char cmd)
{
	PORTD = cmd;
	PORTB &= ~(1<<RS);
	PORTB |= (1<<E);
	_delay_ms(20);
	PORTB &= ~(1<<E);
	PORTB = 0;
}
void sendData(unsigned char data)
{
	PORTD = data;
	PORTB |= (1<<RS);
	PORTB |= (1<<E);
	_delay_ms(20);
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




