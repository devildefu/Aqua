#ifndef __CMOS_H_
#define __CMOS_H_

#include <kernel/include/definitions.h>
#include <kernel/include/ports.h>

uint8_t read_cmos(uint8_t index);
void write_cmos(uint8_t index, uint8_t what);

#endif
