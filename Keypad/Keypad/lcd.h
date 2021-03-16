/*
 * LCD.h
 *
 * Created: 14-05-2020 21:45:57
 *  Author: Abhinav Lal
 */ 
 
#define RS 1
#define E  0

void lcdInit()
{
	sendCmd(0x38); // LCD 8 bit mode
	sendCmd(0x01); // clear display
	sendCmd(0x0C); // display on cursor off
}

void sendCmd(unsigned char cmd)
{
	PORTD = cmd;
	PORTC &= ~(1<<RS);
	PORTC |= (1<<E);
	_delay_ms(20);
	PORTC &= ~(1<<E);
	PORTC = 0;
}
void sendData(unsigned char data)
{
	PORTD = data;
	PORTC |= (1<<RS);
	PORTC |= (1<<E);
	_delay_ms(20);
	PORTC &= ~(1<<E);
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




