; taken from here cause I was banging my head against a wall for hours -> https://gist.github.com/BertrandBordage/10921263
; checking if file exists -> https://gist.github.com/Archenoth/5380671
; so we know how to access the memory address of the string -> https://stackoverflow.com/questions/47534020/how-to-get-address-of-variable-and-dereference-it-in-nasm-x86-assembly
; GDB passing in command line arguments -> https://stackoverflow.com/questions/14494957/how-do-i-pass-a-command-line-argument-while-starting-up-gdb-in-linux
; List of all available registers in x86-64 -> https://docs.microsoft.com/en-us/windows-hardware/drivers/debugger/x64-architecture
; Converting from Big Endian to Little Endian -> https://stackoverflow.com/questions/19275955/convert-little-endian-to-big-endian
  ; https://en.wikibooks.org/wiki/X86_Assembly/Shift_and_Rotate
; Bitwise operations -> https://www.programiz.com/c-programming/bitwise-operators


%define SYS_EXIT 60
%define SYS_READ 0
%define SYS_WRITE 1
%define SYS_OPEN 2
%define SYS_CLOSE 3
%define STDOUT 1

%define BUFFER_SIZE 2048

section .text
global  _start
_start:
  ; So we can read in our argument from argv[]
  ; Link here -> https://stackoverflow.com/questions/36071711/linux-assembly-x86-64-create-a-file-using-command-line-parameters
  add rsp, byte 0x10
  pop rdi
  jmp _check
  ; I added this to see
_check:
; basic if/else control flow -> https://stackoverflow.com/questions/14292903/complex-if-statement-in-assembly
  mov rdx,0
  cmp rdx,rax
  jle _cont
  jnle _exit_failiure
  _cont:

  ; open the file
  mov rax, SYS_OPEN
  mov rsi, 0
  syscall
  mov [fd], rax
  jmp _read_write

_read_write:
  ; Read the file into the buffer
  mov rax, SYS_READ
  mov rdi, [fd]
  mov rsi, file_buffer
  mov rdx, BUFFER_SIZE
  syscall

  ; Si on a atteint la fin du fichier, on quitte
  cmp rax, 0
  je _exit_success

  ; Affiche le contenu du buffer
  mov rdx, rax
  mov rax, SYS_WRITE
  mov rdi, STDOUT
  mov rsi, file_buffer
  syscall

  jp _read_write


_exit_failiure:
  ; exit with code 1
  mov rax, 60
  mov rdi, 1
  syscall

_exit_success:
  ; Close the file stream
  mov rax, SYS_CLOSE
  mov rdi, fd
  syscall

  ; ; place the contents of the file into STDOUT and call it
  ;
  ; mov [file_buffer], dword 10
  ; mov rax, SYS_WRITE
  ; mov rdi, STDOUT
  ; mov rsi, file_buffer
  ; mov rdx, 1
  ; syscall

  ; Exit gracefully
  mov rax, 60
  mov rdi, 0
  syscall


section .data
fd dw 0

section .bss
file_buffer resb BUFFER_SIZE
