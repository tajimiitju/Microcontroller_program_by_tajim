/*
 * Project name:
     Measuring Voltage by ADC
 * Copyright:
     (c) TechshopBD, 2013.
 * Code:
     Alia Rifat.
 * Revision History:
     20130409:
       - initial release;
 * Description:
      A simple example of measuring Voltage by ADC and showing it in
      the seven segment diplay connected to PORTB. The input voltage
      will be measure through PA0 pin.
 * Test configuration:
     MCU:             ATmega32A
                      http://techshopbd.com/uploads/product_document/ATmega32%20Datasheet.pdf
     Dev.board:       TechAVR2 - Trainer Kit
                      http://www.techshopbd.com/index.php/product-categories/avr-9715/avr/techavr2-trainer-kit
     Oscillator:      External Clock 16.0000 MHz
     Software:        mikroC PRO for AVR v.6.0.0
                      http://www.mikroe.com/eng/products/view/228/mikroc-pro-for-avr/
 * NOTES:
     - Place the jumper of J9. Vary the 100K POT(beside J17)
       and see the change of voltage value in 7-segment display.
*/

void main()
{
    volatile unsigned short hi,low,decimal;
    char display[10]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; // CC value of 0-9.
    volatile float adc_value;
    
    DDRA=0x00;         // Declaring PORTA as input
    DDRB=0xFF;         // Declaring PORTB as output
    ADEN_bit=1;        // ADC enable
    REFS0_bit=1;       // Voltage Reference Selection, AVCC(~5V) with external capacitor at AREF pin (Slide down the SW2 switch)
    ADCSRA|=(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);   // ADC Prescaler Selections,selecting division factor=128

    while(1)
    {
        ADSC_bit = 1;      // ADC Start Conversion
        while(ADSC_bit!=0);// Wait till conversion finish
        low = ADCL;        // Store lower eight bits of ADC conversion in 'low'
        hi = ADCH;         // Store upper eight bits of ADC conversion in 'hi'
        adc_value = (hi<<8)+low; //Shift 'hi' 8 steps right and add 'low' with it

        adc_value = (9*adc_value)/1023; //Analog to digital conversion, Precision=5/1023.
        decimal = adc_value;// Store the decimal value and omit other.
        PORTB = display[decimal]; // Show the value in 7-segment connected to PORTB
    }
}