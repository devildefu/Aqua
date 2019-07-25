#ifndef GDT_H
#define GDT_H

#include <cpu/tss.h>
#include <definitions.h>
#include <memory.h>
#include <stdint.h>

struct _GdtEntry {
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t base_middle;
	uint8_t access;
	uint8_t granularity;
	uint8_t base_high;
} _packed_;

struct _GdtPtr {
	uint16_t limit;
	uint32_t base;
} _packed_;

typedef struct _GdtEntry GdtEntry;
typedef struct _GdtPtr GdtPtr;

extern void gdt_flush();

/**
 * Sets GdtEntry
 */
void gdt_set_gate(int id, unsigned long base, unsigned long limit, uint8_t access, uint8_t gran);

/**
 * Setups gdt for protected mode
 */
void gdt_init();

/**
 * Inits TSS
 */
void gdt_init_tss(int32_t id, uint16_t ss0, uint32_t esp0);

void gdt_set_kernel_stack_tts(uint32_t stack);

#endif