; Written/Pieced together by Jared Dyreson
; CPSC-240 TR @ 11:30 - 13:20
extern printf

section .data
format: db "Summation: %f, Mean: %f", 10, 0

array: dq 5.0, 17.6, 101.2, 8.1024, 1.0, 5.1, 4095.382, 0.825
sizeofarray: equ ($-array)/8
sum: dq 0.0
mean: dq 0.0
flt: dq 19.5
section .text
global	main

main:
	push rbp			; set up stack frame
	xor r15, r15 ; indexing
	lea rbx, [array]
	summation:
	cmp r15, sizeofarray
	je exit
	movsd xmm4, [rbx+r15*8] ; move the nth value of the array into a double variable
  addsd xmm4, [sum] ; add it to the sum variable
  movsd [sum], xmm4 ; move the contents of xmm0 into
	inc r15
	jmp summation
	exit:
	cvtsi2sd 	xmm5, r15
	movsd xmm1, [sum]
	divsd xmm1, xmm5
	movq qword[mean], xmm1
	mov	rdi, format
	movq	xmm0, qword [sum]
	movq xmm1, qword [mean]
	mov	rax, 1
	call	printf
	pop	rbp	; restore stack
  xor rax, rax
  ret
