; this program demonstrates subtraction
; Written by Jared Dyreson

global _start
_start:
mov r9, 10
mov r8, 5
sub r9, r8
mov rdi, r9
mov rax, 60
syscall
