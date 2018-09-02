#define F_CPU 8000000UL //Using Internal 8MHz Clock 
#include <avr/io.h> //AVR Input-Output Header File 

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE ((F_CPU / 16 / USART_BAUDRATE) - 1) 


void USART_Init()
{
	UCSRB = (1 << RXEN ) | (1 << TXEN );					//Turn on the transmission and reception circuitry
	UCSRC = (1 << URSEL ) | (1 << UCSZ1 ) | (1 << UCSZ0 );	// Use 8- bit character sizes and It is read as zero when reading UBRRH. So at first set it to 1. 
	
	UBRRH = (BAUD_PRESCALE >> 8);							//Load upper 8- bits of the baud rate value into the high byte of the UBRR register
	UBRRL = BAUD_PRESCALE;									//Load lower 8 - bits of the baud rate value into the low byte of the UBRR register	
}

void transmitByte(unsigned char data)
{
	while((UCSRA & (1 << UDRE)) == 0) {}; //Do nothing until UDR is ready for more data to be written to it
	
	UDR = data;
}

unsigned char receiveByte(void)
{
	char data;
	
	while((UCSRA & (1 << RXC)) == 0) {}; //Do nothing until data have been received and is ready to be read from UDR
	
	data = UDR;
	
	return(data);
}


void transmitString(char *string)
{
	while(*string)
	{
		transmitByte(*string++);
	}
}