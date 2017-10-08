#include "Modules/vga.h"
#include "Modules/keyboard.h"
#include "Modules/string.h"
//#include "Modules/time.h"

struct {
    uint64_t start;
}   start_clocks;

static inline uint64_t rdtsc() {
  	uint32_t low, high;
  	asm volatile ("rdtsc" : "=a"(low), "=d"(high));
  	return ((uint64_t)high << 32) | low;
}

static inline int64_t clock() {
    return rdtsc() - start_clocks.start;
}

static void wait(uint64_t ms) {
    int64_t now = clock();
    int64_t end = now+ms;
   while(clock() <= end) {}
}

static inline void initTimer() {
    start_clocks.start = rdtsc();
}
void kmain(void) {
	initTimer();
	wait(1000);
	putchar('a');
	return;
}
