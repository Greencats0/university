; This program shows how to print a double word
; Written by John Overton

; printDoubleWord(eax)
printDWord:
        push    r8
        mov     r8, 7   ; i
        mov     rbx, 0
printloop:
        cmp     r8, 0
        jz      printexit
	xor	edx, edx
        div     10        ; rem in edx
        add     edx, '0'
        mov     byte [small_buffer + r8], dl
        inc     rbx
        cmp     eax, 0
        jz      printexit
        dec     r8
        jmp     printloop
printexit:
        lea     rax, [small_buffer + r8]
        pop     r8
        ret
