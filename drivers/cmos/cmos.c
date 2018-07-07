#include "cmos.h"

uint8_t read_cmos(uint8_t index) {
  outb(0x70, index);
  return inb(0x71);
}

void write_cmos(uint8_t index, uint8_t what) {
  outb(0x70, index);
  outb(0x71, what);
}
