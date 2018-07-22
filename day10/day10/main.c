
// toggle switch

#ifndef F_CPU
#define F_CPU 8000000UL // 8 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRD &= ~(1<<2); // 2 as input
	DDRC |= (1<<0);// 0 as output
    while (1) 
    {
		if(bit_is_clear(PIND,2))
		{
			while(bit_is_clear(PIND,2))
			{
				
			}
			_delay_us(10);
			PORTC ^= (1<<0); //toggle portc xor 1
		}
    }
}

