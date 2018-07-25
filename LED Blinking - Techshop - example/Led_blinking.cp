#line 1 "D:/DVD Data all/AVR Trainer Kit/Example/LED Blinking/Led_blinking.c"
#line 26 "D:/DVD Data all/AVR Trainer Kit/Example/LED Blinking/Led_blinking.c"
void main()
{
 DDRC = 0xFF;
 while (1)
 {
 PORTC = 0xFF;
 Delay_ms(1000);
 PORTC = 0x00;
 Delay_ms(1000);
 }
}
