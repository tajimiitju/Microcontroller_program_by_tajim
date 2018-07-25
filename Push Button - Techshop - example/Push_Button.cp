#line 1 "C:/Users/kanok/Desktop/Code for AVR dev board/TechAVR2/Example/Push Button/Push_Button.c"
#line 26 "C:/Users/kanok/Desktop/Code for AVR dev board/TechAVR2/Example/Push Button/Push_Button.c"
void main()
{
 DDD2_bit = 0;
 DDD3_bit = 0;
 PORTD2_bit=1;
 PORTD3_bit=1;
 DDC0_bit = 1;
 DDC1_bit = 1;

 while(1)
 {
 if(PIND2_bit == 0)
 {
 Delay_ms(80);
 PORTC0_bit = ~PORTC0_bit;
 while(PIND2_bit == 0);
 }
 if(PIND3_bit == 0)
 {
 Delay_ms(80);
 PORTC1_bit = ~PORTC1_bit;
 while(PIND3_bit == 0);
 }
 }

}
