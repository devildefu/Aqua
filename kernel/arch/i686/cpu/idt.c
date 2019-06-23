#include <cpu/idt.h>

IDT_entry IDT[256];

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

    /* Setting up */
    irq0_address = (unsigned long)irq0;
    IDT[32].offset_lowerbits = irq0_address & 0xFFFF;
    IDT[32].selector = 0x08;
    IDT[32].zero = 0;
    IDT[32].type_attr = 0x8E;
    IDT[32].offset_higherbits = (irq0_address & 0xFFFF0000) >> 16;

    irq1_address = (unsigned long)irq1; 
	IDT[33].offset_lowerbits = irq1_address & 0xFFFF;
	IDT[33].selector = 0x08;
	IDT[33].zero = 0;
	IDT[33].type_attr = 0x8E;
	IDT[33].offset_higherbits = (irq1_address & 0xFFFF0000) >> 16;
 
	irq2_address = (unsigned long)irq2; 
	IDT[34].offset_lowerbits = irq2_address & 0xFFFF;
	IDT[34].selector = 0x08;
	IDT[34].zero = 0;
	IDT[34].type_attr = 0x8E;
	IDT[34].offset_higherbits = (irq2_address & 0xFFFF0000) >> 16;
 
	irq3_address = (unsigned long)irq3; 
	IDT[35].offset_lowerbits = irq3_address & 0xFFFF;
	IDT[35].selector = 0x08;
	IDT[35].zero = 0;
	IDT[35].type_attr = 0x8E;
	IDT[35].offset_higherbits = (irq3_address & 0xFFFF0000) >> 16;
 
	irq4_address = (unsigned long)irq4; 
	IDT[36].offset_lowerbits = irq4_address & 0xFFFF;
	IDT[36].selector = 0x08;
	IDT[36].zero = 0;
	IDT[36].type_attr = 0x8E;
	IDT[36].offset_higherbits = (irq4_address & 0xFFFF0000) >> 16;
 
	irq5_address = (unsigned long)irq5; 
	IDT[37].offset_lowerbits = irq5_address & 0xFFFF;
	IDT[37].selector = 0x08;
	IDT[37].zero = 0;
	IDT[37].type_attr = 0x8E;
	IDT[37].offset_higherbits = (irq5_address & 0xFFFF0000) >> 16;
 
	irq6_address = (unsigned long)irq6; 
	IDT[38].offset_lowerbits = irq6_address & 0xFFFF;
	IDT[38].selector = 0x08;
	IDT[38].zero = 0;
	IDT[38].type_attr = 0x8E;
	IDT[38].offset_higherbits = (irq6_address & 0xFFFF0000) >> 16;
 
	irq7_address = (unsigned long)irq7; 
	IDT[39].offset_lowerbits = irq7_address & 0xFFFF;
	IDT[39].selector = 0x08;
	IDT[39].zero = 0;
	IDT[39].type_attr = 0x8E;
	IDT[39].offset_higherbits = (irq7_address & 0xFFFF0000) >> 16;
 
	irq8_address = (unsigned long)irq8; 
	IDT[40].offset_lowerbits = irq8_address & 0xFFFF;
	IDT[40].selector = 0x08;
	IDT[40].zero = 0;
	IDT[40].type_attr = 0x8E;
	IDT[40].offset_higherbits = (irq8_address & 0xFFFF0000) >> 16;
 
	irq9_address = (unsigned long)irq9; 
	IDT[41].offset_lowerbits = irq9_address & 0xFFFF;
	IDT[41].selector = 0x08;
	IDT[41].zero = 0;
	IDT[41].type_attr = 0x8E;
	IDT[41].offset_higherbits = (irq9_address & 0xFFFF0000) >> 16;
 
	irq10_address = (unsigned long)irq10; 
	IDT[42].offset_lowerbits = irq10_address & 0xFFFF;
	IDT[42].selector = 0x08;
	IDT[42].zero = 0;
	IDT[42].type_attr = 0x8E;
	IDT[42].offset_higherbits = (irq10_address & 0xFFFF0000) >> 16;
 
	irq11_address = (unsigned long)irq11; 
	IDT[43].offset_lowerbits = irq11_address & 0xFFFF;
	IDT[43].selector = 0x08;
	IDT[43].zero = 0;
	IDT[43].type_attr = 0x8E;
	IDT[43].offset_higherbits = (irq11_address & 0xFFFF0000) >> 16;
 
	irq12_address = (unsigned long)irq12; 
	IDT[44].offset_lowerbits = irq12_address & 0xFFFF;
	IDT[44].selector = 0x08;
	IDT[44].zero = 0;
	IDT[44].type_attr = 0x8E;
	IDT[44].offset_higherbits = (irq12_address & 0xFFFF0000) >> 16;
 
	irq13_address = (unsigned long)irq13; 
	IDT[45].offset_lowerbits = irq13_address & 0xFFFF;
	IDT[45].selector = 0x08;
	IDT[45].zero = 0;
	IDT[45].type_attr = 0x8E;
	IDT[45].offset_higherbits = (irq13_address & 0xFFFF0000) >> 16;
 
	irq14_address = (unsigned long)irq14; 
	IDT[46].offset_lowerbits = irq14_address & 0xFFFF;
	IDT[46].selector = 0x08;
	IDT[46].zero = 0;
	IDT[46].type_attr = 0x8E;
	IDT[46].offset_higherbits = (irq14_address & 0xFFFF0000) >> 16;
 
    irq15_address = (unsigned long)irq15; 
	IDT[47].offset_lowerbits = irq15_address & 0xFFFF;
	IDT[47].selector = 0x08;
	IDT[47].zero = 0;
	IDT[47].type_attr = 0x8E;
	IDT[47].offset_higherbits = (irq15_address & 0xFFFF0000) >> 16;

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
    
    uint8_t status = inb(KEYBOARD_STATUS);
    if(status & 0x01) {
        char keycode = inb(KEYBOARD_KEYCODE);
        if(keycode < 0)
            return;
        
        /* TODO: implement character typing */
    }
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