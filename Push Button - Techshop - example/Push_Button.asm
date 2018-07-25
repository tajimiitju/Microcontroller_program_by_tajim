
_main:
	LDI        R27, 255
	OUT        SPL+0, R27
	LDI        R27, 0
	OUT        SPL+1, R27

;Push_Button.c,26 :: 		void main()
;Push_Button.c,28 :: 		DDD2_bit = 0;                      // Make PORTD's PD2 as input
	IN         R27, DDD2_bit+0
	CBR        R27, BitMask(DDD2_bit+0)
	OUT        DDD2_bit+0, R27
;Push_Button.c,29 :: 		DDD3_bit = 0;                      // Make PORTD's PD3 as input
	IN         R27, DDD3_bit+0
	CBR        R27, BitMask(DDD3_bit+0)
	OUT        DDD3_bit+0, R27
;Push_Button.c,30 :: 		PORTD2_bit=1;                      // Pull up PD2
	IN         R27, PORTD2_bit+0
	SBR        R27, BitMask(PORTD2_bit+0)
	OUT        PORTD2_bit+0, R27
;Push_Button.c,31 :: 		PORTD3_bit=1;                      // Pull up PD3
	IN         R27, PORTD3_bit+0
	SBR        R27, BitMask(PORTD3_bit+0)
	OUT        PORTD3_bit+0, R27
;Push_Button.c,32 :: 		DDC0_bit = 1;                      // Make PORTC's PC0 as output
	IN         R27, DDC0_bit+0
	SBR        R27, BitMask(DDC0_bit+0)
	OUT        DDC0_bit+0, R27
;Push_Button.c,33 :: 		DDC1_bit = 1;                      // Make PORTC's PC1 as output
	IN         R27, DDC1_bit+0
	SBR        R27, BitMask(DDC1_bit+0)
	OUT        DDC1_bit+0, R27
;Push_Button.c,35 :: 		while(1)
L_main0:
;Push_Button.c,37 :: 		if(PIND2_bit == 0)              // Check if button 2 is pressed
	IN         R27, PIND2_bit+0
	SBRC       R27, BitPos(PIND2_bit+0)
	JMP        L_main2
;Push_Button.c,39 :: 		Delay_ms(80);                // wait 80 milisecond, for debounce effect
	LDI        R18, 7
	LDI        R17, 127
	LDI        R16, 80
L_main3:
	DEC        R16
	BRNE       L_main3
	DEC        R17
	BRNE       L_main3
	DEC        R18
	BRNE       L_main3
	NOP
	NOP
;Push_Button.c,40 :: 		PORTC0_bit = ~PORTC0_bit;    // Toggle PC0
	IN         R0, PORTC0_bit+0
	LDI        R27, BitMask(PORTC0_bit+0)
	EOR        R0, R27
	OUT        PORTC0_bit+0, R0
;Push_Button.c,41 :: 		while(PIND2_bit == 0);       // wait till button 2 is pressed
L_main5:
	IN         R27, PIND2_bit+0
	SBRC       R27, BitPos(PIND2_bit+0)
	JMP        L_main6
	JMP        L_main5
L_main6:
;Push_Button.c,42 :: 		}
L_main2:
;Push_Button.c,43 :: 		if(PIND3_bit == 0)              // Check if button 1 is pressed
	IN         R27, PIND3_bit+0
	SBRC       R27, BitPos(PIND3_bit+0)
	JMP        L_main7
;Push_Button.c,45 :: 		Delay_ms(80);                // wait 80 milisecond, for debounce effect
	LDI        R18, 7
	LDI        R17, 127
	LDI        R16, 80
L_main8:
	DEC        R16
	BRNE       L_main8
	DEC        R17
	BRNE       L_main8
	DEC        R18
	BRNE       L_main8
	NOP
	NOP
;Push_Button.c,46 :: 		PORTC1_bit = ~PORTC1_bit;    // Toggle PC1
	IN         R0, PORTC1_bit+0
	LDI        R27, BitMask(PORTC1_bit+0)
	EOR        R0, R27
	OUT        PORTC1_bit+0, R0
;Push_Button.c,47 :: 		while(PIND3_bit == 0);       // wait till button 1 is pressed
L_main10:
	IN         R27, PIND3_bit+0
	SBRC       R27, BitPos(PIND3_bit+0)
	JMP        L_main11
	JMP        L_main10
L_main11:
;Push_Button.c,48 :: 		}
L_main7:
;Push_Button.c,49 :: 		}
	JMP        L_main0
;Push_Button.c,51 :: 		}
L_end_main:
L__main_end_loop:
	JMP        L__main_end_loop
; end of _main
