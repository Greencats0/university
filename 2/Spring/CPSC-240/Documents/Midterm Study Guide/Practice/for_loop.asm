section .text
global _start
; C Code
; for(int i = 0; i < 10; ++i){
;   if(i%2 == 1){ summation+=i; }
; }
_start:
  xor r8, r8 ; indexing
  for_loop:
  cmp r8, 10
  je exit
  mov r9, r8
  and r9, 1
  jnz add_block
  inc r8
  jz for_loop
  add_block:
  add qword[summation], r8
  inc r8
  jmp for_loop
  exit:
  mov rdi, qword[summation]
  mov rax, 60
  syscall
section .data
summation: db 0, 10
