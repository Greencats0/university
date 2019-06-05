global main
; introduction to NASM -> https://nullprogram.com/blog/2015/05/15/
extern printf
extern pthread_create
extern pthread_join
extern pthread_self
extern pthread_mutex_lock
extern pthread_mutex_unlock

%define MAX_THREADS 6
%define NULL 0

section .text
main:
	push rbp
	mov rbp, rsp
	mov qword[i], 0

	for_loop_block:
	cmp qword[i], MAX_THREADS
	je for_loop_break	
	; pthread_create( &thread_id[i], NULL, thread_function, NULL ); 
	mov r8, qword[i]
	lea rdi, [pthread_ids+(r8*8)]
	mov rsi, NULL
	mov rdx, function_called
	mov rcx, qword[i]
	call pthread_create
	inc qword[i]
	jmp for_loop_block

	for_loop_break:
	mov qword[i], 0
	join_loop:
	cmp qword[i], RANGE_EACH_THREAD
	je join_loop_ends
	mov rdi, [pthread_ids+(r8*8)]
	mov rsi, NULL
	call pthread_join
	inc qword[i]
	jmp join_loop

	join_loop_ends:
	mov rsi, qword[from]
	mov rdi, format
	xor rax, rax
	call printf
	ret
function_called:
	; give it from=(threadIndex * RANGE_EACH_THREAD) + 1
 	mov r9, rdi ; save the value of rdi

	mov rax, qword[i]
	mov rdx, RANGE_EACH_THREAD
	mul rdx
	mov qword[from], rax
	inc qword[from]

	loop_block:
	cmp qword[from], RANGE_EACH_THREAD
	je loop_break
	inc qword[from]
;	xor rdx, rdx
;	mov rax, NUMBER_TO_FACTOR
;	mov rcx, 2
;	div rcx
;	jz is_factor
;	jmp loop_block
;	is_factor:
;	inc qword[total_factor_count]
	jmp loop_block
	loop_break:

	;compute_label:
	;inc r10
        ;print_label:
        ;mov rsi, r10
        ;mov rdi, format 
	;xor rax, rax
	;call printf
	mov rdi, r9
	ret

section .data

i: dq 0
j: dq 0
format: db "%i", 10, 0
total_factor_count: dq 0
destination: dq 0
from: dq 0
NUMBER_TO_FACTOR equ 1000000000
RANGE_EACH_THREAD equ NUMBER_TO_FACTOR / MAX_THREADS



section .bss
pthread_ids resq MAX_THREADS

