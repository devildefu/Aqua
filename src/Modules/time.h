#ifndef TIME_H
#define TIME_H

#include "definitions.h"
#define ClocksPerMilisecond 3504055.289
#define ClocksPerDecisecond ClocksPerMilisecond * 10
#define ClocksPerCentisecond ClocksPerMilisecond * 100
#define ClocksPerSecond ClocksPerMilisecond * 1000
#define ClocksPerMinute ClocksPerSecond * 60
#define ClocksPerHour ClocksPerMinute * 60
#define ClocksPerDay ClocksPerHour * 24
#define ClocksPerWeek ClocksPerDay * 7
#define ClocksPerMonth ClocksPerDay * 31
#define ClocksPerYearQuater ClocksPerMonth * 4
#define ClocksPerYear ClocksPerDay * 365
#define GHz ClocksPerSecond/100000000

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
    int64_t end = now+(float)ms*ClocksPerMilisecond;
   while(clock() <= end) {}
}

static inline void initTimer() {
    start_clocks.start = rdtsc();
}

#endif



