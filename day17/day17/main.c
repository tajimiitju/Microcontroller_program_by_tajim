/*
 * day17.c
 *
 * Created: 11/7/2017 7:37:02 PM
 * Author : Tajim
 Timer works 16 bit:
 1. Pre-scaler selection (na korle 8Mhz e thake)
 2. wave form generation mode selection
 3. timer compare match
 4. clear timer counter register value
 5. enable global iterrupt function sei()
 6. calculating value for OC0
 7. writing ISR function
 
 */
 #define F_CPU 8000000UL
 #include <avr/io.h>
 #include <avr/interrupt.h>

 int count = 0;

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
	// 256 prescalling e 8000000/256 = 3125 ta bit dile 1 second
	sei(); // set enable interrupt
 }

 ISR(TIMER1_COMPA_vect)
 {
		PORTC ^= (1<<0);
		TCNT1 = 0; // clear time counter
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

