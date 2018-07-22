
#ifndef F_CPU
#define F_CPU 8000000UL // 8 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA |= (1<<0); //Set Data_Direction_Resistor_Of_PORTA_Bit_0
	DDRD |= (1<<0); //Set Data_Direction_Resistor_Of_PORTD_Bit_0
	DDRD |= (1<<1); //Set Data_Direction_Resistor_Of_PORTD_Bit_1
	DDRD |= (1<<2); //Set Data_Direction_Resistor_Of_PORTD_Bit_2
	DDRD |= (1<<3); //Set Data_Direction_Resistor_Of_PORTD_Bit_3
	DDRD |= (1<<4); //Set Data_Direction_Resistor_Of_PORTD_Bit_4
	DDRD |= (1<<5); //Set Data_Direction_Resistor_Of_PORTD_Bit_5
	DDRD |= (1<<6); //Set Data_Direction_Resistor_Of_PORTD_Bit_6
	DDRD |= (1<<7); //Set Data_Direction_Resistor_Of_PORTD_Bit_7
	
	while(1)
	{
		PORTA |= (1<<0); //PORTA_Bit_0 goes to HIGH.
		PORTD |= (1<<0); //PORTD goes to HIGH.
		PORTD |= (1<<1); //PORTD goes to HIGH.
		PORTD |= (1<<2); //PORTD goes to HIGH.
		PORTD |= (1<<3); //PORTD goes to HIGH.
		PORTD |= (1<<4); //PORTD goes to HIGH.
		PORTD |= (1<<5); //PORTD goes to HIGH.
		PORTD |= (1<<6); //PORTD goes to HIGH.
		PORTD |= (1<<7); //PORTD goes to HIGH.
		_delay_ms(100); //Wait for 100ms
		
		PORTA &= ~(1<<0); //PORTA_Bit_0 goes to LOW.
		PORTD &= ~(1<<0); //PORTD goes to LOW.
		PORTD &= ~(1<<1); //PORTD goes to LOW.
		PORTD &= ~(1<<2); //PORTD goes to LOW.
		PORTD &= ~(1<<3); //PORTD goes to LOW.
		PORTD &= ~(1<<4); //PORTD goes to LOW.
		PORTD &= ~(1<<5); //PORTD goes to LOW.
		PORTD &= ~(1<<6); //PORTD goes to LOW.
		PORTD &= ~(1<<7); //PORTD goes to LOW.
		_delay_ms(100); //Wait for 100ms
	}
	

	return 0;
}