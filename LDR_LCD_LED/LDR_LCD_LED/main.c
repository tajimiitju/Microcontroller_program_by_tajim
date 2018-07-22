/*
 * day_12_lcd.c
 *
 * Created: 10/24/2017 7:45:08 PM
 * Author : User
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "lcd.h"
#include "adc.h" 
char line[16];
//int adc_value = 0;

float adc_value = 0;
float adc_volt = 0;


int main(void)
{
	LCDInit(); // declare lcd data port and control port
    /* Replace with your application code */
	DDRC |= ((1<<0)|(1<<1)|(1<<2)|(1<<3));
	LCDInit(); //Initialize LCD Display
	adc_init();//Function call
	uint16_t adc_result=0;
	
	sprintf(line,"ADC Value : ");
	LCDGotoXY(1,1);
	LCDString(line);
	
	sprintf(line,"LIGH : ");
	LCDGotoXY(1,2);
	LCDString(line);
	
    while (1) 
    {
		adc_result = 0;
		adc_result=adc_read();           // Read Analog value from channel-0
		
		sprintf(line,"%d", adc_result);
		LCDGotoXY(13,1);
		LCDString(line);
		
		
		if (adc_result > 500)
		{
			PORTC &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3));
			sprintf(line,"OFF");
			LCDGotoXY(11,2);
			LCDString(line);
			
			_delay_ms(500);
		}
		else
		{
			PORTC |= ((1<<0)|(1<<1)|(1<<2)|(1<<3));
			sprintf(line,"ON");
			LCDGotoXY(11,2);
			LCDString(line);
			
			_delay_ms(500);
		}
    }
	//_delay_ms(50);
}

