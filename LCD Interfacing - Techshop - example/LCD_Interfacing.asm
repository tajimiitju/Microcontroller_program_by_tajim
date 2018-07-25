
_main:
	LDI        R27, 255
	OUT        SPL+0, R27
	LDI        R27, 0
	OUT        SPL+1, R27
	IN         R28, SPL+0
	IN         R29, SPL+1
	SBIW       R28, 1
	OUT        SPL+0, R28
	OUT        SPL+1, R29
	ADIW       R28, 1

;LCD_Interfacing.c,47 :: 		void main()
;LCD_Interfacing.c,51 :: 		Lcd_Init();                  // Initialize LCD
	PUSH       R2
	PUSH       R3
	PUSH       R4
	PUSH       R5
	CALL       _Lcd_Init+0
;LCD_Interfacing.c,52 :: 		Lcd_Cmd(_LCD_CLEAR);         // Clear display
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;LCD_Interfacing.c,53 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);    // Cursor off
	LDI        R27, 12
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;LCD_Interfacing.c,55 :: 		Lcd_Out(1,4,txt3);           // Write text in first row
	LDI        R27, #lo_addr(_txt3+0)
	MOV        R4, R27
	LDI        R27, hi_addr(_txt3+0)
	MOV        R5, R27
	LDI        R27, 4
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;LCD_Interfacing.c,56 :: 		Lcd_Out(2,4,txt4);           // Write text in second row
	LDI        R27, #lo_addr(_txt4+0)
	MOV        R4, R27
	LDI        R27, hi_addr(_txt4+0)
	MOV        R5, R27
	LDI        R27, 4
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;LCD_Interfacing.c,57 :: 		Delay_ms(2000);
	LDI        R18, 163
	LDI        R17, 87
	LDI        R16, 3
L_main0:
	DEC        R16
	BRNE       L_main0
	DEC        R17
	BRNE       L_main0
	DEC        R18
	BRNE       L_main0
	NOP
;LCD_Interfacing.c,58 :: 		Lcd_Cmd(_LCD_CLEAR);         // Clear display
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;LCD_Interfacing.c,60 :: 		Lcd_Out(1,4,txt1);           // Write text in first row
	LDI        R27, #lo_addr(_txt1+0)
	MOV        R4, R27
	LDI        R27, hi_addr(_txt1+0)
	MOV        R5, R27
	LDI        R27, 4
	MOV        R3, R27
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Out+0
;LCD_Interfacing.c,61 :: 		Lcd_Out(2,5,txt2);           // Write text in second row
	LDI        R27, #lo_addr(_txt2+0)
	MOV        R4, R27
	LDI        R27, hi_addr(_txt2+0)
	MOV        R5, R27
	LDI        R27, 5
	MOV        R3, R27
	LDI        R27, 2
	MOV        R2, R27
	CALL       _Lcd_Out+0
;LCD_Interfacing.c,62 :: 		Delay_ms(1000);
	LDI        R18, 82
	LDI        R17, 43
	LDI        R16, 0
L_main2:
	DEC        R16
	BRNE       L_main2
	DEC        R17
	BRNE       L_main2
	DEC        R18
	BRNE       L_main2
	NOP
	NOP
	NOP
	NOP
;LCD_Interfacing.c,65 :: 		for(i=0; i<4; i++)           // Move text to the right 4 times
	LDI        R27, 0
	STD        Y+0, R27
L_main4:
	LDD        R16, Y+0
	CPI        R16, 4
	BRLO       L__main22
	JMP        L_main5
L__main22:
;LCD_Interfacing.c,67 :: 		Lcd_Cmd(_LCD_SHIFT_RIGHT);
	LDI        R27, 28
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;LCD_Interfacing.c,68 :: 		Delay_ms(500);
	LDI        R18, 41
	LDI        R17, 150
	LDI        R16, 128
L_main7:
	DEC        R16
	BRNE       L_main7
	DEC        R17
	BRNE       L_main7
	DEC        R18
	BRNE       L_main7
;LCD_Interfacing.c,65 :: 		for(i=0; i<4; i++)           // Move text to the right 4 times
	LDD        R16, Y+0
	SUBI       R16, 255
	STD        Y+0, R16
;LCD_Interfacing.c,69 :: 		}
	JMP        L_main4
L_main5:
;LCD_Interfacing.c,70 :: 		while(1)                     // Endless loop
L_main9:
;LCD_Interfacing.c,72 :: 		for(i=0; i<4; i++)         // Move text to the left 4 times
	LDI        R27, 0
	STD        Y+0, R27
L_main11:
	LDD        R16, Y+0
	CPI        R16, 4
	BRLO       L__main23
	JMP        L_main12
L__main23:
;LCD_Interfacing.c,74 :: 		Lcd_Cmd(_LCD_SHIFT_LEFT);
	LDI        R27, 24
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;LCD_Interfacing.c,75 :: 		Delay_ms(500);
	LDI        R18, 41
	LDI        R17, 150
	LDI        R16, 128
L_main14:
	DEC        R16
	BRNE       L_main14
	DEC        R17
	BRNE       L_main14
	DEC        R18
	BRNE       L_main14
;LCD_Interfacing.c,72 :: 		for(i=0; i<4; i++)         // Move text to the left 4 times
	LDD        R16, Y+0
	SUBI       R16, 255
	STD        Y+0, R16
;LCD_Interfacing.c,76 :: 		}
	JMP        L_main11
L_main12:
;LCD_Interfacing.c,78 :: 		for(i=0; i<4; i++)         // Move text to the right 4 times
	LDI        R27, 0
	STD        Y+0, R27
L_main16:
	LDD        R16, Y+0
	CPI        R16, 4
	BRLO       L__main24
	JMP        L_main17
L__main24:
;LCD_Interfacing.c,80 :: 		Lcd_Cmd(_LCD_SHIFT_RIGHT);
	LDI        R27, 28
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;LCD_Interfacing.c,81 :: 		Delay_ms(500);
	LDI        R18, 41
	LDI        R17, 150
	LDI        R16, 128
L_main19:
	DEC        R16
	BRNE       L_main19
	DEC        R17
	BRNE       L_main19
	DEC        R18
	BRNE       L_main19
;LCD_Interfacing.c,78 :: 		for(i=0; i<4; i++)         // Move text to the right 4 times
	LDD        R16, Y+0
	SUBI       R16, 255
	STD        Y+0, R16
;LCD_Interfacing.c,82 :: 		}
	JMP        L_main16
L_main17:
;LCD_Interfacing.c,83 :: 		}
	JMP        L_main9
;LCD_Interfacing.c,84 :: 		}
L_end_main:
L__main_end_loop:
	JMP        L__main_end_loop
; end of _main
