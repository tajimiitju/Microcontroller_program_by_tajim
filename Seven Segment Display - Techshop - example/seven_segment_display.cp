#line 1 "E:/OneDrive/TechShop Projects/a) NUR MOHAMMAD/AVR trainer kit/Example/Seven Segment Display/seven_segment_display.c"

void main() {
 int i=0;




 char number[] = {0x3F, 0x86, 0x5B, 0xCF, 0x66, 0xED, 0x7D, 0x87, 0x7F, 0xEF};

 DDRB = 0xFF;

 while (1)
 {
 for (i=0; i<=9; i++)
 {
 PORTB = number[i];
 Delay_ms(700);
 }
 }
}
