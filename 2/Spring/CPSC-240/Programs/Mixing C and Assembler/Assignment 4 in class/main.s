.intel_syntax noprefix
.extern printf
.globl main
.section .text

main:
  push rbp
  push rbx
  mov rbp, rsp

  # add the the contents of the array
  # r8 will hold our counter for the for loop
  xor r8, r8

  lea rbx, [theArray]
  for_loop_block:

  cmp r8, sizeofarray
  je break_from_loop
  movsd xmm0,[rbx+r8*8]
  addsd xmm0, [answer]
  movsd [answer], xmm0
  inc r8
  jmp for_loop_block

  break_from_loop:
  movsd xmm0, [answer]
  divsd xmm0, [sizeofarray]
  movsd [average], xmm0
  mov rsi, format
  mov rsi, answer
  call printf
  xor rax, rax
  pop rbp
  ret


.section .data
summation_msg: .ascii "Sum: "
answer: DQ 0.0
average: DQ 0.0
format: .ascii "%f"
theArray: DQ   5.0, 17.6, 101.2, 8.1024, 1.0, 5.1, 4095.382, 0.825
sizeofarray: .int 8
