/*
 * GccApplication1.c
 *
 * Created: 4/21/2017 4:37:29 PM
 *  Author: Tajim
 */ 

#define F_CPU 1000000ul
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA=0xFF;
	PORTA=0x00;
    while(1)
    {
        //TODO:: Please write your application code 
		PORTA^=0xFF;
		_delay_ms(1000);
    }
}