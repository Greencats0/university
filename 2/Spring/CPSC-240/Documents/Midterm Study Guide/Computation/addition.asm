; This program outlines addition in nasm
; Written by Jared Dyreson

global _start
_start:
mov r9, 10
mov r10, 10
add r9, r10
mov rdi, r9
mov rax, 60
syscall
