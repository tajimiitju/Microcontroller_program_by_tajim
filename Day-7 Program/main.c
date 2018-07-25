#include <avr/io.h>  
#include <util/delay.h> 

int main(void)
{
	DDRA |= (1<<0); //Set Data_Direction_Resistor_Of_PORTA_Bit_0 
	
	while(1)
	{
		PORTA |= (1<<0); //PORTA_Bit_0 goes to HIGH. 
		_delay_ms(100); //Wait for 100ms 
	 
		PORTA &= ~(1<<0); //PORTA_Bit_0 goes to LOW.
		_delay_ms(100); //Wait for 100ms
	}
	

	return 0;
}