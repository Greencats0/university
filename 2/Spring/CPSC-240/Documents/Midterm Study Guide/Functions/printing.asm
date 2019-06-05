; This program will call the function write using syscalls
; Original article: http://cs.lmu.edu/~ray/notes/nasmtutorial/
; Written by Jared Dyreson

%define SYS_WRITE 1
%define STDOUT 1

; What the C function looks like
; ssize_t write(int fd, const void *buf, size_t count);

; Psuedo-code representation of NASM assembler
; print(rdi=file_descriptor, rsi=message, rdx=strlen(message))

; Our use case
; print(STDOUT, message, strlen(message))

; usage of jared::print

; load rdx with strlen
; load rsi with message
;

print:
  push rax
  push rdi
  mov rax, SYS_WRITE ; invoke write syscall
  mov rdi, STDOUT ; point to STDOUT
  syscall ; invoke
  pop rdi
  pop rax
  ret
; _start:
; mov rsi, message
; mov rdx, message_len
; call print
; mov rax, 60
; syscall
;
; section .data
; message: db "Linux", 0xA
; message_len: equ $-message
