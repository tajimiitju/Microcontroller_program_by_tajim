/*
 * day22_mc.c
 *
 * Created: 11/19/2017 7:27:10 PM
 * Author : TAJIM
 */ 
#define  F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

#include "USART.h"

int main(void)
{
    /* Replace with your application code */
	DDRC |= 0xFF;
	USART_Init();
    while (1) 
    {
		char newData = USART_Receive_Byte();
		_delay_ms(3);
		if (newData>0)
		{
			if (newData == 'o')
			{
				newData = USART_Receive_Byte();
				if (newData == 'n')
				{
					USART_Transmit_String("Light ON\r\n");
					PORTC = 0xFF;	
				}
				else if(newData == 'f')
				{
					USART_Transmit_String("Light OFF\r\n");
					PORTC = 0x00;
				}
			}
			else if(newData == 'b')
			{
				USART_Transmit_String("Light OFF\r\n");
				PORTC = 0x00;
			}
		}
    }
}

