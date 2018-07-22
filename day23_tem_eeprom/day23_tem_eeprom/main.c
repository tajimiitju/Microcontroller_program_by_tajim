/*
 * day23_tem_eeprom.c
 *
 * Created: 11/21/2017 8:53:51 PM
 * Author : TAJIM
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include "lcd.h"
#include "adc.h"
char line[16];
//int adc_value = 0;

float adc_value1 = 0;
float adc_value2 = 0;
float adc_volt1 = 0;
float adc_volt2 = 0;
float mili_volt = 0;
float t1 = 0;
float t2 = 0;
float temp = 0;

int address = 0;
int eeprom_value = 0;


int main(void)
{
	LCDInit();
	adc_init();
	//int i = 123;
	//int j = 0;
	DDRD |= (1<<5)|(1<<4);
	
	//eeprom_write_byte((uint8_t*)0,i);
	//j = eeprom_read_byte((uint8_t*)0);
	
	while (1)
	{
		adc_value1 = adc_read(0);
		adc_volt1 = ((adc_value1 * 2.56)/1024.00)*2;
		mili_volt = adc_volt1*1000;
		temp = mili_volt/10;
		_delay_ms(500);
		
		eeprom_write_byte((uint8_t*)address,temp);
			
		//eeprom_value = eeprom_read_byte((uint8_t*)address);
		address++;
		
		if(address>256) address = 0;
		
		sprintf(line,"Value is: %d",eeprom_value);
		LCDGotoXY(1,1);
		LCDString(line);
		
		sprintf(line,"Temp is: %f",temp);
		LCDGotoXY(1,2);
		LCDString(line);
	}
}

