/*
 * day16_timer.c
 *
 * Created: 11/5/2017 7:42:43 PM
 * Author : Tajim
 Timer works 8bit:
 1. Pre-scaler selection
 2. wave form generation mode selection
 3. timer overflow interrupt function enable
 4. clear timer counter register value
 5. enable global iterrupt function sei()
 6. calculating value for OC0
 7. writing ISR function - Interrupt Service Routine
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

int count = 0;

void Timer_0_Init(void)
{
	// TCCR0 for 8 bit
	TCCR0 |= (1<<CS00); // no prescalling 100 
	TCCR0 &= ~(1<<CS01);
	TCCR0 &= ~(1<<CS02);
	
	TCCR0 &= ~(1<<WGM00); //timer normal mode
	TCCR0 &= ~(1<<WGM01); //timer normal mode
	
	TIMSK |= (1<<TOIE0); //overflow int enable
	TCNT0 = 0; // clear time counter
	sei();
}

ISR(TIMER0_OVF_vect)
{
	count++;
	// 8000000/256 =31250 - for 1 second
	if(count==31250)
	{
		PORTC ^= (1<<0);
		count = 0;
	}
}

int main(void)
{
	Timer_0_Init();
	DDRC |= (1<<0);
	while (1) 
    {
		
    }
	return 0;
}

