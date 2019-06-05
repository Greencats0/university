; taken from here cause I was banging my head against a wall for hours -> https://gist.github.com/BertrandBordage/10921263
; checking if file exists -> https://gist.github.com/Archenoth/5380671
%define SYS_EXIT 60
%define SYS_READ 0
%define SYS_WRITE 1
%define SYS_OPEN 2
%define SYS_CLOSE 3
%define STDOUT 1
%define SYS_CREATE 85

%define BUFFER_SIZE 4096

section .text
global  _start
_start:
  ; So we can read in our argument from argv[]
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
  ; mov rdx, rax
  ; mov rax, SYS_WRITE
  ; mov rdi, STDOUT
  ; mov rsi, file_buffer
  ; syscall

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



  ; _reset_key_pos:
  ;   xor bx, bx
  ;   jmp continue
  ;
  ; xor r8,r8
  ; xor r9, r9

  ; l:
  ;  ; https://www.aldeid.com/wiki/X86-assembly/Instructions/xor
  ;   cmp r9, 180
  ;   jge done
  ;   cmp r8, 7
  ;   jle _reset_key_pos
  ;   continue:
  ;   ; r8 -> index for the key (max value of 7)
  ;   ; r9 ->  index for the buffer (max value of 180)
  ;   mov r10, [file_buffer+r9]
  ;   xor r10, [key+r8]
  ;   ; converting ints to ascii
  ;   sub rsp, 16
  ;   mov rcx, 10
  ;   mov rbx, 16
  ;   .L1:
  ;   xor rdx, rdx
  ;   div rcx
  ;   or dl, 0x30
  ;   sub rbx, 1
  ;   mov [rsp+rbx], dl
  ;   test eax, eax
  ;   jnz .L1
  ;
  ;   mov rax, 4
  ;   lea rcx, [rsp+rbx]
  ;   mov edx, 16
  ;   sub rdx, rbx
  ;   int 0x80
  ;   add rsp, 16
  ;   ; mov rax, 1
  ;   ; mov rdi, 1
  ;   ; mov rsi, path
  ;   ; mov rdx, led
  ;   ; syscall
  ;   ; mov [file_buffer+r9], r10
  ;   ; mov sil, byte[file_buffer+r9] ; our character
  ;   ; mov byte[file_buffer+r9], sil
  ;   ; converting from big endian to little endian -> https://www.programiz.com/c-programming/bitwise-operators
  ;   ; shr sil, sil
  ;   ; shifting bits -> http://www.cs.virginia.edu/~evans/cs216/guides/x86.html
  ;   ; mov rax, SYS_WRITE
  ;   ; mov rdi, 1
  ;   ; mov rdx, 1
  ;   ; syscall
  ;   ; mov rax, 85
  ;   ; mov rdi, path
  ;   ; mov rsi, 00644Q
  ;   ; syscall
  ;   ; ;; File descriptor copy
  ; 	; mov	rbx,rax
  ;   ;
  ; 	; ;; sys_write(stream, message, length)
  ; 	; mov	rax, 1        	; sys_write
  ; 	; mov	rdi, path        ; ./nope
  ; 	; ; mov	rsi, message    ; message address
  ; 	; mov	rdx, 1    	; message string length
  ; 	; ; syscall
  ;   ; ; mov ebx, rax
  ;   ; syscall
  ;
  ;   inc r8
  ;   inc r9
  ;   jmp l
  ;   ;
  ;   ; mov r8b, byte[r9+r8]
  ;   ;
  ;
  ;   ; ; xor rax, rax
  ;   ; cmp r8, led ; if a >= b; then move to reset the key
  ;   ; ; jge _reset_key_pos
  ;   ; jge exit
  ;   ; inc r8
  ;   ; ; cmp r8, 180
  ;   ; ; jle done
  ;   ; ;
  ;   ; ; continue:
  ;   ; ; mov al, byte[r9+r8]
  ;   ; ; xor byte[r11+r10], al
  ;   ; ; mov byte[r9+r8], al
  ;   ; ;
  ;   ; ; ; counters
  ;   ; ; inc r8 ; increment the index of the packet
  ;   ; ; inc r10 ; increment the index of the key
  ;   ; ; jmp l
  ;
  ; ; Exit gracefully
  ; done:
    ; opening the file
    ; mov rax, 1
    ; mov rsi, file_buffer
    ; mov rdi, 1
    ; mov rdx, 1
    ; syscall


  exit:
  mov rax, 60
  mov rdi, 0
  syscall


section .data
fd dw 0
key db 0x32,0x36,0x13,0x92,0xa5,0x5a,0x27,0xf3
path: db "decrypted"
decrypted dw 0
led: equ $-path
index db 1


section .bss
file_buffer resb BUFFER_SIZE
length: equ $-file_buffer

; key: db '0123456789ABCDEF', 10
