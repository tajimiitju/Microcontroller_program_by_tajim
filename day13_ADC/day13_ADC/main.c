/*
 * day13_ADC.c
 *
 * Created: 10/26/2017 7:59:31 PM
 * Author : User
 */

 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"


void Wait()
{
	uint8_t i;
	for(i=0;i<20;i++)
	_delay_loop_2(0);
}

int main()
{
	uint16_t adc_result=0;
	//Initialize ADC
	adc_init();
	DDRC |= ((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)); //Set Data_Direction_Resistor_Of_PORTC


	while(1)
	{
		adc_result = 0;
		adc_result=adc_read();           // Read Analog value from channel-0
		if (adc_result > 700)
		{
			PORTC &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
		}
		else
		{
			PORTC |= ((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
		}
		//Wait();
	}
	return 0;
}
