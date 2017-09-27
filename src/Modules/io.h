#ifndef __IO_H_
#define __IO_H_
#include "definitions.h"

///////////////////////////////////////////////////////////
//IN

static inline uint8_t inb(uint16_t port) {
	uint8_t ret;
	asm volatile ("inb %1, %0"
			: "=a"(ret)
			: "Nd"(port) );
	return ret;
}

////////////////////////////////////////////////////////////
//OUT

static inline void outb(uint16_t port, uint8_t val) {
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

////////////////////////////////////////////////////////////
//CPUID

static inline void cpuid(uint32_t reg, uint32_t eax, uint32_t ebx, uint32_t ecx, uint32_t edx) {
	asm volatile( "cpuid"
		    : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx)
		    : "0" (reg) );
}

void DetectCPU() {
	
}


#endif
