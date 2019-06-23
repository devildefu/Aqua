#ifndef IDT_H
#define IDT_H

#include <stdint.h>
#include <ports.h>

#include <video/tty.h>

struct _IDT_entry {
    unsigned short int offset_lowerbits;
    unsigned short int selector;
    unsigned char zero;
    unsigned char type_attr;
    unsigned short int offset_higherbits;
};

typedef struct _IDT_entry IDT_entry;

void idt_init(void);

#endif