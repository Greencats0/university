section .text
global _start
_start:
  ; xor rdx, rdx
  mov rax, 10
  mov rdx, 10
  mul rdx
  mov rdi, rax
  mov rax, 60
  syscall
