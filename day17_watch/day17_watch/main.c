/*
 * day17_watch.c
 *
 * Created: 11/7/2017 8:30:58 PM
 * Author : User
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "lcd.h"
#include <avr/interrupt.h>
char line[16];
int count =0;

unsigned int h = 0;
unsigned int m = 0;
unsigned int s = 0;


void Timer_0_Init(void)
{
	// TCCR1 for 16 bit
	TCCR1B &= ~(1<<CS10); // prescalling 256 - 001
	TCCR1B &= ~(1<<CS11);
	TCCR1B |= (1<<CS12);
	
	// sob gula 0 korle wave form generation normal mode
	TCCR1B &= ~(1<<WGM10); //timer normal mode
	TCCR1B &= ~(1<<WGM11); //timer normal mode
	TCCR1B &= ~(1<<WGM12); //timer normal mode
	TCCR1B &= ~(1<<WGM13); //timer normal mode
	
	TIMSK |= (1<<OCIE1A); //output compare match enable
	TCNT1 = 0; // clear time counter
	OCR1A = 31250;
	sei(); // set enable interrupt
}

ISR(TIMER1_COMPA_vect)
{
	s++;
	if(s>=60)
	{
		s=0;
		m++;
	}
	else if(m>=60)
	{
		m=0;
		h++;
	}
	else if(h>=12)
	{
		h=0;
	}
	TCNT1 = 0; // clear time counter
}


int main(void)
{
	LCDInit();
	Timer_0_Init(); // initilizing timer = 0
	while (1) 
    {
		/*
		
		s++;
		if(s>=60)
		{
			s=0;
			m++;
		}
		else if(m>=60)
		{
			m=0;
			h++;
		}
		else if(h>=12)
		{
			h=0;
		}
		
		*/
		
		sprintf(line, "%.2u : %.2u : %.2u", h, m, s);	
		LCDGotoXY(3,1);
		LCDString(line);
    
	}
	return 0;
}

