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
    while (1) 
    {
		LCDInit(); //Initialize LCD Display
		adc_init();//Function call
		
		sprintf(line,"ADC Value:");
		LCDGotoXY(1,1);
		LCDString(line);
		
		sprintf(line,"ADC Volt:");
		LCDGotoXY(1,2);
		LCDString(line);
		
		
		while(1)
		{
			adc_value = adc_read(); //ADC Read
			adc_volt = ((adc_value*5)/1024.0);
			
			sprintf(line,"%.2f", adc_value);
			LCDGotoXY(11,1);
			LCDString(line);
			
			sprintf(line,"%.2f", adc_volt);
			LCDGotoXY(11,2);
			LCDString(line);
			
			_delay_ms(50);
		}

		
    }
}

