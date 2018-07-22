/*
 * USART.c
 *
 * Created: 11/14/2017 7:42:01 PM
 *  Author: TAJIM
 */ 
#define  F_CPU 8000000UL
#include <avr/io.h>
#include "USART.h"
#define UART_BAUDRATE 9600
#define UART_UBBR_VALUE ((F_CPU / 16 / UART_BAUDRATE) - 1)

void USART_Init(void)
{
	/*Set baud rate */
	//UBRRH = (unsigned char)(baud>>8);
	//UBRRL = (unsigned char)baud;
	UBRRH = (UART_UBBR_VALUE >> 8); //8 bar right shift kore 10 bit er prothom dutake MSB te rakhlo
	UBRRL = UART_UBBR_VALUE; //last 8ta bose jabe
	
	//Enable receiver and transmitter 
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(1<<UCSZ0)|(1<<UCSZ1);
}


void USART_Transmit_Byte( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE))); // bit in not set ... checking
	//while UDRE bit of UCSRA is clear
	
	/* Copy 9th bit to TXB8 
	UCSRB &= ~(1<<TXB8);
	
	if ( data & 0x0100 )
	{
		UCSRB |= (1<<TXB8);		
	}
	*/
	
	/* Put data into buffer, sends the data */
	UDR = data;
}

unsigned char USART_Receive_Byte( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
	return UDR;
}

void USART_Transmit_String(char *string)
{
	while(*string)
	{
		USART_Transmit_Byte(*string++);
	}
}