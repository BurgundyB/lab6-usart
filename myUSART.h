#ifndef myUSART_H
#define myUSART_H

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE F_CPU / (USART_BAUDRATE * 16UL) - 1

void initUSART(unsigned int);
void USART_transmit(unsigned char);
unsigned char USART_receive();

#endif