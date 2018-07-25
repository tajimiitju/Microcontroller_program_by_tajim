
_main:
	LDI        R27, 255
	OUT        SPL+0, R27
	LDI        R27, 0
	OUT        SPL+1, R27

;Led_blinking.c,26 :: 		void main()
;Led_blinking.c,28 :: 		DDRC = 0xFF;                // Set PORTC as output
	LDI        R27, 255
	OUT        DDRC+0, R27
;Led_blinking.c,29 :: 		while (1)
L_main0:
;Led_blinking.c,31 :: 		PORTC = 0xFF;             //Turn ON all the LEDs
	LDI        R27, 255
	OUT        PORTC+0, R27
;Led_blinking.c,32 :: 		Delay_ms(1000);           //Wait for 1 second
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
;Led_blinking.c,33 :: 		PORTC = 0x00;             //Turn OFF all the LEDs
	LDI        R27, 0
	OUT        PORTC+0, R27
;Led_blinking.c,34 :: 		Delay_ms(1000);           //Wait for 1 second
	LDI        R18, 82
	LDI        R17, 43
	LDI        R16, 0
L_main4:
	DEC        R16
	BRNE       L_main4
	DEC        R17
	BRNE       L_main4
	DEC        R18
	BRNE       L_main4
	NOP
	NOP
	NOP
	NOP
;Led_blinking.c,35 :: 		}
	JMP        L_main0
;Led_blinking.c,36 :: 		}
L_end_main:
L__main_end_loop:
	JMP        L__main_end_loop
; end of _main
