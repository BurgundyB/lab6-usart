#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE F_CPU / (USART_BAUDRATE * 16UL) - 1

void init_USART(unsigned int ubbr)
{
	//Set baud rate
	UBBR0H = (ubbr >> 8);
	UBBR0L = ubbr;

	//Enable RX and TX
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);

	//Set frame format
	UCSR0C = (1<<USBS0)|(3<<UCSZ00) //8data 2stop bit
}

void USART_tx ()

int main()
{
	while(1)
	{


	}

	return 0;
}
