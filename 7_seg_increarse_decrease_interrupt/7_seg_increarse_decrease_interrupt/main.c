
#ifndef F_CPU
#define F_CPU 8000000UL // 8 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB |= ((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)); //Set as output
	int segment[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
	//					0	,1	 , 2   ,3	 ,4    ,5	 ,6	   ,7	 ,8	   ,9	 ,10=A	,11=B ,12=C,13=D ,14=E ,15=F
	int i = 0;
	while(1)
	{
			//PORTB = segment[i];
					
			if(i<0 || i>15)
			{
				i=0;
			}
			
			if(bit_is_clear(PIND,3))
			{
				PORTB = segment[i];
				_delay_ms(70);
				i++;	
			}
			else if(bit_is_clear(PIND,2))
			{
				i--;
				if(i<0)
				{
					i=15;
				}
				PORTB = segment[i];
				_delay_ms(70);
			}
	}
	return 0;
}

