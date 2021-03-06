#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "myUSART.h"

 char readButtons();
void writeLED( char);
 char msg;


	int main()
{
	DDRB = 0xFF; //Using Pin 8 - 11 for the LEDS
	DDRC = 0xF0; //Using Pin 4 - 7 for the buttons

	initUSART(USART_BAUDRATE);

	while(1)
	{
		msg = readButtons();
		USART_transmit(msg);
		msg = USART_receive();
		writeLED(msg);
	}
	return 0;
}


//////// accept input from buttons ////////
char readButtons(){
	 char num;  //read port C input value
	 num = PINC;
	 num = ~num;
	 num &= 0x0F;
	 return num;
}

/////// display number to LEDs /////////
void writeLED( char num){
	PORTB = num; //display number
	_delay_ms(10);
	PORTB = 0x00;
}

