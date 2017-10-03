#ifndef TIME_H
#define TIME_H

#include "definitions.h"
#define ClocksPerMilisecond 1
#define ClocksPerDecisecond ClocksPerMilisecond * 10
#define ClocksPerCentisecond ClocksPerMilisecond * 100
#define ClocksPerSecond ClocksPerMilisecond * 1000


static inline uint64_t clock() {
  	uint32_t low, high;
  	asm volatile ("rdtsc" : "=a"(low), "=d"(high));
  	return ((uint64_t)hi << 32) | lo;
}

static void wait(uint64_t ms) {
  	int64_t now = clock();
  	while(clock() <= now+ms) {}
}

#endif



