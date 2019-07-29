%macro jmp_next 0
    mov eax, [esp+32]
    add eax, 2
    mov [esp+32], eax
%endmacro

global isr0:function
global isr1:function
global isr2:function
global isr3:function
global isr4:function
global isr5:function
global isr6:function
global isr7:function
global isr8:function
global isr10:function
global isr11:function
global isr12:function
global isr13:function
global isr14:function
global isr16:function
global isr17:function
global isr18:function
global isr19:function
global isr20:function
global isr30:function

extern isr_handler

; TODO: exception: 8, 10, 11, 12, 13, 14, 17 and 30 push error code! This value must be pulled from the stack!

isr0:
    pushad
    cld
    push 0
    push 0
    call isr_handler
    add esp, 8
    jmp_next
    popad
    iret

isr1:
    pushad
    cld
    push 0
    push 1
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr2:
    pushad
    cld
    push 0
    push 2
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr3:
    pushad
    cld
    push 0
    push 3
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr4:
    pushad
    cld
    push 0
    push 4
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr5:
    pushad
    cld
    push 0
    push 5
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr6:
    pushad
    cld
    push 0
    push 6
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr7:
    pushad
    cld
    push 0
    push 7
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr8:
    pushad
    cld
    push dword [esp]
    push 8
    call isr_handler
    add esp, 8 
    popad
    iret

isr10:
    pushad
    cld
    push dword [esp]
    push 10
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr11:
    pushad
    cld
    push dword [esp]
    push 11
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr12:
    pushad
    cld
    push dword [esp]
    push 12
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr13:
    pushad
    cld
    push dword [esp]
    push 13
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr14:
    pushad
    cld
    push dword [esp]
    push 14
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr16:
    pushad
    cld
    push 0
    push 16
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr17:
    pushad
    cld
    push dword [esp]
    push 17
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr18:
    pushad
    cld
    push 0
    push 18
    call isr_handler
    add esp, 8 
    popad
    iret

isr19:
    pushad
    cld
    push 0
    push 19
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr20:
    pushad
    cld
    push 0
    push 20
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret

isr30:
    pushad
    cld
    push dword [esp]
    push 30
    call isr_handler
    add esp, 8 
    jmp_next
    popad
    iret