
#define F_CPU 8000000UL //Using Internal 8MHz clock frequency 

#include <avr/io.h> //AVR Input Output Header file 
#include <util/delay.h>
#include <stdio.h> 

#include "adc.h" //ADC Header File 
#include "lcd.h" //LCD Header File 

char line[16];

int adc_value = 0;

int main(void)
{
	LCDInit(); //Initialize LCD Display 
	adc_init();//Function call
	
	sprintf(line,"ADC Value Is:");
	LCDGotoXY(1,1);
	LCDString(line);
	
	
	while(1)
	{
		adc_value = adc_read(); //ADC Read 
		
		sprintf(line,"%d", adc_value);
		LCDGotoXY(7,2);
		LCDString(line);
		
		_delay_ms(500);
	}

return 0; 
}