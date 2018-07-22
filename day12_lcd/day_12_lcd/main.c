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
char line[16];

int main(void)
{
	LCDInit(); // declare lcd data port and control port
    /* Replace with your application code */
    while (1) 
    {
		sprintf(line,"Hello TAJIM !");
		LCDGotoXY(1,1);
		LCDString(line);
		int i;
		for (i=1;i<=10;i++)
		{
			sprintf(line,"%d*",i);
			
			LCDGotoXY(i,2);
			LCDString(line);
			_delay_ms(500);	
		}
		
    }
}

