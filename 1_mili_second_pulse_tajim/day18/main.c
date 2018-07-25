/*
 * 1_mili_second_pulse_tajim
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
#include <avr/interrupt.h>
char line[16];
int count = 0;

unsigned int h = 0;
unsigned int m = 0;
unsigned int s = 0;


void pwm_init(void)
{
	// TCCR1 for 16 bit
	TCCR1B |= (1<<CS10); // prescalling 64 -- 011
	TCCR1B |= (1<<CS11);
	TCCR1B &= ~(1<<CS12);
	
	// sob gula 0 korle wave form generation normal mode
	TCCR1A &= ~(1<<WGM10); //timer fast pwm mode 1110
	TCCR1A |= (1<<WGM11); // "
	TCCR1B |= (1<<WGM12); // "
	TCCR1B |= (1<<WGM13); // "
	
	TCCR1A &= ~(1<<COM1A0); //output compare mode, fast pwm non-inverting mode
	TCCR1A |= (1<<COM1A1); //output compare mode, fast pwm non-inverting mode
	
	TCNT1 = 0; // clear time counter
	ICR1 = 2499; // 50hz 20ms =>Top
	// pwm frequency = F_CPU/(N*(1+Top)) => Top = 8000000/(64*50) - 1 =2499
	// N = 64 (prescalling) , pwm frequency = 50 HZ korte chai
	// time T = 1/f = 1/50 = .02 sec = 20 ms
	sei(); // set enable interrupt
}

int main(void)
{
	DDRD |= (1<<5);
	
	pwm_init(); // initilizing timer = 0
	while (1) 
    {
		OCR1A = 125; // 1mili sec 125hz
		// 8000000/64 = 125000 because 64 prescalling
		// 125000 ta pulse dile 1 second
		// 125000/1000 = 125 ta pulse dile 1 mili second
	}
	return 0;
}

