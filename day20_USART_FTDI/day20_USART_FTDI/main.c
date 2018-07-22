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
 
 PWM____
 1. Pre-scaler selection
 2. wave form generation mode selection
 3. timer overflow interrupt function enable
 4. clear timer counter register value
 5. enable global iterrupt function sei()
 6. calculating value for ICR1
 7. writing ISR function
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
	}
	return 0;
}

