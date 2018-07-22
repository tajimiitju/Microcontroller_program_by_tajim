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


/*Includes delay.h header file which defines two functions, _delay_ms (millisecond delay) and _delay_us (microsecond delay)*/

/*Timer Counter 0 Function Declarations*/
void set_timercounter0_mode(unsigned char mode);
void set_timercounter0_prescaler(unsigned char prescaler_value);
void set_timercounter0_output_mode(unsigned char output_mode);
void set_timercounter0_compare_value(unsigned char compare_value);

/*Timer Counter 2 Function Declarations*/
void set_timercounter2_mode(unsigned char mode);
void set_timercounter2_prescaler(unsigned char prescaler_value);
void set_timercounter2_output_mode(unsigned char output_mode);
void set_timercounter2_compare_value(unsigned char compare_value);



int main(void)
{
	
	USART_Init();//Initializing UART............
	
	DDRB=0x08; //PB3 pin of PORTB is declared output (PWM1 pin of DC Motor Driver is connected)

	DDRD=0x80; //PD7 pin of PORTD is declared output (PWM2 pin of DC Motor Driver is connected) 
	
	DDRC=0x0f; //PC0,PC1,PC2 and PC3 pins of PortC are declared output ( i/p1,i/p2,i/p3 and i/p4 pins of DC Motor Driver are connected)
	//DDRC = 0xFF; // all c as output
	set_timercounter0_mode(3); //Timer counter 0 is set to fast pwm mode*/

	set_timercounter0_prescaler(4); //Timer counter 0 frequency is set to 3.90625KHz

	set_timercounter0_output_mode(2); //Timer counter 0 output mode is set  to non-inverting mode
	
	set_timercounter2_mode(3); //Timer counter 2 is set to fast pwm mode
	
	set_timercounter2_prescaler(4); //Timer counter 2 frequency is set to 3.90625KHz 
	
	set_timercounter2_output_mode(2); //Timer counter 2 output mode is set to non-inverting mode*
	
	while(1)
	{
		
		
		
		/*
		if(bit_is_clear(PIND,2))
		{
			PORTC=0x0a;
			set_timercounter0_compare_value(200);//OCR0 register value is set to 180
			
			set_timercounter2_compare_value(200);//OCR2 register value is set to 180
			//d2 pressed Robot moves in forward direction for with medium speed	
		}
		
		if(bit_is_clear(PIND,3))
		{
			PORTC=0x0a;
			set_timercounter0_compare_value(120); //OCR2 register value is set to 100
			
			set_timercounter2_compare_value(120); //OCR2 register value is set to 100
			//D3 pressed Robot moves in forward direction for 4s with low speed
		}
		*/
		unsigned char BT_Data = receiveByte();
		
		// fast forward
		if(BT_Data == 'a')
		{			
			// left back
			//PORTC |= (1<<0);
			//PORTC &= ~(1<<1);
			
			// left forward
			PORTC |= (1<<1);
			PORTC &= ~(1<<0);
			
			// right forward
			PORTC |= (1<<3);
			PORTC &= ~(1<<2);
			
			// right back
			//PORTC |= (1<<2);
			//PORTC &= ~(1<<3);
			
			set_timercounter0_compare_value(255);//OCR0 register value is set to 180
			
			set_timercounter2_compare_value(255);//OCR2 register value is set to 180
			//d2 pressed Robot moves in forward direction for with medium speed
		}
		// slow forward
		else if(BT_Data == 'b')
		{
			PORTC=0x0a; //1010
			PORTC |= (1<<5);
			set_timercounter0_compare_value(180); //OCR2 register value is set to 100
			
			set_timercounter2_compare_value(180); //OCR2 register value is set to 100
			//D3 pressed Robot moves in forward direction for 4s with low speed
		}
		// right
		else if(BT_Data == 'c')
		{
			//PORTC=0x09; // 1001
			// right forward
			PORTC |= (1<<3);
			PORTC &= ~(1<<2);
			set_timercounter0_compare_value(255);
			set_timercounter2_compare_value(255);
		}
		// left
		else if(BT_Data == 'd')
		{
			//PORTC=0x04; // 0110
			//PORTC |= (1<<5);
			// left forward
			PORTC |= (1<<1);
			PORTC &= ~(1<<0);
			set_timercounter0_compare_value(255);
			set_timercounter2_compare_value(255);
		}
		// backward
		else if(BT_Data == 'e')
		{
			PORTC=0x05; // 0101
			set_timercounter0_compare_value(255); 
			set_timercounter2_compare_value(255);
		}
		//off - stop
		else if(BT_Data == 'f')
		{
			PORTC &= ~(1<<5);
			PORTC &= ~(1<<0);
			PORTC &= ~(1<<1);
			PORTC &= ~(1<<2);
			PORTC &= ~(1<<3);
		}
	}
}
/*End of program*/


/*Timer Counter 0 Function Definitions*/
void set_timercounter0_mode(unsigned char mode)
{
	if(mode==0)
	{
		TCCR0|=0;
	}
	else if(mode==1)
	{
		TCCR0|=_BV(WGM00);
	}
	else if(mode==2)
	{
		TCCR0|=_BV(WGM01);
	}
	else if(mode==3)
	{
		TCCR0|=_BV(WGM00)|_BV(WGM01);
	}
	else
	;

}

void set_timercounter0_prescaler(unsigned char prescaler_value)
{
	TCCR0&=~(0x07);
	TCCR0|=prescaler_value; // = 4 = 100 = no prescall or 256
}

void set_timercounter0_output_mode(unsigned char output_mode)
{
	TCCR0|=output_mode<<4;
}

void enable_timercounter0_interrupt(unsigned char interrupt_type)
{
	TIMSK|=1<<interrupt_type;
}

void disable_timercounter0_interrupt(unsigned char interrupt_type)
{
	TIMSK&=~(1<<interrupt_type);
}

void set_timercounter0_compare_value(unsigned char compare_value)
{
	OCR0=compare_value;
}

/*Timer Counter 2 Function Definitions*/
void set_timercounter2_mode(unsigned char mode)
{
	if(mode==0)
	{
		TCCR2|=0;
	}
	else if(mode==1)
	{
		TCCR2|=_BV(WGM20);
	}
	else if(mode==2)
	{
		TCCR2|=_BV(WGM21);
	}
	else if(mode==3)
	{
		TCCR2|=_BV(WGM20)|_BV(WGM21);
	}
	else
	;

}

void set_timercounter2_prescaler(unsigned char prescaler_value)
{
	TCCR2&=~(0x07);
	TCCR2|=prescaler_value;
}

void set_timercounter2_output_mode(unsigned char output_mode)
{
	TCCR2|=output_mode<<4;
}

void enable_timercounter2_interrupt(unsigned char interrupt_type)
{
	TIMSK|=1<<(interrupt_type+6);
}

void disable_timercounter2_interrupt(unsigned char interrupt_type)
{
	TIMSK&=~(1<<(interrupt_type+6));
}

void set_timercounter2_compare_value(unsigned char compare_value)
{
	OCR2=compare_value;
}








//////////////////////////////////////////////
