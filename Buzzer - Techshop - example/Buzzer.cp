#line 1 "C:/Users/kanok/Desktop/Code for AVR dev board/TechAVR2/Example/Buzzer/Buzzer.c"
#line 39 "C:/Users/kanok/Desktop/Code for AVR dev board/TechAVR2/Example/Buzzer/Buzzer.c"
sbit LCD_RS at PORTD4_bit;
sbit LCD_EN at PORTD6_bit;
sbit LCD_D4 at PORTC4_bit;
sbit LCD_D5 at PORTC5_bit;
sbit LCD_D6 at PORTC6_bit;
sbit LCD_D7 at PORTC7_bit;

sbit LCD_RS_Direction at DDD4_bit;
sbit LCD_EN_Direction at DDD6_bit;
sbit LCD_D4_Direction at DDC4_bit;
sbit LCD_D5_Direction at DDC5_bit;
sbit LCD_D6_Direction at DDC6_bit;
sbit LCD_D7_Direction at DDC7_bit;




void Twinkle();


void main()
{
 DDD2_bit = 0;
 PORTD2_bit = 1;

 Sound_Init(&PORTB,3);
 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Delay_ms(100);

 Lcd_Out(1,1, "Press the button");
 Lcd_Out(2,1, "to start music");

 while (1)
 {
 if(PIND2_bit==0)
 {
 Twinkle();
 Lcd_Cmd(_LCD_CLEAR);
 Delay_ms(1000);
 Lcd_Out(1,1, "Press the button");
 Lcd_Out(2,1, "to start music");
 }
 }
}



void Twinkle()
{
 Lcd_Cmd(_LCD_CLEAR);
 Delay_ms(1);

 Lcd_Out(1,1, "Twin");
 Sound_play( 1047 ,400);

 Lcd_Out(1,5, "kle");
 Sound_play( 1047 ,400);

 Lcd_Out(1,9, "Twin");
 Sound_play( 1569 ,400);

 Lcd_Out(1,13, "kle");
 Sound_play( 1569 ,400);

 Lcd_Out(2,1, "lit");
 Sound_play( 1760 ,400);

 Lcd_Out(2,4, "tle");
 Sound_play( 1760 ,400);

 Lcd_Out(2,8, "Star");
 Sound_play( 1569 ,1000);



 Lcd_Cmd(_LCD_CLEAR);
 Delay_ms(1);
 Lcd_Out(1,1, "How");
 Sound_play( 1397 ,400);


 Lcd_Out(1,5, "I");
 Sound_play( 1397 ,400);

 Lcd_Out(1,7, "won");
 Sound_play( 1319 ,400);

 Lcd_Out(1,10, "der");
 Sound_play( 1319 ,400);

 Lcd_Out(2,1, "what");
 Sound_play( 1175 ,400);

 Lcd_Out(2,6, "you");
 Sound_play( 1175 ,400);

 Lcd_Out(2,10, "are!");
 Sound_play( 1047 ,1000);



 Lcd_Cmd(_LCD_CLEAR);
 Delay_ms(1);
 Lcd_Out(1,1, "Up");
 Sound_play( 1569 ,400);

 Lcd_Out(1,4, "A");
 Sound_play( 1569 ,400);

 Lcd_Out(1,5, "bove");
 Sound_play( 1397 ,400);

 Lcd_Out(1,10, "The");
 Sound_play( 1397 ,400);

 Lcd_Out(2,1, "World");
 Sound_play( 1319 ,400);

 Lcd_Out(2,7, "so");
 Sound_play( 1319 ,400);

 Lcd_Out(2,10, "high");
 Sound_play( 1175 ,1000);



 Lcd_Cmd(_LCD_CLEAR);
 Delay_ms(1);
 Lcd_Out(1,1, "Like");
 Sound_play( 1569 ,400);

 Lcd_Out(1,6, "A");
 Sound_play( 1569 ,400);

 Lcd_Out(1,8, "Dia");
 Sound_play( 1397 ,400);

 Lcd_Out(1,11, "mond");
 Sound_play( 1397 ,400);

 Lcd_Out(2,1, "In");
 Sound_play( 1319 ,400);

 Lcd_Out(2,4, "The");
 Sound_play( 1319 ,400);

 Lcd_Out(2,8, "Sky");
 Sound_play( 1175 ,1000);


 Lcd_Cmd(_LCD_CLEAR);
 Delay_ms(1);
 Lcd_Out(1,1, "Twin");
 Sound_play( 1047 ,400);

 Lcd_Out(1,5, "kle");
 Sound_play( 1047 ,400);

 Lcd_Out(1,9, "Twin");
 Sound_play( 1569 ,400);

 Lcd_Out(1,13, "kle");
 Sound_play( 1569 ,400);

 Lcd_Out(2,1, "lit");
 Sound_play( 1760 ,400);

 Lcd_Out(2,4, "tle");
 Sound_play( 1760 ,400);

 Lcd_Out(2,8, "Star");
 Sound_play( 1569 ,1000);



 Lcd_Cmd(_LCD_CLEAR);
 Delay_ms(1);
 Lcd_Cmd(_LCD_CLEAR);
 Delay_ms(1);
 Lcd_Out(1,1, "How");
 Sound_play( 1397 ,400);

 Lcd_Out(1,5, "I");
 Sound_play( 1397 ,400);

 Lcd_Out(1,7, "won");
 Sound_play( 1319 ,400);

 Lcd_Out(1,10, "der");
 Sound_play( 1319 ,400);

 Lcd_Out(2,1, "what");
 Sound_play( 1175 ,400);

 Lcd_Out(2,6, "you");
 Sound_play( 1175 ,400);

 Lcd_Out(2,10, "are!");
 Sound_play( 1047 ,1000);



 Delay_ms(1000);
 Lcd_Cmd(_LCD_CLEAR);
 Delay_ms(1);
 Lcd_Out(2,3, "Thank you!");
 Sound_Play( 2093 ,100);

 Delay_ms(20);
 Sound_Play( 2093 ,1500);

}
