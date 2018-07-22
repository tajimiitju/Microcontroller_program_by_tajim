/*
 * USART.h
 *
 * Created: 11/14/2017 7:38:22 PM
 *  Author: TAJIM
 */ 

void USART_Init(void);

void USART_Transmit_Byte(unsigned char data);

unsigned char USART_Receive_Byte( void );

void USART_Transmit_String(char *string);
