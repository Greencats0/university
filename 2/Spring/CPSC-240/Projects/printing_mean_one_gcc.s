.intel_syntax noprefix
.extern printf
.globl main
.section .text
main:
  push rbp
  mov rbp, rsp
  ; push r15
  ; xor r15, r15
  ; lea rbx, [array]
  ; summing:
  ; cmp r15, sizeofarray
  ; je exit
  ; ;movsd xmm4, [rbx+r15*8]
  ; ;addsd xmm4, [summation]
  ; ;movsd [summation], xmm4
  ; inc r15
  ; jmp summing
  ; exit:
  ; mov rdi, format
  ; movq xmm0, qword[summation]
  ; mov rax, 1
  ; call printf
  xor rax, rax
  pop rbp
  ret

.section .data
summation: .double 0.0
average: .double 0.0
format: .ascii "Summation: %f, Mean: %f"
array: .double   5.0, 17.6, 101.2, 8.1024, 1.0, 5.1, 4095.382, 0.825
sizeofarray: .int 8
