/*
 * bluetooth_hc05.c
 *
 * Created: 12/2/2017 2:18:45 PM
 * Author : Tajim
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "USART.h"

//HC05 connections:
// atmega32 PD0/RXD/14 = hc05 TXD
// atmega32 PD1/TXD/15 = hc05 RXD
// no connection need in STATE and EN pin

int main(void)
{
	DDRC |= ((1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)); //Set Data_Direction_Resistor_Of_PORTD_Bit_7
	
	USART_Init();//Initializing UART
	
	while(1)
	{	
		unsigned char BT_Data = receiveByte();
		if(BT_Data == 'a')
		{			
			// port c 1 on
			PORTC |= (1<<1);
		}
		else if(BT_Data == 'b')
		{
			PORTC &= ~(1<<1);
		}
		if(BT_Data == 'c')
		{
			PORTC |= (1<<2);
		}
		else if(BT_Data == 'd')
		{
			PORTC &= ~(1<<2);
		}
		if(BT_Data == 'e')
		{
			PORTC |= (1<<3);
		}
		else if(BT_Data == 'f')
		{
			PORTC &= ~(1<<3);
		}
	}
}
