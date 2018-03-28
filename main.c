#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "myUSART.h"

#define GREEN_LED PORTB0
#define YELLOW_LED PORTB1
#define RED_LED PORTB2
#define WHITE_LED PORTB3

#define GREEN_SWITCH PORTD4
#define YELLOW_SWITCH PORTD5
#define RED_SWITCH PORTD6
#define WHITE_SWITCH PORTD7

void read_buttons();
void turn_LED();


//DDRB |= (1<<PORTB0)|(1<<PORTB1)|(1<<PORTB2)|(1<<PORTB3); //Using Pin 8 - 11 for the LEDS
//DDRD |= (1<<PORTD4)|(1<<PORTD5)|(1<<PORTD6)|(1<<PORTD7); //Using Pin 4 - 7 for the buttons

int main()
{
	unsigned char message;

	initUSART(USART_BAUDRATE);
	
	while(1)
	{
		message = USART_receive();
		USART_transmit(message);

	}

	return 0;
}

void read_buttons(){


}

void turn_LED(){


}