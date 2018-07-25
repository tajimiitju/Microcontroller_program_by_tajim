
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

;seven_segment_display.c,2 :: 		void main() {
;seven_segment_display.c,3 :: 		int i=0;
;seven_segment_display.c,8 :: 		char number[] = {0x3F, 0x86, 0x5B, 0xCF, 0x66, 0xED, 0x7D, 0x87, 0x7F, 0xEF};
	LDI        R30, #lo_addr(?ICSmain_number_L0+0)
	LDI        R31, hi_addr(?ICSmain_number_L0+0)
	MOVW       R26, R28
	LDI        R24, 10
	LDI        R25, 0
	CALL       ___CC2DW+0
;seven_segment_display.c,10 :: 		DDRB = 0xFF;                   // Configure PORTB as input
	LDI        R27, 255
	OUT        DDRB+0, R27
;seven_segment_display.c,12 :: 		while (1)
L_main0:
;seven_segment_display.c,14 :: 		for (i=0; i<=9; i++)
; i start address is: 18 (R18)
	LDI        R18, 0
	LDI        R19, 0
; i end address is: 18 (R18)
L_main2:
; i start address is: 18 (R18)
	LDI        R16, 9
	LDI        R17, 0
	CP         R16, R18
	CPC        R17, R19
	BRGE       L__main8
	JMP        L_main3
L__main8:
;seven_segment_display.c,16 :: 		PORTB = number[i];
	MOVW       R16, R28
	MOVW       R30, R18
	ADD        R30, R16
	ADC        R31, R17
	LD         R16, Z
	OUT        PORTB+0, R16
;seven_segment_display.c,17 :: 		Delay_ms(700);
	PUSH       R19
	PUSH       R18
	LDI        R18, 57
	LDI        R17, 210
	LDI        R16, 77
L_main5:
	DEC        R16
	BRNE       L_main5
	DEC        R17
	BRNE       L_main5
	DEC        R18
	BRNE       L_main5
	NOP
	POP        R18
	POP        R19
;seven_segment_display.c,14 :: 		for (i=0; i<=9; i++)
	MOVW       R16, R18
	SUBI       R16, 255
	SBCI       R17, 255
	MOVW       R18, R16
;seven_segment_display.c,18 :: 		}
; i end address is: 18 (R18)
	JMP        L_main2
L_main3:
;seven_segment_display.c,19 :: 		}
	JMP        L_main0
;seven_segment_display.c,20 :: 		}
L_end_main:
L__main_end_loop:
	JMP        L__main_end_loop
; end of _main
