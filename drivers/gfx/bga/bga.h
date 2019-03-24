#ifndef BGA_H
#define BGA_H

#include <core/include/definitions.h>
#include <core/include/ports.h>
#include <drivers/com/com.h>

#include "vbe.h"

void bga_write_register(uint16_t indexValue, uint16_t dataValue);

uint16_t bga_read_register(uint16_t indexValue);

int bga_is_available(void);

/* 
useLinearFrameBuffer - VBE_DISPI_LFB_ENABLED or VBE_DISPI_INDEX_BANK (VBE_DISPI_INDEX_BANK is simpler to use)
clearVideoMemory - VBE_DISPI_NOCLEARMEM or 0 */
bool bga_set_video_mode(uint32_t width, uint32_t height, uint32_t bitDepth, int useLinearFrameBuffer, int clearVideoMemory);
void bga_set_bank(uint16_t bankNumber);

#endif