/*
 * atmega8_led_switch.c
 *
 * Created: 4/21/2017 6:24:41 PM
 *  Author: Tajim
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
//Define functions
//======================
void ioinit(void);
void led_on(void);
void led_off(void);
//======================
int main (void)
{
	ioinit(); //Setup IO pins and defaults
	while (1)
	{
		if (bit_is_clear(PINC, 4))
		{
			for (int i=0;i<6;i++)
			{
				if (i>0)
				{
					_delay_ms(500);
					led_on();
					_delay_ms(500);
					led_off();
				}
			}
		}
	}
}

void ioinit (void)
{
	DDRC = 0b11101111; //Pin 27 of MCU as input
	PORTC = 0b00010000; //Enable internal pullup of pin 27
}

void led_on(void)
{
	PORTC |= _BV(PC5); //Pin 28 of MCU as output
}

void led_off(void)
{
	PORTC &= ~_BV(PC5);
}