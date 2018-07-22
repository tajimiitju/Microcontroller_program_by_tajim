/*
 * Led0001.c
 *
 * Created: 18-10-2017 10:12:59 AM
 * Author : FAISAL KHAN
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRC |= ((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
	
    while (1) 
    {
		PORTC = 0b11111111;
		_delay_ms(100);
		PORTC =0b00000000;
		_delay_ms(100);
		 
    }
}

