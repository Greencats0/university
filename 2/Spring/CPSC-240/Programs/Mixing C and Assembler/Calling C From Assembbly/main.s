.intel_syntax noprefix
.extern printf
.global main
.section .text
main:
  push rbp
  mov rbp, rsp
  mov rdi, format
  movsd xmm0, 1.2345
  call printf
  ret

.section .data
format: .byte "%f", 10, 0
