 /*
 * Project name:
    Interfacing LCD display with a 5-way tactile switch
 * Copyright:
     (c) TechshopBD, 2013.
 * Code Writer:
     Alia Rifat.
 * Revision History:
     20130613:
       - initial release;
 * Description:
      A simple example of Interfacing a 2x16  LCD display with a 5-way tactile 
      switch. The switch goes to 5 different directions-Up,Down,Middle,Left,Right.
      The switch is connected to five pins of PORTA.Those are-PA3,PA4,PA5,PA6,PA7.
      By adjusting the tactile switch in different positions,we'll move the text
      shown in the LCD display to different directions.

 * Test configuration:
     MCU:             ATmega32A
                      http://www.techshopbd.com/uploads/product_document/ATmega32%20Datasheet.pdf
     dev.board:       TechAVR2 - Trainer Kit
                      http://www.techshopbd.com/index.php/product-categories/avr-9715/avr/techavr2-trainer-kit
     Oscillator:      External Clock 16.0000 MHz
     Software:        mikroC PRO for AVR v.6.0.0
                      http://www.mikroe.com/eng/products/view/228/mikroc-pro-for-avr/
 * NOTES:
     - Turn on the 8-position DIP switch (DSW2), excapt the 6th position.
     - Place the joystick jumper (J3)
 */


sbit LCD_RS at PORTD4_bit;   // connect the RS pin of LCD to PD4
sbit LCD_EN at PORTD6_bit;   // connect the EN pin of LCD to PD6
sbit LCD_D4 at PORTC4_bit;   // connect the D4 pin of LCD to PC4
sbit LCD_D5 at PORTC5_bit;   // connect the D5 pin of LCD to PC5
sbit LCD_D6 at PORTC6_bit;   // connect the D6 pin of LCD to PC6
sbit LCD_D7 at PORTC7_bit;   // connect the D7 pin of LCD to PC7

sbit LCD_RS_Direction at DDD4_bit;//Direction of RS pin
sbit LCD_EN_Direction at DDD6_bit;//Direction of EN pin
sbit LCD_D4_Direction at DDC4_bit;//Direction of D4 pin
sbit LCD_D5_Direction at DDC5_bit;//Direction of D5 pin
sbit LCD_D6_Direction at DDC6_bit;//Direction of D6 pin
sbit LCD_D7_Direction at DDC7_bit;//Direction of D7 pin


void main()
{
  short x=1, y=5;                    // Declare two integer type variables
  char txt[] = "Welcome";            // Keep the text " Welcome " in a characrter type array
  
  DDRA = DDRA & 0x07;                // Setting PA3 to PA7 as output
  PORTA=0xF8;                        // Pulling up PA3 to PA7
  
  Lcd_Init();                        // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);               // Clear Display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
  Lcd_Out(x, y, txt);                // Show "Welcome" on 1st row, 5th coloumn

  while(1)
  {
     if(PINA3_bit==0)                // Check if the switch is in 'up' position
     {
       x=1;                          // Set the value of x as 1
       Lcd_Cmd(_LCD_CLEAR);          // Clear the LCD display
       Lcd_Out(x, y, txt);           // Show "Welcome" on 1st row, yth coulumn,
       while(PINA3_bit==0);          // Wait till the button is in 'up' position
     }
     
     if(PINA7_bit==0)                // Check if the switch is in 'down' position
     {
       x=2;                          // Set the value to x as
       Lcd_Cmd(_LCD_CLEAR);          // Clear the LCD display
       Lcd_Out(x, y, txt);           // Show "Welcome" on 2nd row,yth coulumn
       while(PINA7_bit==0);          // Wait till the button is in 'down'position
     }
     
     if(PINA4_bit==0)                // Check if the switch is in 'middle' position
     {
       y=5;                          // Set the value of y as 5
       Lcd_Cmd(_LCD_CLEAR);          // Clear the LCD display
       Lcd_Out(x, y, txt);           // Show "Welcome" on xth row, 5th coulumn
       while(PINA4_bit==0);          // Wait till the button is in 'middle' Position
     }
     
     if(PINA5_bit==0)                // Check if the switch is in 'left' position
     {
       y--;                          // Decrease the value of y i.e. coulumn by 1
       if(y<1)                       // If coulumn number is less than 1
       {
          y=1;                       // Keep the value 1
       }
       Lcd_Cmd(_LCD_CLEAR);          // Clear the LCD display
       Lcd_Out(x, y, txt);           // Show "Welcome" on xth row, yth coulumn
       while(PINA5_bit==0);          // Wait till the button 'Left' is pressed
     }
     
     if(PINA6_bit==0)                // Check if the switch is in 'Right' position
     {
       y++;
       if(y>10)
       {
       y=10;
       }
       Lcd_Cmd(_LCD_CLEAR);          // Clear the LCD display
       Lcd_Out(x, y, txt);           // Show "Welcome" on xth row, yth coulumn
       while(PINA6_bit==0);
     }
  }
}