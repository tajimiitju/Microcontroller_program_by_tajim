#line 1 "D:/today09/DVD Data all/AVR Trainer Kit/Example/ADC/ADC_Interfacing.c"
#line 28 "D:/today09/DVD Data all/AVR Trainer Kit/Example/ADC/ADC_Interfacing.c"
void main()
{
 volatile unsigned short hi,low,decimal;
 char display[10]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
 volatile float adc_value;

 DDRA=0x00;
 DDRB=0xFF;
 ADEN_bit=1;
 REFS0_bit=1;
 ADCSRA|=(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

 while(1)
 {
 ADSC_bit = 1;
 while(ADSC_bit!=0);
 low = ADCL;
 hi = ADCH;
 adc_value = (hi<<8)+low;

 adc_value = (9*adc_value)/1023;
 decimal = adc_value;
 PORTB = display[decimal];
 }
}
