#ifndef CPU_H
#define CPU_H

typedef struct{
  char name[48];
} CPU_INFO;

static inline void cpuid(uint32_t reg, uint32_t* eax, uint32_t* ebx, uint32_t* ecx, uint32_t* edx) {
	asm volatile( "cpuid"
		    : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx)
		    : "0" (reg) );
}

#endif
