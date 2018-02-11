A20_check:
	pushad
	mov edi, 0x112345
	mov esi, 0x012345
	mov [esi], esi
	mov [edi], edi
	cmpsd
	popad
    je A20_is
    jne A20_is2
	ret

A20_is:
    mov al, 0x21212121
	mov [0xB8000], al    
    ret

A20_is2:
    mov al, 0x12121212
    mov [0xB8000], al
    ret

A20_enable_KC:
        cli
 
        call    a20wait
        mov     al,0xAD
        out     0x64,al
 
        call    a20wait
        mov     al,0xD0
        out     0x64,al
 
        call    a20wait2
        in      al,0x60
        push    eax
 
        call    a20wait
        mov     al,0xD1
        out     0x64,al
 
        call    a20wait
        pop     eax
        or      al,2
        out     0x60,al
 
        call    a20wait
        mov     al,0xAE
        out     0x64,al
 
        call    a20wait
        sti
        ret
 
a20wait:
        in      al,0x64
        test    al,2
        jnz     a20wait
        ret
 
 
a20wait2:
        in      al,0x64
        test    al,1
        jz      a20wait2
        ret

A20_enable_fast:
in al, 0x92
test al, 2
jnz after
or al, 2
and al, 0xFE
out 0x92, al
after:
ret

A20_enable_bios:
;FASM
[bits 16]
mov     ax,2403h                ;--- A20-Gate Support ---
int     15h
jb      a20_ns                  ;INT 15h is not supported
cmp     ah,0
jnz     a20_ns                  ;INT 15h is not supported
 
mov     ax,2402h                ;--- A20-Gate Status ---
int     15h
jb      a20_failed              ;couldn't get status
cmp     ah,0
jnz     a20_failed              ;couldn't get status
 
cmp     al,1
jz      a20_activated           ;A20 is already activated
 
mov     ax,2401h                ;--- A20-Gate Activate ---
int     15h
jb      a20_failed              ;couldn't activate the gate
cmp     ah,0
jnz     a20_failed              ;couldn't activate the gate

a20_ns:
a20_failed: 
a20_activated:                  ;go on
ret

A20_enable_0xee:
in al, 0xee
ret