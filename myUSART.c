#include <avr/io.h>
#include <avr/interrupt.h>
#include "myUSART.h"

////////// initialize USART ////////////
void initUSART() //pass USART_BAUDRATE
{
	//Set baud rate
	UBRR0H = (BAUD_PRESCALE >> 8);
	UBRR0L = BAUD_PRESCALE;

	//Enable RX and TX
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);

	//Set frame format
	UCSR0C = (1<<USBS0)|(3<<UCSZ00); //8data 2stop bit
}


//////////// USART transmit /////////////
void USART_transmit (unsigned char data)
{
	//wait for Data Register Empty Flag to be set
	while ((UCSR0A & (1 << UDRE0)) == 0){};

	//transmit data
	UDR0 = data;
}

/////////// USART receive ////////////////
unsigned char USART_receive ()
{
	//wait for Receive Complete Flag to be set
	while ((UCSR0A & (1 << RXC0)) == 0){}; 

	//return received data
	return UDR0;
}

