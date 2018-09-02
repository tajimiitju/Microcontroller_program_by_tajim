
/*
 * day20_USART_FTDI.c
 *
 * Created: 11/14/2017 7:32:51 PM
 * Author : TAJIM
 */ 


/*
 * day19.c
 * day19_light_brightness
 * Created: 11/12/2017 7:37:05 PM
 * Author : TAJIM
 
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "USART.h"
#include <avr/interrupt.h>

int main(void)
{
	USART_Init();
	//USART_Transmit_Byte('A');
	while (1)
	{
		USART_Transmit_String("Hello World!\r\n"); // \r for carriage return
		_delay_ms(500);
	}
	return 0;
}

