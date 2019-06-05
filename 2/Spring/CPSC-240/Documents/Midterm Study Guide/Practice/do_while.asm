section .text
global _start
_start:
  xor r8, r8 ; indexer
  do_while:
    inc r8 ; show that the statement is executed first before the conditional
    cmp r8, 10
    je exit
    jmp do_while
  exit:
    xor rdi, rdi
    mov rax, 60
    syscall
