
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

;ADC_Interfacing.c,28 :: 		void main()
;ADC_Interfacing.c,31 :: 		char display[10]= {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; // CC value of 0-9.
	LDI        R30, #lo_addr(?ICSmain_display_L0+0)
	LDI        R31, hi_addr(?ICSmain_display_L0+0)
	MOVW       R26, R28
	LDI        R24, 10
	LDI        R25, 0
	CALL       ___CC2DW+0
;ADC_Interfacing.c,34 :: 		DDRA=0x00;         // Declaring PORTA as input
	LDI        R27, 0
	OUT        DDRA+0, R27
;ADC_Interfacing.c,35 :: 		DDRB=0xFF;         // Declaring PORTB as output
	LDI        R27, 255
	OUT        DDRB+0, R27
;ADC_Interfacing.c,36 :: 		ADEN_bit=1;        // ADC enable
	IN         R27, ADEN_bit+0
	SBR        R27, 128
	OUT        ADEN_bit+0, R27
;ADC_Interfacing.c,37 :: 		REFS0_bit=1;       // Voltage Reference Selection, AVCC(~5V) with external capacitor at AREF pin (Slide down the SW2 switch)
	IN         R27, REFS0_bit+0
	SBR        R27, 64
	OUT        REFS0_bit+0, R27
;ADC_Interfacing.c,38 :: 		ADCSRA|=(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);   // ADC Prescaler Selections,selecting division factor=128
	IN         R16, ADCSRA+0
	ORI        R16, 7
	OUT        ADCSRA+0, R16
;ADC_Interfacing.c,40 :: 		while(1)
L_main0:
;ADC_Interfacing.c,42 :: 		ADSC_bit = 1;      // ADC Start Conversion
	IN         R27, ADSC_bit+0
	SBR        R27, 64
	OUT        ADSC_bit+0, R27
;ADC_Interfacing.c,43 :: 		while(ADSC_bit!=0);// Wait till conversion finish
L_main2:
	IN         R27, ADSC_bit+0
	SBRS       R27, 6
	JMP        L_main3
	JMP        L_main2
L_main3:
;ADC_Interfacing.c,44 :: 		low = ADCL;        // Store lower eight bits of ADC conversion in 'low'
; low start address is: 18 (R18)
	IN         R18, ADCL+0
;ADC_Interfacing.c,45 :: 		hi = ADCH;         // Store upper eight bits of ADC conversion in 'hi'
; hi start address is: 19 (R19)
	IN         R19, ADCH+0
;ADC_Interfacing.c,46 :: 		adc_value = (hi<<8)+low; //Shift 'hi' 8 steps right and add 'low' with it
	MOV        R17, R19
	CLR        R16
; hi end address is: 19 (R19)
	ADD        R16, R18
	LDI        R27, 0
	ADC        R17, R27
; low end address is: 18 (R18)
	LDI        R18, 0
	MOV        R19, R18
	CALL       _float_ulong2fp+0
; adc_value start address is: 20 (R20)
	MOVW       R20, R16
	MOVW       R22, R18
;ADC_Interfacing.c,48 :: 		adc_value = (9*adc_value)/1023; //Analog to digital conversion, Precision=5/1023.
	LDI        R16, 0
	LDI        R17, 0
	LDI        R18, 16
	LDI        R19, 65
	CALL       _float_fpmul1+0
; adc_value end address is: 20 (R20)
	LDI        R20, 0
	LDI        R21, 192
	LDI        R22, 127
	LDI        R23, 68
	CALL       _float_fpdiv1+0
; adc_value start address is: 20 (R20)
	MOVW       R20, R16
	MOVW       R22, R18
;ADC_Interfacing.c,49 :: 		decimal = adc_value;// Store the decimal value and omit other.
	MOVW       R16, R20
	MOVW       R18, R22
	CALL       _float_fpint+0
; adc_value end address is: 20 (R20)
; decimal start address is: 18 (R18)
	MOV        R18, R16
;ADC_Interfacing.c,50 :: 		PORTB = display[decimal]; // Show the value in 7-segment connected to PORTB
	MOVW       R16, R28
	MOV        R30, R18
	LDI        R31, 0
	ADD        R30, R16
	ADC        R31, R17
; decimal end address is: 18 (R18)
	LD         R16, Z
	OUT        PORTB+0, R16
;ADC_Interfacing.c,51 :: 		}
	JMP        L_main0
;ADC_Interfacing.c,52 :: 		}
L_end_main:
L__main_end_loop:
	JMP        L__main_end_loop
; end of _main
