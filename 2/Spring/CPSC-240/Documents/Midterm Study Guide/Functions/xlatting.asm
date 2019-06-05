; This program illustrates the use of xlat which finds positional offsets from a given string
; Written by Jared Dyreson

global _start
_start:
lea rbx, [table]
mov al, 15
xlat
mov dil, al ; 0x70 is stored inside this register, therefore the letter F is essentially displayed
mov rax, 60
syscall
section .data
table: db "0123456789ABCDEF", 0xA
