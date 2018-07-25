#line 1 "C:/Users/kanok/Desktop/Code for AVR dev board/TechAVR2/Joystick Interfacing/Joystick.c"
#line 32 "C:/Users/kanok/Desktop/Code for AVR dev board/TechAVR2/Joystick Interfacing/Joystick.c"
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


void main()
{
 short x=1, y=5;
 char txt[] = "Welcome";

 DDRA = DDRA & 0x07;
 PORTA=0xF8;

 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(x, y, txt);

 while(1)
 {
 if(PINA3_bit==0)
 {
 x=1;
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(x, y, txt);
 while(PINA3_bit==0);
 }

 if(PINA7_bit==0)
 {
 x=2;
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(x, y, txt);
 while(PINA7_bit==0);
 }

 if(PINA4_bit==0)
 {
 y=5;
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(x, y, txt);
 while(PINA4_bit==0);
 }

 if(PINA5_bit==0)
 {
 y--;
 if(y<1)
 {
 y=1;
 }
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(x, y, txt);
 while(PINA5_bit==0);
 }

 if(PINA6_bit==0)
 {
 y++;
 if(y>10)
 {
 y=10;
 }
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(x, y, txt);
 while(PINA6_bit==0);
 }
 }
}
