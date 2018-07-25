/*
 * Project name:
     Playing tunes in speaker
 * Copyright:
     (c) TechshopBD, 2013.
 * Code Writer:
     Alia Rifat.
 * Revision History:
     20130613:
       - initial release;
 * Description:
      This code will play 'twinkle twinkle' in the buzzer connected to PB3 and
      simultaneously show the lyrics on the LCD display as soon as you press the
      button conncted to PD2

 * Test configuration:
     MCU:             ATmega32A
                      http://www.techshopbd.com/uploads/product_document/ATmega32%20Datasheet.pdf
     dev.board:       TechAVR2 - Trainer Kit
                      http://www.techshopbd.com/index.php/product-categories/avr-9715/avr/techavr2-trainer-kit
     Oscillator:      External Clock 16.0000 MHz
     Software:        mikroC PRO for AVR v.6.0.0
                      http://www.mikroe.com/eng/products/view/228/mikroc-pro-for-avr/
     
     Note: 1) Please check  http://www.phy.mtu.edu/~suits/notefreqs.html to know the frquency of musical notes.
           2) Don't forget to add Sound and LCD library.
*/

#define C6  1047     // C6,Frequency 1047
#define D6  1175     // D6,Frequency 1175
#define E6  1319     // E6,Frequency 1319
#define F6  1397     // F6,Frequency 1397
#define G6  1569     // G6,Frequency 1569
#define A6  1760     // A6,Frequency 1760
#define B6  1976     // B6,Frequency 1976
#define C7  2093     // C7,Frequency 2093

// LCD module connections
sbit LCD_RS at PORTD4_bit;   // Connect the RS pin of LCD to PD4
sbit LCD_EN at PORTD6_bit;   // Connect the EN pin of LCD to PD6
sbit LCD_D4 at PORTC4_bit;   // Connect the D4 pin of LCD to PC4
sbit LCD_D5 at PORTC5_bit;   // Connect the D5 pin of LCD to PC5
sbit LCD_D6 at PORTC6_bit;   // Connect the D6 pin of LCD to PC6
sbit LCD_D7 at PORTC7_bit;   // Connect the D7 pin of LCD to PC7

sbit LCD_RS_Direction at DDD4_bit;
sbit LCD_EN_Direction at DDD6_bit;
sbit LCD_D4_Direction at DDC4_bit;
sbit LCD_D5_Direction at DDC5_bit;
sbit LCD_D6_Direction at DDC6_bit;
sbit LCD_D7_Direction at DDC7_bit;
// End LCD module connections


// Function declaration
void Twinkle();


void main()
{
  DDD2_bit = 0;                              // Set PD2 as input
  PORTD2_bit = 1;                            // Enable pullup

  Sound_Init(&PORTB,3);                      // Initialize sound pin
  Lcd_Init();                                // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);                       // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);                  // Cursor off
  Delay_ms(100);

  Lcd_Out(1,1, "Press the button");          // Show "Press the button" on LCD
  Lcd_Out(2,1, "to start music");            // Show "to start music" on LCD

  while (1)
  {
      if(PIND2_bit==0)
      {
         Twinkle();                          // Call the function twinkle
         Lcd_Cmd(_LCD_CLEAR);                // Clear LCD
         Delay_ms(1000);                     // Wait for 1000 milisecond
         Lcd_Out(1,1, "Press the button");   // Show "Press the button" on LCD
         Lcd_Out(2,1, "to start music");     // Show "to start music" on LCD
      }
  }
}



void Twinkle()
{
    Lcd_Cmd(_LCD_CLEAR);                     //Clear LCD
    Delay_ms(1);                             //Wait for 1 milisecond

    Lcd_Out(1,1, "Twin");                    //Show 'Twin' on LCD
    Sound_play(C6,400);                      //play C6 for 400 milisecond

    Lcd_Out(1,5, "kle");                     //Show 'kle' on LCD
    Sound_play(C6,400);                      //play C6 for 400 milisecond

    Lcd_Out(1,9, "Twin");                    //Show 'Twin' on LCD
    Sound_play(G6,400);                      //play G6 for 400 milisecond

    Lcd_Out(1,13, "kle");                    //Show 'kle' on LCD
    Sound_play(G6,400);                      //play G6 for 400 milisecond

    Lcd_Out(2,1, "lit");                     //Show 'lit' on LCD
    Sound_play(A6,400);                      //play A6 for 400 milisecond

    Lcd_Out(2,4, "tle");                     //Show 'tle' on LCD
    Sound_play(A6,400);                      //play A6 for 400 milisecond

    Lcd_Out(2,8, "Star");                    //Show 'star' on LCD
    Sound_play(G6,1000);                     //play G6 for 400 milisecond



    Lcd_Cmd(_LCD_CLEAR);                     //Clear LCD
    Delay_ms(1);                             //wait for 1 milisecond
    Lcd_Out(1,1, "How");                     //Show 'How' on LCD
    Sound_play(F6,400);                      //play F6 for 400 milisecond


    Lcd_Out(1,5, "I");                       //Show 'I' on LCD
    Sound_play(F6,400);                      //play F6 for 400 milisecond

    Lcd_Out(1,7, "won");                     //Show 'won' on LCD
    Sound_play(E6,400);                      //play E6 for 400 milisecond

    Lcd_Out(1,10, "der");                    //Show 'der' on LCD
    Sound_play(E6,400);                      //play E6 for 400 milisecond

    Lcd_Out(2,1, "what");                    //Show 'what' on LCD
    Sound_play(D6,400);                      //play D6 for 400 milisecond

    Lcd_Out(2,6, "you");                     //Show 'what' on LCD
    Sound_play(D6,400);                      //play D6 for 400 milisecond

    Lcd_Out(2,10, "are!");                   //Show 'what' on LCD
    Sound_play(C6,1000);                     //play C6 for 400 milisecond



    Lcd_Cmd(_LCD_CLEAR);
    Delay_ms(1);
    Lcd_Out(1,1, "Up");                      //Show 'Up' on LCD
    Sound_play(G6,400);                      //play G6 for 400 milisecond

    Lcd_Out(1,4, "A");                       //Show 'A' on LCD
    Sound_play(G6,400);                      //play G6 for 400 milisecond

    Lcd_Out(1,5, "bove");                    //Show 'bove' on LCD
    Sound_play(F6,400);                      //play F6 for 400 milisecond

    Lcd_Out(1,10, "The");                    //Show 'The' on LCD
    Sound_play(F6,400);                      //play F6 for 400 milisecond

    Lcd_Out(2,1, "World");                   //Show 'World' on LCD
    Sound_play(E6,400);                      //play E6 for 400 milisecond

    Lcd_Out(2,7, "so");                      //Show 'so' on LCD
    Sound_play(E6,400);                      //play E6 for 400 milisecond

    Lcd_Out(2,10, "high");                   //Show 'high' on LCD
    Sound_play(D6,1000);                     //play D6 for 400 milisecond



    Lcd_Cmd(_LCD_CLEAR);
    Delay_ms(1);
    Lcd_Out(1,1, "Like");                    //Show 'Like' on LCD
    Sound_play(G6,400);                      //play G6 for 400 milisecond

    Lcd_Out(1,6, "A");                       //Show 'A' on LCD
    Sound_play(G6,400);                      //play G6 for 400 milisecond

    Lcd_Out(1,8, "Dia");                     //Show 'Dia' on LCD
    Sound_play(F6,400);                      //play F6 for 400 milisecond

    Lcd_Out(1,11, "mond");                   //Show 'mond' on LCD
    Sound_play(F6,400);                      //play F6 for 400 milisecond

    Lcd_Out(2,1, "In");                      //Show 'In' on LCD
    Sound_play(E6,400);                      //play E6 for 400 milisecond

    Lcd_Out(2,4, "The");                     //Show 'The' on LCD
    Sound_play(E6,400);                      //play E6 for 400 milisecond

    Lcd_Out(2,8, "Sky");                     //Show 'Sky' on LCD
    Sound_play(D6,1000);                     //play D6 for 400 milisecond


    Lcd_Cmd(_LCD_CLEAR);
    Delay_ms(1);
     Lcd_Out(1,1, "Twin");                   //Show 'Twin' on LCD
    Sound_play(C6,400);                      //play C6 for 400 milisecond

    Lcd_Out(1,5, "kle");                     //Show 'kle' on LCD
    Sound_play(C6,400);                      //play C6 for 400 milisecond

    Lcd_Out(1,9, "Twin");                    //Show 'Twin' on LCD
    Sound_play(G6,400);                      //play G6 for 400 milisecond

    Lcd_Out(1,13, "kle");                    //Show 'kle' on LCD
    Sound_play(G6,400);                      //play G6 for 400 milisecond

    Lcd_Out(2,1, "lit");                     //Show 'lit' on LCD
    Sound_play(A6,400);                      //play A6 for 400 milisecond

    Lcd_Out(2,4, "tle");                     //Show 'tle' on LCD
    Sound_play(A6,400);                      //play A6 for 400 milisecond

    Lcd_Out(2,8, "Star");                    //Show 'Star' on LCD
    Sound_play(G6,1000);                     //play G6 for 400 milisecond



    Lcd_Cmd(_LCD_CLEAR);                     //Clear LCD
    Delay_ms(1);                             //Wait for 1 milisecond
    Lcd_Cmd(_LCD_CLEAR);                     //Clear LCD
    Delay_ms(1);                             //wait for 1 milisecond
    Lcd_Out(1,1, "How");                     //Show 'How' on LCD
    Sound_play(F6,400);                      //play F6 for 400 milisecond

    Lcd_Out(1,5, "I");                       //Show 'I' on LCD
    Sound_play(F6,400);                      //play F6 for 400 milisecond

    Lcd_Out(1,7, "won");                     //Show 'Won' on LCD
    Sound_play(E6,400);                      //play F6 for 400 milisecond

    Lcd_Out(1,10, "der");                    //Show 'der' on LCD
    Sound_play(E6,400);                      //play E6 for 400 milisecond

    Lcd_Out(2,1, "what");                    //Show 'what' on LCD
    Sound_play(D6,400);                      //play D6 for 400 milisecond

    Lcd_Out(2,6, "you");                     //Show 'you' on LCD
    Sound_play(D6,400);                      //play D6 for 400 milisecond

    Lcd_Out(2,10, "are!");                   //Show 'are' on LCD
    Sound_play(C6,1000);                     //play C6 for 400 milisecond



    Delay_ms(1000);                          //wait for 1000 milisecond
    Lcd_Cmd(_LCD_CLEAR);                     //clear LCD
    Delay_ms(1);                             //wait for 1 milisecond
    Lcd_Out(2,3, "Thank you!");              //Show 'Thank You' on LCD
    Sound_Play(C7,100);                      //play C7 for 400 milisecond

    Delay_ms(20);                            //Wait for 20 milisecond
    Sound_Play(C7,1500);                     //play C7 for 400 milisecond

}