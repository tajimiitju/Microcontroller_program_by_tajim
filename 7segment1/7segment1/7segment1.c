/*
 * _7segment1.c
 *
 * Created: 4/22/2017 12:56:32 PM
 *  Author: Tajim
 */ 

/*
 * numbers_letters.c
 * Written in AVR Studio 5
 * Compiler: AVR GNU C Compiler (GCC)
 *
 * Created: 10/06/2011 05:31:57 PM
 * Author: AVR Tutorials
 * Website: www.AVR-Tutorials.com
 */ 
 
#include <avr/io.h>
 
#define F_CPU	4000000UL
#include <util/delay.h>
 
int main(void)
{
	DDRA = 0xFF;	// Configure port B as output
 
    while(1)
    {
        //TODO:: Please write your application code
 
		PORTA = 0b00111111;		// Display Number 0
		_delay_ms(500);		// Wait for 1s
		PORTA = 0b00110000;		// Display Number 1
		_delay_ms(500);		// Wait for 1s
		PORTA = 0b01011011;		// Display Number 2
		_delay_ms(500);		// Wait for 1s
		PORTA = 0b01001111;		// Display Number 3
		_delay_ms(500);		// Wait for 1s
		PORTA = 0b01100110;		// Display Number 4
		_delay_ms(500);		// Wait for 1s
		PORTA = 0b01101101;		// Display Number 5
		_delay_ms(500);		// Wait for 1s
		PORTA = 0b01111101;		// Display Number 6
		_delay_ms(500);		// Wait for 1s
		PORTA = 0b00000111;		// Display Number 7
		_delay_ms(500);		// Wait for 1s
		PORTA = 0b01111111;		// Display Number 8
		_delay_ms(500);		// Wait for 1s
		PORTA = 0b01101111;		// Display Number 9
		_delay_ms(500);		// Wait for 1s
		
 
		PORTA = 0b01110111;		// Display Letter A
		_delay_ms(500);		// Wait for 1s
		PORTA = 0b01111111;		// Display Number B
		_delay_ms(500);		// Wait for 1s
		PORTA = 0b00111001;		// Display Letter C
		_delay_ms(500);		// Wait for 1s
		PORTA = 0b00111111;		// Display Number D
		_delay_ms(500);		// Wait for 1s
		PORTA = 0b01111001;		// Display Letter E
		_delay_ms(500);		// Wait for 1s
		PORTA = 0b01110001;		// Display Letter F
		_delay_ms(500);		// Wait for 1s
 
    }
 
	return 0;
}

//40=a
//39=b
//38=c
//37=d
//36=e
//35=f
//36=g