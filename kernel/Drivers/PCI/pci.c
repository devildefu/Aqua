#include "pci.h"

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