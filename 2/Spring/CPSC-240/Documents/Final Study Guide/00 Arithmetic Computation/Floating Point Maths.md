# Floating Point Maths

# Addition

*Assume variable and number are declared double variables*
```asm
movsd xmm0, [variable]
addsd xmm0, [number]
movsd [answer], xmm0
```
Values are to be stored in the xmm[0-15] register after computation.

# Subtraction

```asm
movsd xmm0, [variable]
subsd xmm0, [number]
movsd [answer], xmm0
```

# Multiplication

```asm
; Input in rax register
mov rdx, rax
cvtsi2sd xmm0, rdx
mulsd xmm0, [floating_point]
cvtsd2si rax, xmm0
```
You need to convert the non decimal number into decimal representation. After computation, the number needs to be converted from a decimal representation into a regular integer. This process will loose precision. 

# Division

```asm
movsd xmm0, [answer]
divsd xmm0, [dividing_factor]
movsd [division_output], xmm0
```


