section .text
global _start
_start:
  mov r8, 19
  mov r9, 20
  add r8, r9
  mov rdi, r8
  mov rax, 60
  syscall
