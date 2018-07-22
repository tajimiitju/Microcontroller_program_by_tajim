/*
 * Led0002.c
 *
 * Created: 18-10-2017 10:53:34 AM
 * Author : FAISAL KHAN
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>



int main(void)
{
    DDRC |= ((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));  //set C0-C7 as output
	DDRD &=~ ((1<<2)|(1<<3));											//set D2-D3 as input
	PORTC = 0b00000000;													//set portc to all low
	
    while (1) 
    {
		
		if (bit_is_clear (PIND,2))
		{
			PORTC = 0b11111111;
		}

		if (bit_is_clear (PIND,3))
		{
			PORTC = 0b00000000;
		}
		
    }
}

