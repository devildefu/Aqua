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

extern isr0_handler
extern isr1_handler
extern isr2_handler
extern isr3_handler
extern isr4_handler
extern isr5_handler
extern isr6_handler
extern isr7_handler
extern isr8_handler
extern isr10_handler
extern isr11_handler
extern isr12_handler
extern isr13_handler
extern isr14_handler
extern isr16_handler
extern isr17_handler
extern isr18_handler
extern isr19_handler
extern isr20_handler
extern isr30_handler

isr0:
    pushad
    call isr0_handler
    jmp_next
    popad
    iret

isr1:
    pushad
    call isr1_handler
    jmp_next
    popad
    iret

isr2:
    pushad
    call isr2_handler
    jmp_next
    popad
    iret

isr3:
    pushad
    call isr3_handler
    jmp_next
    popad
    iret

isr4:
    pushad
    call isr4_handler
    jmp_next
    popad
    iret

isr5:
    pushad
    call isr5_handler
    jmp_next
    popad
    iret

isr6:
    pushad
    call isr6_handler
    jmp_next
    popad
    iret

isr7:
    pushad
    call isr7_handler
    jmp_next
    popad
    iret

isr8:
    pushad
    call isr8_handler
    jmp_next
    popad
    iret

isr10:
    pushad
    call isr10_handler
    jmp_next
    popad
    iret

isr11:
    pushad
    call isr11_handler
    jmp_next
    popad
    iret

isr12:
    pushad
    call isr12_handler
    jmp_next
    popad
    iret

isr13:
    pushad
    call isr13_handler
    jmp_next
    popad
    iret

isr14:
    pushad
    call isr14_handler
    jmp_next
    popad
    iret

isr16:
    pushad
    call isr16_handler
    jmp_next
    popad
    iret

isr17:
    pushad
    call isr17_handler
    jmp_next
    popad
    iret

isr18:
    pushad
    call isr18_handler
    jmp_next
    popad
    iret

isr19:
    pushad
    call isr19_handler
    jmp_next
    popad
    iret

isr20:
    pushad
    call isr20_handler
    jmp_next
    popad
    iret

isr30:
    pushad
    call isr30_handler
    jmp_next
    popad
    iret