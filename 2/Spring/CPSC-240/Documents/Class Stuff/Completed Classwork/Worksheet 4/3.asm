; Written by Jared Dyreson
; C-Code
; do { quitTotalCost = quitTotalCost + quitPrice; } while (quitTotalCost < 1000)

global _start
section .text
_start:
xor r11, r11 ; quitTotalCost
mov r12, 999 ; quitPrice
; this loop is intended to only twice for speed
do_while_block:
add r11, r12 ; add <dst> <src>
cmp r11, 1000 ; our conditional statement
jl do_while_block ; continue doing the statement if the number is less than 1000
jnl break ; break if the opposite is true
break:
mov rax, 60
mov rdi, r12 ; just to see what the ouput would have been <./ouput ; echo $?> turns out i can't display 1000 but its there
syscall
