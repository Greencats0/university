global main

extern printf
extern pthread_create
extern pthread_join

%define MAX_THREADS 2
%define NUMBER_TO_FACTOR 100
%define RANGE_EACH_THREAD NUMBER_TO_FACTOR/MAX_THREADS

section .text

main:
	push rbp
	mov rbp, rsp

	; setting up the outer for loop
	; there should be 100 factors that divide evenly into one billion
	mov qword[i], 0
	outer_for_loop:
	cmp qword[i], MAX_THREADS
	jge outer_loop_break

	; meat of the program goes here
	; define our inner loop which makes us do weird things
	; test by using the MAX_THREADS constant again

	inner_for_loop:
	cmp qword[j], MAX_THREADS
	jge inner_loop_break
	mov rdx, qword[divide]
	cqo
	mov rcx, qword[i]
	div rdx
	jz increment
	jmp inner_loop_break
	;mov rax, 1
	;mov rbx, qword[i]
	;div rbx
	increment:
	inc qword[i]
	inner_loop_break:
	jmp outer_loop_break

	; end of the actual driver code
	outer_loop_break:
	ret
section .data

i: dq 0
j: dq 0
divide: dq 100
