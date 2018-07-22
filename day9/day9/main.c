
#ifndef F_CPU
#define F_CPU 8000000UL // 8 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//DDRC |= ((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)); //Set Data_Direction_Resistor_Of_PORTD_Bit_7
	DDRA &= ~(1<<0);
	DDRC |= (1<<0);
	
	while(1)
	{
		
		if(bit_is_clear(PIND,2))
		{
			_delay_us(10);
			PORTC |= (1<<0);
		}
		else
		{
			PORTC &= ~(1<<0);
		}
		
		
	}
	
	return 0;
}