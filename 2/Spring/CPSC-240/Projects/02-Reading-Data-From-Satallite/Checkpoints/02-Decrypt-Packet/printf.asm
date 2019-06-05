section .text
global printf_
printf_:
  mov rax, 1
  mov rdi, 1
  syscall
  ret
