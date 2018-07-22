/*
 * day_10_Ibterrupt.c
 *
 * Created: 10/19/2017 8:53:04 PM
 * Author : User
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
void Int_INT0(void);
int i;

int main(void)
{
    /* Replace with your application code */
	DDRC |= ((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)); //set C0-C7 as output
	
    Int_INT0();
	while (1) 
    {
		for(i=0;i<=7;i++)
		{
			PORTC = (1<<i);
			_delay_ms(200);
		}
    }
	return 0;
}

// INT0 = PD2
void Int_INT0(void)
{
	sei(); //enable global interrupt
	MCUCR &= ~(1<<ISC00); //
	MCUCR |= (1<<ISC01); //
	GICR |= (1<<INT0);// external interrupt 0 enabled
}

ISR(INT0_vect)
{
	for(i=7;i>=0;i--)
	{
		PORTC = (1<<i);
		_delay_ms(200);
	}
}
