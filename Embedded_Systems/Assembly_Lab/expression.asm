;;*****************************************************************************
;;
;;	  Assembly language subroutine
;;
;;		Author: 	Stephen Longofono
;;		Organization:	KU/EECS/EECS 388
;;		Date:		April 15, 2016
;;
;;		Purpose:	This short program demonstrates our understanding of basic
;		                applications of assembly instructions.  We were assigned a
;;              		set of expressions to evaluate within a single subroutine call.
;;      			This subroutine was called within a C program, which varied the
;;      		        values of the parameters over a range of numbers and verified
;;      		        the result of each set of parameters.
;;
;;		Notes:  	Conceived by Gary Minden, Modified by Stephen Longofono
;;
;;*****************************************************************************
;;


;;	Declare sections and external references

		.global		asmCompute	; Declare entry point as a global symbol

		.text				; Program sections

		asmCompute:			; Entry point

;;	This subroutine computes the following:
;;      X = A - D ^ A * C + A - B & A 
;;      Y = B | D / C - B + D + C + A 
;;      RESULT = X + Y

;;  	Compute X
;;	Everything onto the stack
		PUSH		{R5}
		PUSH		{R6}
		PUSH		{R7}
		PUSH		{R8}
		MOV		R5, R0	;r5 now holds a
		MOV		R6, R1	;r6 now holds b
		MOV		R7, R2	;r7 now holds c
		MOV		R8, R3	;r8 now holds d

;;	Multiply a,c

		MOV		R0, R5	;copy of a
		MULS		R0, R0, R7 ;multiply a by c into R0

;;	Add result to a
		ADDS		R0, R0, R5

;;	Subtract b from result
		SUBS		R0, R0, R6

;;	Bitwise AND, a and result
		AND		R0, R0, R5

;;	Subtract d from a
		MOV		R1, R5
		SUBS		R1, R1, R8

;;	Xor last two results
		EOR		R0, R0, R1

;;	Store result
		MOV		R3, R0

;;  	Compute Y

;;	Divide d by c
		MOV		R0, R8
		SDIVS		R0, R0, R7

;;	Subtract b from result
		SUBS		R0, R0, R6

;;	Add d to result
		ADDS		R0, R0, R8

;;	Add c to result
		ADDS		R0, R0,	R7

;;	Add a to result
		ADDS		R0, R0, R5

;;	OR b and result
		ORRS		R0, R0, R6

;;  	Compute RESULT
		ADDS		R0,	R0, R3

;;	Clean up
		POP		{R8}
		POP		{R7}
		POP		{R6}
		POP		{R5}
;;

;;	Return from the subroutine with the result in R0
;;
		BX		LR	; Branch to the program address in the Link Register

		.end
