; This program demonstrates a while loop in NASM
; Written by Jared Dyreson

; same procedure as a for loop but in reverse essentially
; C Code
; number = 10; while(number != 0) { --number; }
global _start
_start:
mov r8, 10
while_loop_block:
cmp r8, 0
je exit
dec r8
jmp while_loop_block
exit:
mov rax, 60
syscall
