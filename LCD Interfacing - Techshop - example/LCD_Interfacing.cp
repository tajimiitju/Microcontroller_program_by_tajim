#line 1 "D:/DVD Data all/AVR Trainer Kit/Example/LCD Interfacing/LCD_Interfacing.c"
#line 26 "D:/DVD Data all/AVR Trainer Kit/Example/LCD Interfacing/LCD_Interfacing.c"
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


char txt1[] = "LCD  Test";
char txt2[] = "Example";
char txt3[] = "Welcome to";
char txt4[] = "TechShopBD";


void main()
{
 char i;

 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);

 Lcd_Out(1,4,txt3);
 Lcd_Out(2,4,txt4);
 Delay_ms(2000);
 Lcd_Cmd(_LCD_CLEAR);

 Lcd_Out(1,4,txt1);
 Lcd_Out(2,5,txt2);
 Delay_ms(1000);


 for(i=0; i<4; i++)
 {
 Lcd_Cmd(_LCD_SHIFT_RIGHT);
 Delay_ms(500);
 }
 while(1)
 {
 for(i=0; i<4; i++)
 {
 Lcd_Cmd(_LCD_SHIFT_LEFT);
 Delay_ms(500);
 }

 for(i=0; i<4; i++)
 {
 Lcd_Cmd(_LCD_SHIFT_RIGHT);
 Delay_ms(500);
 }
 }
}
