/*
 * Project name:
     LCD Interfacing
 * Copyright:
     (c) TechshopBD, 2013.
 * Code Writer:
     Alia Rifat.
 * Revision History:
     20130610:
       - initial release;
 * Description:
      A simple example of interfacing LCD.
      PORTD4, PORTD6, PORTC4-7 are connected to LCD connector through Dip switch (DSW2).
 * Test configuration:
     MCU:             ATmega32
                      http://www.techshopbd.com/uploads/product_document/ATmega32%20Datasheet.pdf
     dev.board:       TechAVR2 - Trainer Kit
                      http://www.techshopbd.com/index.php/product-categories/avr-9715/avr/techavr2-trainer-kit
     Oscillator:      External Clock 16.0000 MHz
     Software:        mikroC PRO for AVR v.6.0.0
                      http://www.mikroe.com/eng/products/view/228/mikroc-pro-for-avr/
 * NOTES:
     - Turn on the 8-position DIP switch (DSW2), except position 6.
 */

sbit LCD_RS at PORTD4_bit;   // connect the RS pin of LCD to PD4
sbit LCD_EN at PORTD6_bit;   // connect the EN pin of LCD to PD6
sbit LCD_D4 at PORTC4_bit;   // connect the D4 pin of LCD to PC4
sbit LCD_D5 at PORTC5_bit;   // connect the D5 pin of LCD to PC5
sbit LCD_D6 at PORTC6_bit;   // connect the D6 pin of LCD to PC6
sbit LCD_D7 at PORTC7_bit;   // connect the D7 pin of LCD to PC7

sbit LCD_RS_Direction at DDD4_bit;
sbit LCD_EN_Direction at DDD6_bit;
sbit LCD_D4_Direction at DDC4_bit;
sbit LCD_D5_Direction at DDC5_bit;
sbit LCD_D6_Direction at DDC6_bit;
sbit LCD_D7_Direction at DDC7_bit;


char txt1[] = "LCD  Test";
char txt2[] = "Example";
char txt3[] = "Welcome to";
char txt4[] = "TechShopBD";


void main()
{
  char i;                      // Loop variable
  
  Lcd_Init();                  // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);         // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);    // Cursor off

  Lcd_Out(1,4,txt3);           // Write text in first row
  Lcd_Out(2,4,txt4);           // Write text in second row
  Delay_ms(2000);
  Lcd_Cmd(_LCD_CLEAR);         // Clear display

  Lcd_Out(1,4,txt1);           // Write text in first row
  Lcd_Out(2,5,txt2);           // Write text in second row
  Delay_ms(1000);

  // Moving text
  for(i=0; i<4; i++)           // Move text to the right 4 times
  {
    Lcd_Cmd(_LCD_SHIFT_RIGHT);
    Delay_ms(500);
  }
  while(1)                     // Endless loop
  {
    for(i=0; i<4; i++)         // Move text to the left 4 times
    {
      Lcd_Cmd(_LCD_SHIFT_LEFT);
      Delay_ms(500);
    }

    for(i=0; i<4; i++)         // Move text to the right 4 times
    {
      Lcd_Cmd(_LCD_SHIFT_RIGHT);
      Delay_ms(500);
    }
  }
}