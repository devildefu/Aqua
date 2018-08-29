#ifndef BGA_H
#define BGA_H

#include <core/include/definitions.h>
#include <core/include/ports.h>
#include <drivers/com/com.h>

#include "vbe.h"

void BGA_WriteRegister(uint16_t indexValue, uint16_t dataValue);

uint16_t BGA_ReadRegister(uint16_t indexValue);

/* QEMU return VBE_DISPI_ID0
TODO: QEMU support */
int BGA_IsAvailable(void);

/* 
useLinearFrameBuffer - VBE_DISPI_LFB_ENABLED or VBE_DISPI_INDEX_BANK (VBE_DISPI_INDEX_BANK is simpler to use)
clearVideoMemory - VBE_DISPI_NOCLEARMEM or 0 */
bool BGA_SetVideoMode(uint32_t width, uint32_t height, uint32_t bitDepth, int useLinearFrameBuffer, int clearVideoMemory);
void BGA_SetBank(uint16_t bankNumber);

#endif