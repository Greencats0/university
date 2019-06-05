; This program outlines division in nasm
; Written by Jared Dyreson

global _start
_start:
xor edx, edx
mov eax, 10 ; dividend
mov ecx, 5 ; divisor
div ecx
mov edi, eax ; quotient is stored in eax
mov rax, 60
syscall
