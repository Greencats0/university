section .text
global _start
_start:
  mov r8, 10
  while_block:
    cmp r8, 0
    je exit
    dec r8
    jmp while_block
  exit:
    xor rdi, rdi
    mov rax, 60
    syscall
