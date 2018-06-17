#ifndef K_PCI
#define K_PCI

#include <kernel/include/definitions.h>
#include <kernel/include/ports.h>

/* 
    Enum for pci device types, for more about it, go to https://wiki.osdev.org/PCI#Class_Codes
*/

enum DEVICE_TYPE {
    OLD = 0x0,
    MASS_STORAGE = 0x1,
    NETWORK = 0x2,
    DISPLAY = 0x3,
    MULTIMEDIA = 0x4,
    MEMORY = 0x5,
    BRIDGE = 0x6,
    SIMPLE_COM = 0x7,
    BASE_SYSTEM = 0x8,
    INPUT = 0x9,
    DOCKING_STATION = 0xA,
    PROCESSOR = 0xB,
    SERIAL = 0xC,
    WIRELESS = 0xD,
    SMART_IO = 0xE,
    SATELLITE = 0xF,
    ENCRYPTION = 0x10,
    DATA_ACQUISITION = 0x11,
    RESERVED = 0x12,
    UNKNOWN = 0x13
};

/*
    Struct for typical pci device, for more information go to https://wiki.osdev.org/PCI#PCI_Device_Structure and 
    https://docs.microsoft.com/en-us/previous-versions/windows/embedded/ms903537(v=msdn.10)
*/


struct PCI_DEVICE {
    /* 8 bit variables */
        uint8_t RevisionID; 
        uint8_t ProgIf; 
        uint8_t SubClass; 
        uint8_t BaseClass; 
        uint8_t CacheLineSize; 
        uint8_t LatencyTimer; 
        uint8_t HeaderType; 
        uint8_t BIST; 
    /* 16 bit variables */
        uint16_t VendorID; 
        uint16_t DeviceID; 
        uint16_t Command; 
        uint16_t Status; 

    /* Union for specific pci device */
    union {

        /* Struct for 00h type device */
        struct PCI_DEVICE_TYPE_00H {
            /* 8 bit variables */
                uint8_t InterruptLine; 
                uint8_t InterruptPin; 
                uint8_t MinimumGrant; 
                uint8_t MaximumLatency; 
            /* 16 bit variables */
                uint16_t SubVendorID;
                uint16_t SubSystemID;
            /* 32 bit variables */
                uint32_t BaseAddresses[PCI_TYPE0_ADDRESSES];
                uint32_t CIS;
                uint32_t ROMBaseAddress;
                uint32_t Reserved2[2];
        } type0;

        /* Struct for 01h type device */
        struct PCI_DEVICE_TYPE_01H {
            /* 8 bit variables */
                uint8_t PrimaryBusNumber;
                uint8_t SecondaryBusNumber;
                uint8_t SubordinateBusNumber;
                uint8_t SecondaryLatencyTimer;
                uint8_t IOBase;
                uint8_t IOLimit;
                uint8_t InterruptLine;
                uint8_t InterruptPin;
            /* 16 bit variables */
                uint16_t SecondaryStatus;
                uint16_t MemoryBase;
                uint16_t MemoryLimit;
                uint16_t PrefetchableMemoryBase;
                uint16_t PrefetchableMemoryLimit;
                uint16_t IOBaseUpper;
                uint16_t IOLimitUpper;
                uint16_t BridgeControl;
            /* 32 bit variables */
                uint32_t BaseAddresses[PCI_TYPE1_ADDRESSES];
                uint32_t PrefetchableMemoryBaseUpper32;
                uint32_t PrefetchableMemoryLimitUpper32;
                uint32_t Reserved2;
                uint32_t ExpansionROMBase;
        } type1;

        /* Struct for 02h type device */
        struct PCI_DEVICE_TYPE_02H {
            /* 8 bit variables */
                uint8_t CapabilitiesPtr;
                uint8_t Reserved2;
                uint8_t PrimaryBusNumber;
                uint8_t CardbusBusNumber;
                uint8_t SubordinateBusNumber;
                uint8_t CardbusLatencyTimer;
                uint8_t InterruptLine;
                uint8_t InterruptPin;
                uint8_t Reserved3[56];
                uint8_t MultiMediaControl;
                uint8_t GeneralStatus;
                uint8_t Reserved4[2];
                uint8_t GPIO0Control;
                uint8_t GPIO1Control;
                uint8_t GPIO2Control;
                uint8_t GPIO3Control;
                uint8_t RetryStatus;
                uint8_t CardControl;
                uint8_t DeviceControl;
                uint8_t Diagnostic;
            /* 16 bit variables */
                uint16_t SecondaryStatus;
                uint16_t IOBase0_LO;
                uint16_t IOBase0_HI;
                uint16_t IOLimit0_LO;
                uint16_t IOLimit0_HI;
                uint16_t IOBase1_LO;
                uint16_t IOBase1_HI;
                uint16_t IOLimit1_LO;
                uint16_t IOLimit1_HI;
                uint16_t BridgeControl;
                uint16_t SubVendorID;
                uint16_t SubSystemID;
            /* 32 bit variables */
                uint32_t BaseAddress;
                uint32_t MemoryBase0;
                uint32_t MemoryLimit0;
                uint32_t MemoryBase1;
                uint32_t MemoryLimit1;
                uint32_t IRQMuxRouting;
                uint32_t SystemControl;
                uint32_t LegacyBaseAddress;
        } type2;
    } u;
};

#endif
