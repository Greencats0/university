global main
; introduction to NASM -> https://nullprogram.com/blog/2015/05/15/
extern printf
extern pthread_create
extern pthread_join
extern pthread_self
extern pthread_mutex_lock
extern pthread_mutex_unlock

%define MAX_THREADS 2
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
	cmp qword[i], MAX_THREADS
	je join_loop_ends
	mov rdi, [pthread_ids+(r8*8)]
	mov rsi, NULL
	call pthread_join
	inc qword[i]
	jmp join_loop

	join_loop_ends:
	ret
function_called:
 	mov r9, rdi ; save the value of rdi
        mov rdi, message 
        mov rsi, fmt
        mov rcx, message_len
        call printf
 	mov rdi, r9
	ret

section .data

message: db "Hello", 10
message_len: equ $-message
fmt: db "%s", 10 
i: dq 

section .bss
pthread_ids resq MAX_THREADS
