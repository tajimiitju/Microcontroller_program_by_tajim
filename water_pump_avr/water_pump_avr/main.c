/*
 * water_pump_avr.c
 *
 * Created: 10/26/2017 1:40:45 PM
 * Author : TAJIM
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "lcd.h"
char line[16];

int main(void)
{
	
	DDRD |= (1<<0); // port d 0 as output

	LCDInit(); // declare lcd data port and control port
	/* Replace with your application code */
	while (1)
	{
		sprintf(line,"Auto Water Pump");
		LCDGotoXY(1,1);
		LCDString(line);
		// D1 = full ; D2 = Mid : D3 = quarter
		
		//bit_is_clear(PIND,2)
		
		if (bit_is_set(PIND,1) && bit_is_set(PIND,2) && bit_is_set(PIND,3))
		{
			sprintf(line,"Empty. Motor-ON");
			LCDGotoXY(1,2);
			LCDString(line);
			_delay_ms(100);
			PORTD |= (1<<0); // port d 0 = motor on

		}
		if(bit_is_set(PIND,1) && bit_is_set(PIND,2) && bit_is_clear(PIND,3))
		{
			sprintf(line,"Qarter. Motor-ON");
			LCDGotoXY(1,2);
			LCDString(line);
			_delay_ms(100);
			PORTD |= (1<<0); // port d 0 = motor on

		}
		if(bit_is_set(PIND,1) && bit_is_clear(PIND,2) && bit_is_clear(PIND,3))
		{
			sprintf(line,"Midium. Motor-ON");
			LCDGotoXY(1,2);
			LCDString(line);
			_delay_ms(100);
			PORTD |= (1<<0); // port d 0 = motor on
			
		}
		if (bit_is_clear(PIND,1) && bit_is_clear(PIND,2) && bit_is_clear(PIND,3))
		{
			sprintf(line,"Full. Motor-OFF");
			LCDGotoXY(1,2);
			LCDString(line);
			_delay_ms(100);
			PORTD &= ~(1<<0); // port d 0 = motor off

		}
		
	}
}

