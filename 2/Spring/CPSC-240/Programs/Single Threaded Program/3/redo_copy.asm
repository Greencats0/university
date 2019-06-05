global main

extern printf

section .text

main:
	push rbp
	mov rbp, rsp

	; we first need to divide up the amount of threads
	xor rdx, rdx
	mov rax, 10 ; dividend
	mov rcx, 5 ; divisor
	div rcx
	mov qword[total_factor_count], rax

	mov rdi, format
	mov rsi, qword[total_factor_count]
	call print_number 


	ret

; function call compute_number(dividend=r8, divisor=r9)

print_number:
	push rdi
	push rsi
	push rdx
	mov rdi, format
	xor rax, rax
	call printf

	pop rdi
	pop rsi
	ret

section .data
i: dq 0
format: db "%i", 10, 0
total_factor_count: dq 0
destination: dq 0
from: dq 0
NUMBER_TO_FACTOR equ 10000000000
RANGE_EACH_THREAD equ NUMBER_TO_FACTOR / 2

section .bss
pthread_ids resq 2
