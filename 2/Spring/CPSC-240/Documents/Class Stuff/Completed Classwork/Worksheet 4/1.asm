; Written by Jared Dyreson
; C-Code
; if(quitReturnCode != 0){ quitFileDescriptor = quitReturnCode; }
; else { quitFileDescriptor = 0; }

%define RAISE_SYSTEM_EXIT 60
%define EXIT_STATUS 0

section .text
global _start

file_assignment:
mov r11, r12
jmp continuity

zero_assignment:
xor r12, r12 ; clear/set quitFileDescriptor equal to zero
jmp continuity

_start:
xor r11,r11 ; quitReturnCode
xor r12,r12 ; quitFileDescriptor
mov r11, 10 ; some arbitrary number for quitReturnCode which will satisfy the if block
cmp r11, 0 ; check if the value is set to zero
jne file_assignment
je zero_assignment
continuity:
mov rax, RAISE_SYSTEM_EXIT ; we want to exit
mov rdi, EXIT_STATUS ; return 0
syscall ; invoke
