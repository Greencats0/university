section .text
global _start
_start:
  mov r9, 10
  mov r10, 5
  sub r10, r9
  mov rdi, r10
  mov rax, 60
  syscall
