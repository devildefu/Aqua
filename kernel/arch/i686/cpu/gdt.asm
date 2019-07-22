global gdt_flush:function
extern gdt_ptr
gdt_flush:
    lgdt [gdt_ptr] ; Load the GDT
    jmp 0x0008:fix_cs
    fix_cs:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret

global tss_flush:function
tss_flush:
    mov ax, 0x2B
    ltr ax
    ret