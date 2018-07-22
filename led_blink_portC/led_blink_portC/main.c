
#ifndef F_CPU
#define F_CPU 8000000UL // 8 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA |= (1<<0); //Set Data_Direction_Resistor_Of_PORTA_Bit_0
	DDRC |= ((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)); //Set Data_Direction_Resistor_Of_PORTD_Bit_7
	DDRD |= ((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)); //Set Data_Direction_Resistor_Of_PORTD_Bit_7
	int i=0;
	while(1)
	{
			for (i=0;i<=7;i++)
			{
				PORTA |= (1<<0); //PORTA_Bit_0 goes to HIGH.
				PORTC |= (1<<i); //PORTD goes to HIGH.
				PORTD |= (1<<i); //PORTD goes to HIGH.
				
				_delay_ms(30); //Wait for 100ms
				
				PORTA &= ~(1<<0); //PORTA_Bit_0 goes to LOW.
				PORTC &= ~(1<<i); //PORTD goes to LOW.
				PORTD &= ~(1<<i); //PORTD goes to LOW.
				
				_delay_ms(30); //Wait for 100ms
			}
					
	}
	

	return 0;
}