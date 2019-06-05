.globl hello_world
.type hello_world, @function
.section .data
message: .ascii "Hello, World!\n"
length: .quad . - message
.section .text
hello_world:
  mov $1, %rax
  mov $1, %rdi
  mov $message, %rsi
  mov length, %rdx
  syscall
  ret
