
#include <avr/io.h> //AVR Input-Output Header File 
#include "adc.h" //ADC Header File 

void adc_init(void)
{
	//01. Reference voltage selection  
	ADMUX |= (1<<REFS0); //AVCC with external capacitor at AREF pin
	ADMUX &= ~(1<<REFS1); //AVCC with external capacitor at AREF pin
	
	//02. Prescaler selection 
	ADCSRA &= ~(1<<ADPS0); //Division Factor 64 for 125KHz ADC_Frequency 
	ADCSRA |= (1<<ADPS1); //Division Factor 64 for 125KHz ADC_Frequency
	ADCSRA |= (1<<ADPS2); //Division Factor 64 for 125KHz ADC_Frequency
	
	//03. Enable ADC 
	ADCSRA |= (1<<ADEN); //ADC Enable 
	
	//04. ADC Data order 
	ADMUX &= ~ (1<<ADLAR); //ADC Data resister data in type selection 
}


uint16_t adc_read(void)
{
	//05. Channel Selection 
	ADMUX &= ~(1<<MUX0); //ADC_Channel_0 Select 
	ADMUX &= ~(1<<MUX1); //ADC_Channel_0 Select
	ADMUX &= ~(1<<MUX2); //ADC_Channel_0 Select
	ADMUX &= ~(1<<MUX3); //ADC_Channel_0 Select
	
	//06. Start conversion 
	ADCSRA |= (1<<ADSC); //ADC Start Conversion 
	
	while(bit_is_set(ADCSRA, ADSC)); //Wait until adc conversion is completed 
	
	//07. Read ADC data 
	return ADCW;
}