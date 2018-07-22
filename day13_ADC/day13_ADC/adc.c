/*
 * adc.c
 *
 * Created: 10/29/2017 8:26:13 AM
 *  Author: User
 */ 

// 1. reference voltage selection
// 2. prescaller seletion
// 3. Enable adc
// 4. channel selection
// 5. adc data order
// 6. start conversion
// 7. read adc data


#include <avr/io.h>
#include "adc.h"

void adc_init(void)
{
	ADMUX |= (1<<REFS0);                         // For Aref=AVcc;
	ADMUX &= ~(1<<REFS1);                
	
	ADCSRA &= ~(1<<ADPS0); //Prescalar div factor =64 - 011
	ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1); //Prescalar div factor =64 - 011
}

uint16_t adc_read(void)
{
	//5 channel selection
	ADMUX &= ~(1<<MUX0);
	ADMUX &= ~(1<<MUX1);
	ADMUX &= ~(1<<MUX2);
	ADMUX &= ~(1<<MUX3);
	
	//6. start conversion
	ADCSRA |= (1<<ADSC);
	while (bit_is_set(ADCSRA,ADSC));
	
	
	//read adc data
	return ADCW;
}

/*
uint16_t adc_read(uint8_t ch)
{
	//Select ADC Channel ch must be 0-7
	ch=ch&0b00000111;
	ADMUX|=ch;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));

	//Clear ADIF by writing one to it
	//Note you may be wondering why we have write one to clear it
	//This is standard way of clearing bits in io as said in datasheets.
	//The code writes '1' but it result in setting bit to '0' !!!

	ADCSRA|=(1<<ADIF);

	return (ADC);
}

*/