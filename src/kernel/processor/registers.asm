global throw_regs
throw_regs:
    mov eax, [esp+4]

    mov   [eax+4], ebx
    mov   [eax+8], ecx
    mov   [eax+12], edx

    mov ebx, [esp]
    mov   [eax+16], ebx

    mov ebx, 0
    mov [eax], ebx

    mov ebx, esp
    add ebx, 4

    mov   [eax+20], ebx

    mov ebx, [eax+4]

    mov   [eax+24], ebp

    mov eax, 0
    ret

global set_regs
set_regs:
    mov ebx, [esp+4]
    
    mov eax,  [ebx]
    mov ecx,  [ebx+8]
    mov edx,  [ebx+12]
    mov esp,  [ebx+20]
    mov ebp,  [ebx+24]

    mov ebx, [ebx+16]
    jmp ebx

global geteip
geteip:
    mov eax, [esp]
    ret

global _jmp
_jmp:
    mov eax, [esp+4]
    pop ebx
    jmp eax