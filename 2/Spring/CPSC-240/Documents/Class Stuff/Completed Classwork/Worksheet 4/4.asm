; Written by Jared Dyreson
; C-Code
; for(int i = 0; i < 10; ++i){ if(i%2 == 0) { quitSum+=i; } }
; output should be 25; the program increments every other time

global _start
section .text

assign:
add r13, r11 ; quitSum+=i
inc r11 ; ++i
jmp for_loop_block ; return to for loop

_start:
xor r11,r11 ; this is is our indexer (int i = 0 )
mov r12, 10 ; our terminating condition
xor r13, r13 ; quitSum

; for loop block begins
for_loop_block:
cmp r11, r12 ; i < 10
jl continuity ; execute for loop body
jnl break ; leave if we are i == 10

continuity:
xor rdx, rdx ; remainder
mov rbx, 2 ; divisor
mov rax, r11 ; dividend
div rbx
cmp rdx, 0 ;if i %2 == 0 (no remainder)
je assign ; ^ jump to adding instruction
; else increment counter and return to head of for loop
inc r11
jmp for_loop_block

break:
mov rax, 60
mov rdi, r13
syscall
