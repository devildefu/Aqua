#include "bga.h"

void BGA_WriteRegister(uint16_t indexValue, uint16_t dataValue) {
    outw(VBE_DISPI_IOPORT_INDEX, indexValue);
    outw(VBE_DISPI_IOPORT_DATA, dataValue);
}

uint16_t BGA_ReadRegister(uint16_t indexValue) {
    outw(VBE_DISPI_IOPORT_INDEX, indexValue);
    return inw(VBE_DISPI_IOPORT_DATA);
}

int BGA_IsAvailable(void) {
    return (BGA_ReadRegister(VBE_DISPI_INDEX_ID) == VBE_DISPI_ID5);
}

bool BGA_SetVideoMode(uint32_t width, uint32_t height, uint32_t bitDepth, int useLinearFrameBuffer, int clearVideoMemory) {
    if(width > VBE_DISPI_MAX_XRES || height > VBE_DISPI_MAX_YRES) {
        COM_print(COM1_PORT, "[BGA Driver] Resolution is too large");
        return false;
    }

    BGA_WriteRegister(VBE_DISPI_INDEX_ENABLE, VBE_DISPI_DISABLED);
    BGA_WriteRegister(VBE_DISPI_INDEX_XRES, width);
    BGA_WriteRegister(VBE_DISPI_INDEX_YRES, height);
    BGA_WriteRegister(VBE_DISPI_INDEX_BPP, bitDepth);
    BGA_WriteRegister(VBE_DISPI_INDEX_ENABLE, VBE_DISPI_ENABLED |
        (useLinearFrameBuffer ? VBE_DISPI_LFB_ENABLED : 0) |
        (clearVideoMemory ? 0 : VBE_DISPI_NOCLEARMEM));
    return true;
}

void BGA_SetBank(uint16_t bankNumber) {
    BGA_WriteRegister(VBE_DISPI_INDEX_BANK, bankNumber);
}