#include "definitions.h"
#define ClocksPerSecond 1000


static inline int64_t clock() {
  int64_t time;
  _asm("rdtsc" : "=a"(time));
  return time;
}



