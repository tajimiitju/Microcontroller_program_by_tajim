
_main:
	LDI        R27, 255
	OUT        SPL+0, R27
	LDI        R27, 0
	OUT        SPL+1, R27
	IN         R28, SPL+0
	IN         R29, SPL+1
	SBIW       R28, 10
	OUT        SPL+0, R28
	OUT        SPL+1, R29
	ADIW       R28, 1

;Joystick.c,47 :: 		void main()
;Joystick.c,49 :: 		short x=1, y=5;                    // Declare two integer type variables
	PUSH       R2
	PUSH       R3
	PUSH       R4
	PUSH       R5
	LDI        R30, #lo_addr(?ICSmain_x_L0+0)
	LDI        R31, hi_addr(?ICSmain_x_L0+0)
	MOVW       R26, R28
	LDI        R24, 10
	LDI        R25, 0
	CALL       ___CC2DW+0
;Joystick.c,50 :: 		char txt[] = "Welcome";            // Keep the text " Welcome " in a characrter type array
;Joystick.c,52 :: 		DDRA = DDRA & 0x07;                // Setting PA3 to PA7 as output
	IN         R16, DDRA+0
	ANDI       R16, 7
	OUT        DDRA+0, R16
;Joystick.c,53 :: 		PORTA=0xF8;                        // Pulling up PA3 to PA7
	LDI        R27, 248
	OUT        PORTA+0, R27
;Joystick.c,55 :: 		Lcd_Init();                        // Initialize LCD
	CALL       _Lcd_Init+0
;Joystick.c,56 :: 		Lcd_Cmd(_LCD_CLEAR);               // Clear Display
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Joystick.c,57 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
	LDI        R27, 12
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Joystick.c,58 :: 		Lcd_Out(x, y, txt);                // Show "Welcome" on 1st row, 5th coloumn
	MOVW       R16, R28
	SUBI       R16, 254
	SBCI       R17, 255
	MOVW       R4, R16
	LDD        R3, Y+1
	LDD        R2, Y+0
	CALL       _Lcd_Out+0
;Joystick.c,60 :: 		while(1)
L_main0:
;Joystick.c,62 :: 		if(PINA3_bit==0)                // Check if the switch is in 'up' position
	IN         R27, PINA3_bit+0
	SBRC       R27, BitPos(PINA3_bit+0)
	JMP        L_main2
;Joystick.c,64 :: 		x=1;                          // Set the value of x as 1
	LDI        R27, 1
	STD        Y+0, R27
;Joystick.c,65 :: 		Lcd_Cmd(_LCD_CLEAR);          // Clear the LCD display
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Joystick.c,66 :: 		Lcd_Out(x, y, txt);           // Show "Welcome" on 1st row, yth coulumn,
	MOVW       R16, R28
	SUBI       R16, 254
	SBCI       R17, 255
	MOVW       R4, R16
	LDD        R3, Y+1
	LDD        R2, Y+0
	CALL       _Lcd_Out+0
;Joystick.c,67 :: 		while(PINA3_bit==0);          // Wait till the button is in 'up' position
L_main3:
	IN         R27, PINA3_bit+0
	SBRC       R27, BitPos(PINA3_bit+0)
	JMP        L_main4
	JMP        L_main3
L_main4:
;Joystick.c,68 :: 		}
L_main2:
;Joystick.c,70 :: 		if(PINA7_bit==0)                // Check if the switch is in 'down' position
	IN         R27, PINA7_bit+0
	SBRC       R27, BitPos(PINA7_bit+0)
	JMP        L_main5
;Joystick.c,72 :: 		x=2;                          // Set the value to x as
	LDI        R27, 2
	STD        Y+0, R27
;Joystick.c,73 :: 		Lcd_Cmd(_LCD_CLEAR);          // Clear the LCD display
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Joystick.c,74 :: 		Lcd_Out(x, y, txt);           // Show "Welcome" on 2nd row,yth coulumn
	MOVW       R16, R28
	SUBI       R16, 254
	SBCI       R17, 255
	MOVW       R4, R16
	LDD        R3, Y+1
	LDD        R2, Y+0
	CALL       _Lcd_Out+0
;Joystick.c,75 :: 		while(PINA7_bit==0);          // Wait till the button is in 'down'position
L_main6:
	IN         R27, PINA7_bit+0
	SBRC       R27, BitPos(PINA7_bit+0)
	JMP        L_main7
	JMP        L_main6
L_main7:
;Joystick.c,76 :: 		}
L_main5:
;Joystick.c,78 :: 		if(PINA4_bit==0)                // Check if the switch is in 'middle' position
	IN         R27, PINA4_bit+0
	SBRC       R27, BitPos(PINA4_bit+0)
	JMP        L_main8
;Joystick.c,80 :: 		y=5;                          // Set the value of y as 5
	LDI        R27, 5
	STD        Y+1, R27
;Joystick.c,81 :: 		Lcd_Cmd(_LCD_CLEAR);          // Clear the LCD display
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Joystick.c,82 :: 		Lcd_Out(x, y, txt);           // Show "Welcome" on xth row, 5th coulumn
	MOVW       R16, R28
	SUBI       R16, 254
	SBCI       R17, 255
	MOVW       R4, R16
	LDD        R3, Y+1
	LDD        R2, Y+0
	CALL       _Lcd_Out+0
;Joystick.c,83 :: 		while(PINA4_bit==0);          // Wait till the button is in 'middle' Position
L_main9:
	IN         R27, PINA4_bit+0
	SBRC       R27, BitPos(PINA4_bit+0)
	JMP        L_main10
	JMP        L_main9
L_main10:
;Joystick.c,84 :: 		}
L_main8:
;Joystick.c,86 :: 		if(PINA5_bit==0)                // Check if the switch is in 'left' position
	IN         R27, PINA5_bit+0
	SBRC       R27, BitPos(PINA5_bit+0)
	JMP        L_main11
;Joystick.c,88 :: 		y--;                          // Decrease the value of y i.e. coulumn by 1
	LDD        R16, Y+1
	SUBI       R16, 1
	STD        Y+1, R16
;Joystick.c,89 :: 		if(y<1)                       // If coulumn number is less than 1
	CPI        R16, 1
	BRLT       L__main20
	JMP        L_main12
L__main20:
;Joystick.c,91 :: 		y=1;                       // Keep the value 1
	LDI        R27, 1
	STD        Y+1, R27
;Joystick.c,92 :: 		}
L_main12:
;Joystick.c,93 :: 		Lcd_Cmd(_LCD_CLEAR);          // Clear the LCD display
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Joystick.c,94 :: 		Lcd_Out(x, y, txt);           // Show "Welcome" on xth row, yth coulumn
	MOVW       R16, R28
	SUBI       R16, 254
	SBCI       R17, 255
	MOVW       R4, R16
	LDD        R3, Y+1
	LDD        R2, Y+0
	CALL       _Lcd_Out+0
;Joystick.c,95 :: 		while(PINA5_bit==0);          // Wait till the button 'Left' is pressed
L_main13:
	IN         R27, PINA5_bit+0
	SBRC       R27, BitPos(PINA5_bit+0)
	JMP        L_main14
	JMP        L_main13
L_main14:
;Joystick.c,96 :: 		}
L_main11:
;Joystick.c,98 :: 		if(PINA6_bit==0)                // Check if the switch is in 'Right' position
	IN         R27, PINA6_bit+0
	SBRC       R27, BitPos(PINA6_bit+0)
	JMP        L_main15
;Joystick.c,100 :: 		y++;
	LDD        R16, Y+1
	MOV        R17, R16
	SUBI       R17, 255
	STD        Y+1, R17
;Joystick.c,101 :: 		if(y>10)
	LDI        R16, 10
	CP         R16, R17
	BRLT       L__main21
	JMP        L_main16
L__main21:
;Joystick.c,103 :: 		y=10;
	LDI        R27, 10
	STD        Y+1, R27
;Joystick.c,104 :: 		}
L_main16:
;Joystick.c,105 :: 		Lcd_Cmd(_LCD_CLEAR);          // Clear the LCD display
	LDI        R27, 1
	MOV        R2, R27
	CALL       _Lcd_Cmd+0
;Joystick.c,106 :: 		Lcd_Out(x, y, txt);           // Show "Welcome" on xth row, yth coulumn
	MOVW       R16, R28
	SUBI       R16, 254
	SBCI       R17, 255
	MOVW       R4, R16
	LDD        R3, Y+1
	LDD        R2, Y+0
	CALL       _Lcd_Out+0
;Joystick.c,107 :: 		while(PINA6_bit==0);
L_main17:
	IN         R27, PINA6_bit+0
	SBRC       R27, BitPos(PINA6_bit+0)
	JMP        L_main18
	JMP        L_main17
L_main18:
;Joystick.c,108 :: 		}
L_main15:
;Joystick.c,109 :: 		}
	JMP        L_main0
;Joystick.c,110 :: 		}
L_end_main:
L__main_end_loop:
	JMP        L__main_end_loop
; end of _main
