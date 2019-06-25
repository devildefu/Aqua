global isr0:function

global isr0_handler
extern isr0_handler

isr0:
    pushad
    call isr0_handler
    ; Jump to next instruction
    mov eax, [esp+32]
    add eax, 2
    mov [esp+32], eax
    popad
    iret