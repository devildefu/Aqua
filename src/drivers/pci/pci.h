#ifndef K_PCI
#define K_PCI

#include <kernel/include/definitions.h>
#include <kernel/include/ports.h>

void checkFunction(uint8_t bus, uint8_t device, uint8_t function);
void checkDevice(uint8_t bus, uint8_t device);
void checkBus(uint8_t bus);
void checkAllBuses(void);

uint16_t pciConfigReadWord (uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset);
uint16_t getVendorID(uint8_t bus, uint8_t slot);
uint16_t getClassCode(uint8_t bus, uint8_t slot);
uint16_t getSubClass(uint8_t bus, uint8_t slot);
uint16_t getHeaderType(uint8_t bus, uint8_t slot);
uint16_t getSecondaryBus(uint8_t bus, uint8_t slot);

#endif
