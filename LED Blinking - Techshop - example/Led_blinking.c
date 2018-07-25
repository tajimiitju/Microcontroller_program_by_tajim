/*
 * Project name:
     LED Blinking
 * Copyright:
     (c) TechshopBD, 2013.
 * Code Writer:
     Alia Rifat.
 * Revision History:
     20130408:
       - initial release;
 * Description:
      A simple example of blinking LED.
      8 LEDs are connected to PORTC through an 8-position DIP switch.
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
  DDRC = 0xFF;                // Set PORTC as output
  while (1)
  {
    PORTC = 0xFF;             //Turn ON all the LEDs
    Delay_ms(1000);           //Wait for 1 second
    PORTC = 0x00;             //Turn OFF all the LEDs
    Delay_ms(1000);           //Wait for 1 second
  }
}