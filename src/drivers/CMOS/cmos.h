#ifndef __CMOS_H_
#define __CMOS_H_

#include <utils/definitions.h>
#include <io/ports.h>

uint8_t read_cmos(uint8_t index);
void write_cmos(uint8_t index, uint8_t what);

#endif
