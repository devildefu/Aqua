#include "pci.h"

#include <kernel/io/ports.h>

void checkFunction(uint8_t bus, uint8_t device, uint8_t function) {
    uint8_t baseClass;
    uint8_t subClass;
    uint8_t secondaryBus;
 
    baseClass = getClassCode(bus, device);
    subClass = getSubClass(bus, device);
    if( (baseClass == 0x06) && (subClass == 0x04) ) {
        secondaryBus = getSecondaryBus(bus, device);
        checkBus(secondaryBus);
    }
}

void checkDevice(uint8_t bus, uint8_t device) {
    uint8_t function = 0;
    uint16_t vendorID;
    uint8_t headerType;

    vendorID = getVendorID(bus, device);
    if(vendorID == 0xFFFF) return;        // Device doesn't exist
    checkFunction(bus, device, function);
    headerType = getHeaderType(bus, device);
    if( (headerType & 0x80) != 0) {
        /* It is a multi-function device, so check remaining functions */
        for(function = 1; function < 8; function++) {
            if(getVendorID(bus, device) != 0xFFFF) {
                checkFunction(bus, device, function);
            }
        }
    }
}

void checkBus(uint8_t bus) {
    uint8_t device;
 
    for(device = 0; device < 32; device++) {
        checkDevice(bus, device);
    }
}

void checkAllBuses(void) {
    uint8_t function;
    uint8_t bus;
    uint16_t headerType;
 
    headerType = getHeaderType(0, 0);
    if( (headerType & 0x80) == 0) {
        /* Single PCI host controller */
        checkBus(0);
    } else {
        /* Multiple PCI host controllers */
        for(function = 0; function < 8; function++) {
            if(getVendorID(0, 0) != 0xFFFF) break;
            bus = function;
            checkBus(bus);
        }
    }
}

uint16_t pciConfigReadWord (uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset)
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