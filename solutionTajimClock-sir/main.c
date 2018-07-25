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
unsigned int sc = 0;


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
	//int hc=0,mc=0,sc=0;
	while (1) 
    {
		sprintf(line, "  %.2u : %.2u : %.2u", h, m, s);
		LCDGotoXY(1,1);
		LCDString(line);
		
		sprintf(line, "                ");
		LCDGotoXY(1,2);
		LCDString(line);
		
		if(bit_is_clear(PIND,1))
		{
			_delay_us(10); //debounce delay
			sc++;
			
			while(sc==1)
			{
				/*sprintf(line, "You Select SET");
				LCDGotoXY(1,1);
				LCDString(line);*/
				
				sprintf(line, "SET hour: ");
				LCDGotoXY(1,1);
				LCDString(line);
				
				sprintf(line, "%.2u",h);
				LCDGotoXY(11,2);
				LCDString(line);
				
				if(bit_is_clear(PIND,2))
				{
					while(bit_is_clear(PIND,2))
					_delay_us(10);
					h++;
				}
				
				else if(bit_is_clear(PIND,1))
				{
					_delay_us(10); //debounce delay
					sc=0;
				}
			}
		}
		
		else if (sc==2)
		{
				sprintf(line, "You Select SET");
				LCDGotoXY(1,1);
				LCDString(line);
				
				sprintf(line, "SET minute: ");
				LCDGotoXY(1,2);
				LCDString(line);
				
				while(bit_is_clear(PIND,2))
				{
					_delay_us(10);
					m++;
					sprintf(line, "%.2u",m);
					LCDGotoXY(13,2);
					LCDString(line);
				}
		}

			
	}
		  
return 0;
}

// on -- bit_is_clear(PIND,1) -- bit_is_clear(PIND,2)
// off -- bit_is_set(PIND,1) -- bit_is_set(PIND,2)
// set = pin 1 , change = pin 2