; This shows the use of a for loop is Nasm
; Written by Jared Dyreson

global _start
_start:
xor r8, r8 ; int i = 0
mov r9, 10; int j = 10 (upper bound)
for_loop_block:
cmp r8, r9 ; i < 10 ?
jge exit ; true we break out of the loop
inc r8 ; ++i
jmp for_loop_block ; back to the for_loop_block label
exit:
mov rax, 60
mov rdi, r8 ; show that r8 will be 10 not 11 
syscall
