section .text
global _start
_start:
  xor rdx, rdx ; remainder
  mov rax, 10
  mov rcx, 10
  div rcx
  mov rdi, rdx
  mov rax, 60
  syscall
