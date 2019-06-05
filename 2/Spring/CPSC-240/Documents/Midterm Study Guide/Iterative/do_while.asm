; This program shows a do while block
; Written by Jared Dyreson

global _start
_start:
xor r8, r8
do_while_block:
inc r8
cmp r8, 1
je exit
jmp do_while_block
exit:
mov rax, 60
mov rdi, r8
syscall
