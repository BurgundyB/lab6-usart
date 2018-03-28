#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "myUSART.h"
#include "blueLED.h"

#define GREEN_LED		PORTB0
#define YELLOW_LED		PORTB1
#define RED_LED 		PORTB2
#define WHITE_LED 		PORTB3

#define GREEN_SWITCH 	PORTD4
#define YELLOW_SWITCH 	PORTD5
#define RED_SWITCH 		PORTD6
#define WHITE_SWITCH 	PORTD7



void wait()
{
	int i = 0;
	for (i=0;i<2;i++)
		_delay_ms(250);
}



void initPorts()
{
	DDRD &= 0x0F; //set high nybble as input while leaving RX TX untouched
	DDRD |= 0x0C; //set PD3 and PD2 to a known state (as output)
				  //to prevent unknown reading if in input mode
	DDRB |= 0xFF; //set as output
}


unsigned char readButton()
{
	unsigned char num;
	num = PIND; //read value from port D
	num = ~num; //1s complement to use only IF pins are normally powered
	num = num >> 4; //bitshift to discard low nybble, pad high nybble with 0s
	wait();
	return num;
}



void writeLED(unsigned char num)
{
	PORTB = num; //display received number
	wait();
	PORTB = 0x00; //turn LEDs off
	wait();
}





int main()
{
	unsigned char msg;
	initPorts();
	initUSART();
	LED_ON;
	wait();
	LED_OFF;

	while(1)
	{
		//while()
		//msg = USART_receive();
		//USART_transmit(msg);

		while(PIND == 0xF0)
		{
			LED_ON;
			wait();
			LED_OFF;
		}

		msg = readButton();
		USART_transmit(msg);
		//(TO DO LATER: combine two nybbles in one byte by discarding the 0s)
		
		msg = USART_receive();
		writeLED(msg);
		
		{
			LED_ON;
			wait();
			LED_OFF;
		}


	}

	return 0;
}



















