; This program will convert the endianess of a given number
; Written by John Overton

cvtEndian:
  push    rbx
  push    rcx

  mov     ebx, eax
  shr     ebx, 24
  mov     ecx, ebx

  mov     ebx, eax
  shr     ebx, 8
  and     ebx, 0xff00
  or      ecx, ebx

  mov     ebx, eax
  shl     ebx, 0x8
  and     ebx, 0xff0000
  or      ecx, ebx

  mov     ebx, eax
  shl     ebx, 0x18
  or      ecx, ebx
  mov     eax, ecx

  pop     rcx
  pop     rbx
  ret
