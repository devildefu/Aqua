#ifndef IDT_H
#define IDT_H

#include <cpu/isrs.h>
#include <definitions.h>
#include <ports.h>
#include <stdint.h>
#include <video/tty.h>

struct _IDT_entry {
	uint16_t offset_lowerbits;
	uint16_t selector;
	uint8_t zero;
	uint8_t type_attr;
	uint16_t offset_higherbits;
};

typedef struct _IDT_entry IDT_entry;

void idt_init(void);
void idt_set(uint8_t id, ulong_t base, uint16_t selector, uint8_t type_attr);

#endif