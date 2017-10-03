#ifndef TIME_H
#define TIME_H

#include "definitions.h"
#define ClocksPerSecond 1000


static inline uint64_t clock() {
  	uint64_t time;
  	asm volatile ("rdtsc" : "=A"(time));
  	return time;
}

static void wait(uint64_t ms) {
  	int64_t now = clock();
  	while(clock() <= now+ms) {
		
	}
}

#endif



