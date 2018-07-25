
void main() {
  int i=0;
  //with no decimal point DP
  //char number[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
  
  //with blinking decimal point DP . Comment any two.
  char number[] = {0x3F, 0x86, 0x5B, 0xCF, 0x66, 0xED, 0x7D, 0x87, 0x7F, 0xEF};
  
  DDRB = 0xFF;                   // Configure PORTB as input
  
  while (1) 
  {                    // endless loop
     for (i=0; i<=9; i++)
         {
         PORTB = number[i];
         Delay_ms(700);
         }
  }
}