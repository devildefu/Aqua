#include <cpu/idt.h>

IDT_entry IDT[256];

void idt_set(uint8_t id, unsigned long base, uint16_t selector, uint8_t type_attr) {
    IDT[id].offset_lowerbits = base & 0xFFFF;
    IDT[id].selector = selector;
    IDT[id].zero = 0;
    IDT[id].type_attr = type_attr;
    IDT[id].offset_higherbits = (base & 0xFFFF0000) >> 16;
}

void idt_init(void) {
    extern int idt_load();
    extern int irq0();
    extern int irq1();
    extern int irq2();
    extern int irq3();
    extern int irq4();
    extern int irq5();
    extern int irq6();
    extern int irq7();
    extern int irq8();
    extern int irq9();
    extern int irq10();
    extern int irq11();
    extern int irq12();
    extern int irq13();
    extern int irq14();
    extern int irq15();

    unsigned long irq0_address;
    unsigned long irq1_address;
    unsigned long irq2_address;
    unsigned long irq3_address;
    unsigned long irq4_address;
    unsigned long irq5_address;
    unsigned long irq6_address;
    unsigned long irq7_address;
    unsigned long irq8_address;
    unsigned long irq9_address;
    unsigned long irq10_address;
    unsigned long irq11_address;
    unsigned long irq12_address;
    unsigned long irq13_address;
    unsigned long irq14_address;
    unsigned long irq15_address;
    unsigned long idt_address;
    unsigned long idt_ptr[2];

    /* Remapping PIC */
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 40);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    outb(0x21, 0x0);
    outb(0xA1, 0x0);

    /* Setting up IRQ */
    idt_set(32, (unsigned)irq0, 0x08, 0x8E);
    idt_set(33, (unsigned)irq1, 0x08, 0x8E);
    idt_set(34, (unsigned)irq2, 0x08, 0x8E);
    idt_set(35, (unsigned)irq3, 0x08, 0x8E);
    idt_set(36, (unsigned)irq4, 0x08, 0x8E);
    idt_set(37, (unsigned)irq5, 0x08, 0x8E);
    idt_set(38, (unsigned)irq6, 0x08, 0x8E);
    idt_set(39, (unsigned)irq7, 0x08, 0x8E);
    idt_set(40, (unsigned)irq8, 0x08, 0x8E);
    idt_set(41, (unsigned)irq9, 0x08, 0x8E);
    idt_set(42, (unsigned)irq10, 0x08, 0x8E);
    idt_set(43, (unsigned)irq11, 0x08, 0x8E);
    idt_set(44, (unsigned)irq12, 0x08, 0x8E);
    idt_set(45, (unsigned)irq13, 0x08, 0x8E);
    idt_set(46, (unsigned)irq14, 0x08, 0x8E);
    idt_set(47, (unsigned)irq15, 0x08, 0x8E);

    idt_address = (unsigned long)IDT;
    idt_ptr[0] = (sizeof(IDT_entry) * 256) + ((idt_address & 0xFFFF) << 16);
    idt_ptr[1] = idt_address >> 16;

    /* and finish! */
    idt_load(idt_ptr);
}

void irq0_handler(void) {
    outb(0x20, 0x20);
}

void irq1_handler(void) {
	outb(0x20, 0x20);
    
   /* uint8_t status = inb(KEYBOARD_STATUS);
    if(status & 0x01) {
        char keycode = inb(KEYBOARD_KEYCODE);
        if(keycode < 0)
            return; */
        
        /* TODO: implement character typing */
    /*}*/
}
 
void irq2_handler(void) {
    outb(0x20, 0x20);
}
 
void irq3_handler(void) {
    outb(0x20, 0x20);
}
 
void irq4_handler(void) {
    outb(0x20, 0x20);
}
 
void irq5_handler(void) {
    outb(0x20, 0x20);
}
 
void irq6_handler(void) {
    outb(0x20, 0x20);
}
 
void irq7_handler(void) {
    outb(0x20, 0x20);
}
 
void irq8_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20);          
}
 
void irq9_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}
 
void irq10_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}
 
void irq11_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}
 
void irq12_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}
 
void irq13_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}
 
void irq14_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}
 
void irq15_handler(void) {
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}
