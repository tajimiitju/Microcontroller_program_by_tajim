/*
 * GccApplication1.c
 *
 * Created: 4/21/2017 4:37:29 PM
 *  Author: Tajim
 */ 
#ifndef F_CPU
#define F_CPU 1000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB=0xFF;
	DDRD=7;
	PORTD=7;
	PORTB=0x00;
    while(1)
    {
        //TODO:: Please write your application code 
		PORTB=0xFF;
		_delay_ms(2000);
		PORTB=0x00;
		_delay_ms(2000);
    }
	return 0;
}