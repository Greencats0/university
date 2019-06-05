section .text
global _start
_start:
  mov eax, -65
  cdqe
  mov rax, 60
  mov rdi, 0
  syscall
