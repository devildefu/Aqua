#include <cpu/gdt.h>

GdtEntry gdt[6];
GdtPtr gdt_ptr;

TssEntry tss;

void gdt_set_gate(int id, unsigned long base, unsigned long limit, uint8_t access, uint8_t gran) {
	/* Base */
	gdt[id].base_low = (base & 0xFFFF);
	gdt[id].base_middle = (base >> 16) & 0xFF;
	gdt[id].base_high = (base >> 24) & 0xFF;

	/* Limit */
	gdt[id].limit_low = (limit & 0xFFFF);
	gdt[id].granularity = (limit >> 16) & 0x0F;

	/* Granularity */
	gdt[id].granularity |= (gran & 0xF0);

	/* and access */
	gdt[id].access = access;
}

void gdt_init() {
	gdt_ptr.limit = (sizeof(GdtEntry) * 6) - 1;
	gdt_ptr.base = (uint32_t)&gdt;

	/* Null descriptor */
	gdt_set_gate(0, 0, 0, 0, 0);

	/* Code segment descriptor */
	gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

	/* Data segment descrriptor */
	gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

	/* User code */
	gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);

	/* User data */
	gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);

	/* TSS segment descriptor */
	gdt_init_tss(5, 0x10, 0x0);

	/* and flush! */
	gdt_flush();
	tss_flush();
}

void gdt_init_tss(int32_t id, uint16_t ss0, uint32_t esp0) {
	uintptr_t base = (uintptr_t)&tss;
	uintptr_t limit = base + sizeof(tss);

	gdt_set_gate(id, base, limit, 0xE9, 0x00);

	memset(&tss, 0x0, sizeof(tss));

	tss.ss0 = ss0;
	tss.esp0 = esp0;
	tss.cs = 0x0b;
	tss.ss = 0x13;
	tss.ds = 0x13;
	tss.es = 0x13;
	tss.fs = 0x13;
	tss.gs = 0x13;
	tss.iomap_base = sizeof(tss);
}

void gdt_set_kernel_stack_tts(uint32_t stack) {
	tss.esp0 = stack;
}