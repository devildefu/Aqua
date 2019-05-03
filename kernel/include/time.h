#ifndef TIME_H
#define TIME_H

#include <stdint.h>
#define CLOCKS_PER_MILISECOND 3504055.289
#define CLOCKS_PER_DECISECOND CLOCKS_PER_MILISECOND * 10
#define CLOCKS_PER_CENTISECOND CLOCKS_PER_MILISECOND * 100
#define CLOCKS_PER_SECOND CLOCKS_PER_MILISECOND * 1000
#define CLOCKS_PER_MINUTE CLOCKS_PER_SECOND * 60
#define CLOCKS_PER_HOUR CLOCKS_PER_MINUTE * 60
#define CLOCKS_PER_DAY CLOCKS_PER_HOUR * 24
#define CLOCKS_PER_WEEK CLOCKS_PER_DAY * 7
#define CLOCKS_PER_MONTH CLOCKS_PER_DAY * 31
#define CLOCKS_PER_YEAR_QUATER CLOCKS_PER_MONTH * 4
#define CLOCKS_PER_YEAR CLOCKS_PER_DAY * 365
#define GHZ CLOCKS_PER_SECOND/100000000

struct {
    uint64_t start;
}   start_clocks;

static inline uint64_t rdtsc() {
    uint64_t ret;
    asm ("rdtsc" : "=A"(ret));
    return ret;
}

static inline int64_t clock() {
    return rdtsc() - start_clocks.start;
}

static void wait(uint64_t ms) {
    int64_t now = clock();
    int64_t end = now+(float)ms*CLOCKS_PER_MILISECOND;
   while(clock() < end) {}
}

static inline void initTimer() {
    start_clocks.start = rdtsc();
}

static inline void waitClocks(uint64_t clocks) {
    uint64_t now = rdtsc();
    while(rdtsc()-now <= clocks) {}
}

#endif
