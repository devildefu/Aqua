#include "bga.h"

void bga_write_register(uint16_t indexValue, uint16_t dataValue) {
    outw(VBE_DISPI_IOPORT_INDEX, indexValue);
    outw(VBE_DISPI_IOPORT_DATA, dataValue);
}

uint16_t bga_read_register(uint16_t indexValue) {
    outw(VBE_DISPI_IOPORT_INDEX, indexValue);
    return inw(VBE_DISPI_IOPORT_DATA);
}

int bga_is_available(void) {
    return (bga_read_register(VBE_DISPI_INDEX_ID) == VBE_DISPI_ID5);
}

bool bga_set_video_mode(uint32_t width, uint32_t height, uint32_t bitDepth, int useLinearFrameBuffer, int clearVideoMemory) {
    if(width > VBE_DISPI_MAX_XRES || height > VBE_DISPI_MAX_YRES) {
        com_print(COM1_PORT, "[BGA Driver] Resolution is too large");
        return false;
    }

    bga_write_register(VBE_DISPI_INDEX_ENABLE, VBE_DISPI_DISABLED);
    bga_write_register(VBE_DISPI_INDEX_XRES, width);
    bga_write_register(VBE_DISPI_INDEX_YRES, height);
    bga_write_register(VBE_DISPI_INDEX_BPP, bitDepth);
    bga_write_register(VBE_DISPI_INDEX_ENABLE, VBE_DISPI_ENABLED |
        (useLinearFrameBuffer ? VBE_DISPI_LFB_ENABLED : 0) |
        (clearVideoMemory ? 0 : VBE_DISPI_NOCLEARMEM));
    return true;
}

void bga_set_bank(uint16_t bankNumber) {
    bga_write_register(VBE_DISPI_INDEX_BANK, bankNumber);
}