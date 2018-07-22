/*
 * Led0004.c
 *
 * Created: 19-10-2017 1:02:48 AM
 * Author : FAISAL KHAN
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>


unsigned int i;
unsigned int x=0;



int main(void)
{
	DDRC |= ((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)); //set C0-C7 as output
	DDRD &=~ ((1<<2)|(1<<3));										   //set D2-D3 as input
	
	while (1)
	{
		if (bit_is_clear (PIND,2))
		{
			for (i=0;i<=8;i++)
			{
				if (i==8)
				{
					i=0;
				}
				if (bit_is_clear(PIND,3))
				{
					break;
				}
				
				PORTC = (1<<i);
				_delay_ms (200);
				
			}
		}
		
		if (bit_is_clear (PIND,3))
		{
			for (i=0;i<=8;i++)
			{
				if (i==8)
				{
					i=0;
				}
				if (bit_is_clear(PIND,2))
				{
					break;
				}
				PORTC = (128>>i);
				_delay_ms (200);
			}
		}
		
	}
}