section .text
global _start
_start:
  mov al, [number]
  lea rbx, [table]
  mov [number], al
  xlat
  mov byte[number], al
  mov rsi, number
  mov rdx, 2
  mov rax, 1
  syscall
  mov rax, 60
  mov rdi, 0
  syscall

section .data
number: db 15, 10
table: db "0123456789ABCDEF"
