/*
 * LED_BLINK.c
 *
 * Created: 4/21/2017 11:44:00 AM
 *  Author: Tajim
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xFF; //Nakes PORTC as Output
	while(1) //infinite loop
	{
		PORTC = 0xFF; //Turns ON All LEDs
		_delay_ms(100); //1 second delay
		PORTC= 0x00; //Turns OFF All LEDs
		_delay_ms(100); //1 second delay
	}
}