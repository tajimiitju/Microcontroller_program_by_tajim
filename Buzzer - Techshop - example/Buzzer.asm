
_main:
	LDI        R27, 255
	OUT        SPL+0, R27
	LDI        R27, 0
	OUT        SPL+1, R27

;Buzzer.c,59 :: 		void main()
;Buzzer.c,61 :: 		DDD2_bit = 0;                              // Set PD2 as input
	PUSH       R2
	PUSH       R3
	PUSH       R4
	PUSH       R5
	IN         R27, DDD2_bit+0
	CBR        R27, BitMask(DDD2_bit+0)
	OUT        DDD2_bit+0, R27
;Buzzer.c,62 :: 		PORTD2_bit = 1;                            // Enable pullup
	IN         R27, PORTD2_bit+0
	SBR        R27, BitMask(PORTD2_bit+0)
	OUT        PORTD2_bit+0, R27
;Buzzer.c,64 :: 		Sound_Init(&PORTB,3);                      // Initialize sound pin
	LDI        R27, 3
	MOV        R4, R27
	LDI        R27, #lo_addr(PORTB+0)
	MOV        R2, R27
	LDI        R27, hi_addr(PORTB+0)
	MOV        R3, R27
	CALL       _Sound_Init+0
;Buzzer.c,65 :: 		Lcd_Init();                                // Initialize LCD
	CALL       _Lcd_Init+0
;Buzzer.c,66 :: 		Lcd_Cmd(_LCD_CLEAR);                       // Clear display
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Buzzer.c,67 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);                  // Cursor off
	LDI        R27, 12
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Buzzer.c,68 :: 		Delay_ms(100);
	LDI        R18, 9
	LDI        R17, 30
	LDI        R16, 229
L_main0:
	DEC        R16
	BRNE       L_main0
	DEC        R17
	BRNE       L_main0
	DEC        R18
	BRNE       L_main0
	NOP
;Buzzer.c,70 :: 		Lcd_Out(1,1, "Press the button");          // Show "Press the button" on LCD
	LDI        R27, #lo_addr(?lstr1_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr1_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,71 :: 		Lcd_Out(2,1, "to start music");            // Show "to start music" on LCD
	LDI        R27, #lo_addr(?lstr2_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr2_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,73 :: 		while (1)
L_main2:
;Buzzer.c,75 :: 		if(PIND2_bit==0)
	IN         R27, PIND2_bit+0
	SBRC       R27, BitPos(PIND2_bit+0)
	JMP        L_main4
;Buzzer.c,77 :: 		Twinkle();                          // Call the function twinkle
	CALL       _Twinkle+0
;Buzzer.c,78 :: 		Lcd_Cmd(_LCD_CLEAR);                // Clear LCD
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Buzzer.c,79 :: 		Delay_ms(1000);                     // Wait for 1000 milisecond
	LDI        R18, 82
	LDI        R17, 43
	LDI        R16, 0
L_main5:
	DEC        R16
	BRNE       L_main5
	DEC        R17
	BRNE       L_main5
	DEC        R18
	BRNE       L_main5
	NOP
	NOP
	NOP
	NOP
;Buzzer.c,80 :: 		Lcd_Out(1,1, "Press the button");   // Show "Press the button" on LCD
	LDI        R27, #lo_addr(?lstr3_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr3_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,81 :: 		Lcd_Out(2,1, "to start music");     // Show "to start music" on LCD
	LDI        R27, #lo_addr(?lstr4_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr4_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,82 :: 		}
L_main4:
;Buzzer.c,83 :: 		}
	JMP        L_main2
;Buzzer.c,84 :: 		}
L_end_main:
L__main_end_loop:
	JMP        L__main_end_loop
; end of _main

_Twinkle:

;Buzzer.c,88 :: 		void Twinkle()
;Buzzer.c,90 :: 		Lcd_Cmd(_LCD_CLEAR);                     //Clear LCD
	PUSH       R2
	PUSH       R3
	PUSH       R4
	PUSH       R5
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Buzzer.c,91 :: 		Delay_ms(1);                             //Wait for 1 milisecond
	LDI        R17, 21
	LDI        R16, 199
L_Twinkle7:
	DEC        R16
	BRNE       L_Twinkle7
	DEC        R17
	BRNE       L_Twinkle7
;Buzzer.c,93 :: 		Lcd_Out(1,1, "Twin");                    //Show 'Twin' on LCD
	LDI        R27, #lo_addr(?lstr5_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr5_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,94 :: 		Sound_play(C6,400);                      //play C6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 23
	MOV        R2, R27
	LDI        R27, 4
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,96 :: 		Lcd_Out(1,5, "kle");                     //Show 'kle' on LCD
	LDI        R27, #lo_addr(?lstr6_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr6_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 5
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,97 :: 		Sound_play(C6,400);                      //play C6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 23
	MOV        R2, R27
	LDI        R27, 4
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,99 :: 		Lcd_Out(1,9, "Twin");                    //Show 'Twin' on LCD
	LDI        R27, #lo_addr(?lstr7_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr7_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 9
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,100 :: 		Sound_play(G6,400);                      //play G6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 33
	MOV        R2, R27
	LDI        R27, 6
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,102 :: 		Lcd_Out(1,13, "kle");                    //Show 'kle' on LCD
	LDI        R27, #lo_addr(?lstr8_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr8_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 13
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,103 :: 		Sound_play(G6,400);                      //play G6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 33
	MOV        R2, R27
	LDI        R27, 6
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,105 :: 		Lcd_Out(2,1, "lit");                     //Show 'lit' on LCD
	LDI        R27, #lo_addr(?lstr9_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr9_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,106 :: 		Sound_play(A6,400);                      //play A6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 224
	MOV        R2, R27
	LDI        R27, 6
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,108 :: 		Lcd_Out(2,4, "tle");                     //Show 'tle' on LCD
	LDI        R27, #lo_addr(?lstr10_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr10_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 4
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,109 :: 		Sound_play(A6,400);                      //play A6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 224
	MOV        R2, R27
	LDI        R27, 6
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,111 :: 		Lcd_Out(2,8, "Star");                    //Show 'star' on LCD
	LDI        R27, #lo_addr(?lstr11_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr11_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 8
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,112 :: 		Sound_play(G6,1000);                     //play G6 for 400 milisecond
	LDI        R27, 232
	MOV        R4, R27
	LDI        R27, 3
	MOV        R5, R27
	LDI        R27, 33
	MOV        R2, R27
	LDI        R27, 6
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,116 :: 		Lcd_Cmd(_LCD_CLEAR);                     //Clear LCD
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Buzzer.c,117 :: 		Delay_ms(1);                             //wait for 1 milisecond
	LDI        R17, 21
	LDI        R16, 199
L_Twinkle9:
	DEC        R16
	BRNE       L_Twinkle9
	DEC        R17
	BRNE       L_Twinkle9
;Buzzer.c,118 :: 		Lcd_Out(1,1, "How");                     //Show 'How' on LCD
	LDI        R27, #lo_addr(?lstr12_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr12_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,119 :: 		Sound_play(F6,400);                      //play F6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 117
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,122 :: 		Lcd_Out(1,5, "I");                       //Show 'I' on LCD
	LDI        R27, #lo_addr(?lstr13_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr13_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 5
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,123 :: 		Sound_play(F6,400);                      //play F6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 117
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,125 :: 		Lcd_Out(1,7, "won");                     //Show 'won' on LCD
	LDI        R27, #lo_addr(?lstr14_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr14_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 7
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,126 :: 		Sound_play(E6,400);                      //play E6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 39
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,128 :: 		Lcd_Out(1,10, "der");                    //Show 'der' on LCD
	LDI        R27, #lo_addr(?lstr15_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr15_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 10
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,129 :: 		Sound_play(E6,400);                      //play E6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 39
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,131 :: 		Lcd_Out(2,1, "what");                    //Show 'what' on LCD
	LDI        R27, #lo_addr(?lstr16_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr16_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,132 :: 		Sound_play(D6,400);                      //play D6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 151
	MOV        R2, R27
	LDI        R27, 4
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,134 :: 		Lcd_Out(2,6, "you");                     //Show 'what' on LCD
	LDI        R27, #lo_addr(?lstr17_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr17_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 6
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,135 :: 		Sound_play(D6,400);                      //play D6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 151
	MOV        R2, R27
	LDI        R27, 4
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,137 :: 		Lcd_Out(2,10, "are!");                   //Show 'what' on LCD
	LDI        R27, #lo_addr(?lstr18_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr18_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 10
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,138 :: 		Sound_play(C6,1000);                     //play C6 for 400 milisecond
	LDI        R27, 232
	MOV        R4, R27
	LDI        R27, 3
	MOV        R5, R27
	LDI        R27, 23
	MOV        R2, R27
	LDI        R27, 4
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,142 :: 		Lcd_Cmd(_LCD_CLEAR);
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Buzzer.c,143 :: 		Delay_ms(1);
	LDI        R17, 21
	LDI        R16, 199
L_Twinkle11:
	DEC        R16
	BRNE       L_Twinkle11
	DEC        R17
	BRNE       L_Twinkle11
;Buzzer.c,144 :: 		Lcd_Out(1,1, "Up");                      //Show 'Up' on LCD
	LDI        R27, #lo_addr(?lstr19_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr19_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,145 :: 		Sound_play(G6,400);                      //play G6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 33
	MOV        R2, R27
	LDI        R27, 6
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,147 :: 		Lcd_Out(1,4, "A");                       //Show 'A' on LCD
	LDI        R27, #lo_addr(?lstr20_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr20_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 4
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,148 :: 		Sound_play(G6,400);                      //play G6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 33
	MOV        R2, R27
	LDI        R27, 6
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,150 :: 		Lcd_Out(1,5, "bove");                    //Show 'bove' on LCD
	LDI        R27, #lo_addr(?lstr21_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr21_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 5
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,151 :: 		Sound_play(F6,400);                      //play F6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 117
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,153 :: 		Lcd_Out(1,10, "The");                    //Show 'The' on LCD
	LDI        R27, #lo_addr(?lstr22_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr22_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 10
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,154 :: 		Sound_play(F6,400);                      //play F6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 117
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,156 :: 		Lcd_Out(2,1, "World");                   //Show 'World' on LCD
	LDI        R27, #lo_addr(?lstr23_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr23_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,157 :: 		Sound_play(E6,400);                      //play E6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 39
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,159 :: 		Lcd_Out(2,7, "so");                      //Show 'so' on LCD
	LDI        R27, #lo_addr(?lstr24_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr24_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 7
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,160 :: 		Sound_play(E6,400);                      //play E6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 39
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,162 :: 		Lcd_Out(2,10, "high");                   //Show 'high' on LCD
	LDI        R27, #lo_addr(?lstr25_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr25_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 10
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,163 :: 		Sound_play(D6,1000);                     //play D6 for 400 milisecond
	LDI        R27, 232
	MOV        R4, R27
	LDI        R27, 3
	MOV        R5, R27
	LDI        R27, 151
	MOV        R2, R27
	LDI        R27, 4
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,167 :: 		Lcd_Cmd(_LCD_CLEAR);
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Buzzer.c,168 :: 		Delay_ms(1);
	LDI        R17, 21
	LDI        R16, 199
L_Twinkle13:
	DEC        R16
	BRNE       L_Twinkle13
	DEC        R17
	BRNE       L_Twinkle13
;Buzzer.c,169 :: 		Lcd_Out(1,1, "Like");                    //Show 'Like' on LCD
	LDI        R27, #lo_addr(?lstr26_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr26_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,170 :: 		Sound_play(G6,400);                      //play G6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 33
	MOV        R2, R27
	LDI        R27, 6
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,172 :: 		Lcd_Out(1,6, "A");                       //Show 'A' on LCD
	LDI        R27, #lo_addr(?lstr27_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr27_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 6
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,173 :: 		Sound_play(G6,400);                      //play G6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 33
	MOV        R2, R27
	LDI        R27, 6
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,175 :: 		Lcd_Out(1,8, "Dia");                     //Show 'Dia' on LCD
	LDI        R27, #lo_addr(?lstr28_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr28_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 8
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,176 :: 		Sound_play(F6,400);                      //play F6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 117
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,178 :: 		Lcd_Out(1,11, "mond");                   //Show 'mond' on LCD
	LDI        R27, #lo_addr(?lstr29_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr29_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 11
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,179 :: 		Sound_play(F6,400);                      //play F6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 117
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,181 :: 		Lcd_Out(2,1, "In");                      //Show 'In' on LCD
	LDI        R27, #lo_addr(?lstr30_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr30_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,182 :: 		Sound_play(E6,400);                      //play E6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 39
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,184 :: 		Lcd_Out(2,4, "The");                     //Show 'The' on LCD
	LDI        R27, #lo_addr(?lstr31_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr31_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 4
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,185 :: 		Sound_play(E6,400);                      //play E6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 39
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,187 :: 		Lcd_Out(2,8, "Sky");                     //Show 'Sky' on LCD
	LDI        R27, #lo_addr(?lstr32_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr32_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 8
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,188 :: 		Sound_play(D6,1000);                     //play D6 for 400 milisecond
	LDI        R27, 232
	MOV        R4, R27
	LDI        R27, 3
	MOV        R5, R27
	LDI        R27, 151
	MOV        R2, R27
	LDI        R27, 4
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,191 :: 		Lcd_Cmd(_LCD_CLEAR);
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Buzzer.c,192 :: 		Delay_ms(1);
	LDI        R17, 21
	LDI        R16, 199
L_Twinkle15:
	DEC        R16
	BRNE       L_Twinkle15
	DEC        R17
	BRNE       L_Twinkle15
;Buzzer.c,193 :: 		Lcd_Out(1,1, "Twin");                   //Show 'Twin' on LCD
	LDI        R27, #lo_addr(?lstr33_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr33_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,194 :: 		Sound_play(C6,400);                      //play C6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 23
	MOV        R2, R27
	LDI        R27, 4
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,196 :: 		Lcd_Out(1,5, "kle");                     //Show 'kle' on LCD
	LDI        R27, #lo_addr(?lstr34_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr34_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 5
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,197 :: 		Sound_play(C6,400);                      //play C6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 23
	MOV        R2, R27
	LDI        R27, 4
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,199 :: 		Lcd_Out(1,9, "Twin");                    //Show 'Twin' on LCD
	LDI        R27, #lo_addr(?lstr35_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr35_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 9
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,200 :: 		Sound_play(G6,400);                      //play G6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 33
	MOV        R2, R27
	LDI        R27, 6
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,202 :: 		Lcd_Out(1,13, "kle");                    //Show 'kle' on LCD
	LDI        R27, #lo_addr(?lstr36_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr36_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 13
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,203 :: 		Sound_play(G6,400);                      //play G6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 33
	MOV        R2, R27
	LDI        R27, 6
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,205 :: 		Lcd_Out(2,1, "lit");                     //Show 'lit' on LCD
	LDI        R27, #lo_addr(?lstr37_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr37_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,206 :: 		Sound_play(A6,400);                      //play A6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 224
	MOV        R2, R27
	LDI        R27, 6
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,208 :: 		Lcd_Out(2,4, "tle");                     //Show 'tle' on LCD
	LDI        R27, #lo_addr(?lstr38_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr38_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 4
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,209 :: 		Sound_play(A6,400);                      //play A6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 224
	MOV        R2, R27
	LDI        R27, 6
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,211 :: 		Lcd_Out(2,8, "Star");                    //Show 'Star' on LCD
	LDI        R27, #lo_addr(?lstr39_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr39_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 8
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,212 :: 		Sound_play(G6,1000);                     //play G6 for 400 milisecond
	LDI        R27, 232
	MOV        R4, R27
	LDI        R27, 3
	MOV        R5, R27
	LDI        R27, 33
	MOV        R2, R27
	LDI        R27, 6
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,216 :: 		Lcd_Cmd(_LCD_CLEAR);                     //Clear LCD
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Buzzer.c,217 :: 		Delay_ms(1);                             //Wait for 1 milisecond
	LDI        R17, 21
	LDI        R16, 199
L_Twinkle17:
	DEC        R16
	BRNE       L_Twinkle17
	DEC        R17
	BRNE       L_Twinkle17
;Buzzer.c,218 :: 		Lcd_Cmd(_LCD_CLEAR);                     //Clear LCD
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Buzzer.c,219 :: 		Delay_ms(1);                             //wait for 1 milisecond
	LDI        R17, 21
	LDI        R16, 199
L_Twinkle19:
	DEC        R16
	BRNE       L_Twinkle19
	DEC        R17
	BRNE       L_Twinkle19
;Buzzer.c,220 :: 		Lcd_Out(1,1, "How");                     //Show 'How' on LCD
	LDI        R27, #lo_addr(?lstr40_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr40_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,221 :: 		Sound_play(F6,400);                      //play F6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 117
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,223 :: 		Lcd_Out(1,5, "I");                       //Show 'I' on LCD
	LDI        R27, #lo_addr(?lstr41_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr41_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 5
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,224 :: 		Sound_play(F6,400);                      //play F6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 117
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,226 :: 		Lcd_Out(1,7, "won");                     //Show 'Won' on LCD
	LDI        R27, #lo_addr(?lstr42_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr42_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 7
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,227 :: 		Sound_play(E6,400);                      //play F6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 39
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,229 :: 		Lcd_Out(1,10, "der");                    //Show 'der' on LCD
	LDI        R27, #lo_addr(?lstr43_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr43_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 10
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,230 :: 		Sound_play(E6,400);                      //play E6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 39
	MOV        R2, R27
	LDI        R27, 5
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,232 :: 		Lcd_Out(2,1, "what");                    //Show 'what' on LCD
	LDI        R27, #lo_addr(?lstr44_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr44_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 1
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,233 :: 		Sound_play(D6,400);                      //play D6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 151
	MOV        R2, R27
	LDI        R27, 4
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,235 :: 		Lcd_Out(2,6, "you");                     //Show 'you' on LCD
	LDI        R27, #lo_addr(?lstr45_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr45_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 6
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,236 :: 		Sound_play(D6,400);                      //play D6 for 400 milisecond
	LDI        R27, 144
	MOV        R4, R27
	LDI        R27, 1
	MOV        R5, R27
	LDI        R27, 151
	MOV        R2, R27
	LDI        R27, 4
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,238 :: 		Lcd_Out(2,10, "are!");                   //Show 'are' on LCD
	LDI        R27, #lo_addr(?lstr46_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr46_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 10
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,239 :: 		Sound_play(C6,1000);                     //play C6 for 400 milisecond
	LDI        R27, 232
	MOV        R4, R27
	LDI        R27, 3
	MOV        R5, R27
	LDI        R27, 23
	MOV        R2, R27
	LDI        R27, 4
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,243 :: 		Delay_ms(1000);                          //wait for 1000 milisecond
	LDI        R18, 82
	LDI        R17, 43
	LDI        R16, 0
L_Twinkle21:
	DEC        R16
	BRNE       L_Twinkle21
	DEC        R17
	BRNE       L_Twinkle21
	DEC        R18
	BRNE       L_Twinkle21
	NOP
	NOP
	NOP
	NOP
;Buzzer.c,244 :: 		Lcd_Cmd(_LCD_CLEAR);                     //clear LCD
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Buzzer.c,245 :: 		Delay_ms(1);                             //wait for 1 milisecond
	LDI        R17, 21
	LDI        R16, 199
L_Twinkle23:
	DEC        R16
	BRNE       L_Twinkle23
	DEC        R17
	BRNE       L_Twinkle23
;Buzzer.c,246 :: 		Lcd_Out(2,3, "Thank you!");              //Show 'Thank You' on LCD
	LDI        R27, #lo_addr(?lstr47_Buzzer+0)
	MOV        R4, R27
	LDI        R27, hi_addr(?lstr47_Buzzer+0)
	MOV        R5, R27
	LDI        R27, 3
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;Buzzer.c,247 :: 		Sound_Play(C7,100);                      //play C7 for 400 milisecond
	LDI        R27, 100
	MOV        R4, R27
	LDI        R27, 0
	MOV        R5, R27
	LDI        R27, 45
	MOV        R2, R27
	LDI        R27, 8
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,249 :: 		Delay_ms(20);                            //Wait for 20 milisecond
	LDI        R18, 2
	LDI        R17, 160
	LDI        R16, 147
L_Twinkle25:
	DEC        R16
	BRNE       L_Twinkle25
	DEC        R17
	BRNE       L_Twinkle25
	DEC        R18
	BRNE       L_Twinkle25
	NOP
;Buzzer.c,250 :: 		Sound_Play(C7,1500);                     //play C7 for 400 milisecond
	LDI        R27, 220
	MOV        R4, R27
	LDI        R27, 5
	MOV        R5, R27
	LDI        R27, 45
	MOV        R2, R27
	LDI        R27, 8
	MOV        R3, R27
	CALL       _Sound_Play+0
;Buzzer.c,252 :: 		}
L_end_Twinkle:
	POP        R5
	POP        R4
	POP        R3
	POP        R2
	RET
; end of _Twinkle
