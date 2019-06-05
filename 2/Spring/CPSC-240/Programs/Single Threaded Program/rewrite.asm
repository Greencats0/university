global main
extern printf
extern pthread_create
extern pthread_join

%define NULL 0

section .text
main:
  push rbp
  mov rbp, rsp
  mov rdi, pthread_id
  mov rsi, NULL
  mov rdx, function_called
  mov rcx, NULL
  call pthread_create
  mov rdi, qword[pthread_id]
  mov rsi, NULL
  call pthread_join 
  ret

function_called:
  mov rsi, message 
  mov rdi, fmt
  mov rcx, message_len
  call printf
  ret

section .data
pthread_id: dd 0, 0, 0, 0, 0
message: db "Hello", 10
message_len: equ $-message
fmt: db "%s", 10 
