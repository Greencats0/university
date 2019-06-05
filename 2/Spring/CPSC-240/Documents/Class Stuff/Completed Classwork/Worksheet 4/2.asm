; Written by Jared Dyreson
; C-Code
; while(quitReturnCode != 0) { quitFileDescriptor = quitReturnCode; }

%define RAISE_SYSTEM_EXIT 60
%define EXIT_STATUS 0

global _start
section .text
_start:
mov r11, 10 ;  this is not to result in an infinite loop (quitReturnCode)
xor r12, r12 ; quitReturnCode
while_loop_entry:
cmp r11, 0 ; if quitReturnCode is zero, then break
mov r12, r11 ; assignment
dec r11 ; decrease counter
jne while_loop_entry ; then proceed to leave (NOT do while where the condition is checked before proceeding)
je break
break:
mov rax, RAISE_SYSTEM_EXIT
mov rdi, EXIT_STATUS
syscall
