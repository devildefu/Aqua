#ifndef MMIO_H
#define MMIO_H

#include <stdint.h>

static inline void mmio_write(uint32_t reg, uint32_t data) {
	*(volatile uint32_t*)reg = data;
}

static inline uint32_t mmio_read(uint32_t reg) {
	return *(volatile uint32_t*)reg;
}

#endif