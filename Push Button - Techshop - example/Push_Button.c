/*
 * Project name:
     Turning LED's ON and OFF by using buttons.
 * Copyright:
     (c) TechshopBD, 2013.
 *Code Writer:
     Alia Rifat
 * Revision History:
     20130409:
       - initial release;
 * Description:
      A simple example of switching LED's ON and OFF by using buttons.Button
      1 is connected to PD2,button 2 is connected to PD3.
 * Test configuration:
     MCU:             ATmega32
                      http://www.techshopbd.com/uploads/product_document/ATmega32%20Datasheet.pdf
     dev.board:       TechAVR2 - Trainer Kit
                      http://www.techshopbd.com/index.php/product-categories/avr-9715/avr/techavr2-trainer-kit
     Oscillator:      External Clock 16.0000 MHz
     Software:        mikroC PRO for AVR v.6.0.0
                      http://www.mikroe.com/eng/products/view/228/mikroc-pro-for-avr/
 * NOTES:
     - Turn on the 8-position DIP switch to blink each LED.
 */

void main()
{
   DDD2_bit = 0;                      // Make PORTD's PD2 as input
   DDD3_bit = 0;                      // Make PORTD's PD3 as input
   PORTD2_bit=1;                      // Pull up PD2
   PORTD3_bit=1;                      // Pull up PD3
   DDC0_bit = 1;                      // Make PORTC's PC0 as output
   DDC1_bit = 1;                      // Make PORTC's PC1 as output

   while(1)
   {
      if(PIND2_bit == 0)              // Check if button 2 is pressed
      {
         Delay_ms(80);                // wait 80 milisecond, for debounce effect
         PORTC0_bit = ~PORTC0_bit;    // Toggle PC0
         while(PIND2_bit == 0);       // wait till button 2 is pressed
      }
      if(PIND3_bit == 0)              // Check if button 1 is pressed
      {
         Delay_ms(80);                // wait 80 milisecond, for debounce effect
         PORTC1_bit = ~PORTC1_bit;    // Toggle PC1
         while(PIND3_bit == 0);       // wait till button 1 is pressed
      }
   }

}