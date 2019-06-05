; This program outlines multiplication
; Written by Jared Dyreson

global _start
_start:
mov eax, 3
mov edx, 4
mul edx
mov edi, eax ; eax stores the output
; xor rdx,rdx
mov rax, 60
syscall
