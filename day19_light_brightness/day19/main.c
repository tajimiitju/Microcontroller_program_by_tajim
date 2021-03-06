/*
 * day19.c
 * day19_light_brightness
 * Created: 11/12/2017 7:37:05 PM
 * Author : TAJIM
 
 PWM____
 1. Pre-scaler selection
 2. wave form generation mode selection
 3. timer overflow interrupt function enable
 4. clear timer counter register value
 5. enable global iterrupt function sei()
 6. calculating value for ICR1
 7. writing ISR function
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
//#include "lcd.h"
#include <avr/interrupt.h>

int count = 0;


void Timer_0_Init(void)
{
	// TCCR1 for 16 bit
	TCCR1B |= (1<<CS10); // prescalling 64 -- 110
	TCCR1B |= (1<<CS11);
	TCCR1B &= ~(1<<CS12);
	
	// sob gula 0 korle wave form generation normal mode
	TCCR1A &= ~(1<<WGM10); //timer fast pwm mode 1110
	TCCR1A |= (1<<WGM11); // "
	TCCR1B |= (1<<WGM12); // "
	TCCR1B |= (1<<WGM13); // "
	
	TCCR1A &= ~(1<<COM1A0); //output compare mode, fast pwm non-inverting mode
	TCCR1A |= (1<<COM1A1); //output compare mode, fast pwm non-inverting mode
	TCCR1A &= ~(1<<COM1B0); //output compare mode, fast pwm non-inverting mode
	TCCR1A |= (1<<COM1B1); //output compare mode, fast pwm non-inverting mode
	
	TCNT1 = 0; // clear time counter
	//OCR1A = 31250;
	ICR1 = 2499; // 50hz 20ms 
	sei(); // set enable interrupt
}


int i=0;
int main(void)
{
	DDRD |= (1<<5);
	Timer_0_Init(); // initilizing timer = 0
	while (1) 
    {
	    for (i=0;i<=2499;i++)
	    {
		    OCR1A =i; 
		    _delay_ms(1);
		}
		for (i=2499;i>=0;i--)
		{
			OCR1A =i; 
			_delay_ms(1);
		}
	}
	return 0;
}

