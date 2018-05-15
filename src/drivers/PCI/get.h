#pragma once
#include <io/ports.h>

uint16_t pciConfigReadWord (uint8_t bus, uint8_t slot,
                             uint8_t func, uint8_t offset)
{
    uint32_t address;
    uint32_t lbus  = (uint32_t)bus;
    uint32_t lslot = (uint32_t)slot;
    uint32_t lfunc = (uint32_t)func;
    uint16_t tmp = 0;
 
    /* create configuration address as per Figure 1 */
    address = (uint32_t)((lbus << 16) | (lslot << 11) |
              (lfunc << 8) | (offset & 0xfc) | ((uint32_t)0x80000000));
 
    /* write out the address */
    outb(0xCF8, address);
    /* read in the data */
    /* (offset & 2) * 8) = 0 will choose the first word of the 32 bits register */
    tmp = (uint16_t)((inb(0xCFC) >> ((offset & 2) * 8)) & 0xffff);
    return (tmp);
}

uint16_t getVendorID(uint8_t bus, uint8_t slot)
{
    uint16_t vendor, device;
    /* try and read the first configuration register. Since there are no */
    /* vendors that == 0xFFFF, it must be a non-existent device. */
    if ((vendor = pciConfigReadWord(bus,slot,0,0)) != 0xFFFF) {
       device = pciConfigReadWord(bus,slot,0,2);
    } return (vendor);
}

uint16_t getClassCode(uint8_t bus, uint8_t slot)
{
    return (pciConfigReadWord(bus,slot,0,10));
}

uint16_t getSubClass(uint8_t bus, uint8_t slot)
{
    return (pciConfigReadWord(bus,slot,1,10));
}

uint16_t getHeaderType(uint8_t bus, uint8_t slot)
{
    return (pciConfigReadWord(bus,slot,0, 0x0C));
}

uint16_t getSecondaryBus(uint8_t bus, uint8_t slot)
{
    return (pciConfigReadWord(bus,slot,1, 18));
}