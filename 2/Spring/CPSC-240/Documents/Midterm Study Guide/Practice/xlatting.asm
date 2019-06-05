section .text
global _start
_start:
  cmp byte[number], 16
  je exit
  lea rbx, [table]
  ; mov rdi, 1
  mov al, byte[number]
  xlat
  mov byte[number], al
  mov rsi, number
  mov rax, 1
  mov rdx, 2
  syscall
  exit:
  mov rax, 60
  xor rdi, rdi
  syscall


section .data
table: db "0123456789ABCDEF"
number: db 14, 10
