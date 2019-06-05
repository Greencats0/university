; This program demonstrates how to perform a simple encryption algorithm in NASM
; Written by Jared Dyreson

%include "printing.asm"

global _start
_start:
mov rsi, message
mov rdx, message_len
call print
encrypt:
; r8 : position in the string
; r9 : position in the key
cmp 
mov rax, 60
syscall
section .text
message: db "This is a message that will be encrypted", 0xA
message_len: equ $-message
encryption_key: db 0xA, 0xB, 0xC, 0xD
