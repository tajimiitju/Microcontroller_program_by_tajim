/*
 * day23_fuse_mc.c
 *
 * Created: 11/21/2017 7:22:25 PM
 * Author : User
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include "lcd.h"
char line[16];


int main(void)
{
	LCDInit();
	int i = 123;
	int j = 0;
	DDRD |= (1<<5)|(1<<4);
    
    eeprom_write_byte((uint8_t*)0,i);
    j = eeprom_read_byte((uint8_t*)0);
    
	while (1) 
    {
		sprintf(line,"Value is: %d",j);
		LCDGotoXY(1,1);
		LCDString(line);
    }
}

