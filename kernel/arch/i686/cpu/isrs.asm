global isr0:function

global isr0_handler
extern isr0_handler

isr0:
    pushad
    call isr0_handler
    popad
    iret