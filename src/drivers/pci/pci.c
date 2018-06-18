#include "pci.h"
#include <kernel/include/ports.h>
#include <kernel/include/string.h>

#define PCI_CONFIG_ADDRESS 0xCF8
#define PCI_CONFIG_DATA 0xCFC

PCI_DEVICE devices[65536];

size_t arraySize(void) {
    return sizeof(devices) / sizeof(PCI_DEVICE);
}

void check_function(uint8_t bus, uint8_t device, uint8_t function) {
    uint16_t vendor_id = get_vendor_id(bus, device, function);

    if(vendor_id == 0xFFFF) {
        return;
    }

    uint8_t class_code = get_class_code(bus, device, function);
    uint8_t sub_class  = get_subclass(bus, device, function);
    uint8_t revision_id = get_revision_id(bus, device, function);
    uint8_t prog_if  = get_prog_if(bus, device, function);
    uint8_t cache_line_size = get_cache_line_size(bus, device, function);
    uint8_t latency_timer  = get_latency_timer(bus, device, function);
    uint8_t header_type = get_header_type(bus, device, function);
    uint8_t bist  = get_bist(bus, device, function);

    uint16_t device_id  = get_device_id(bus, device, function);
    uint16_t command  = get_device_id(bus, device, function);
    uint16_t status  = get_device_id(bus, device, function);

    devices[arraySize()].BaseClass = class_code;
    devices[arraySize()].SubClass = sub_class;
    devices[arraySize()].RevisionID = revision_id;
    devices[arraySize()].ProgIf = prog_if;
    devices[arraySize()].CacheLineSize = cache_line_size;
    devices[arraySize()].LatencyTimer = latency_timer;
    devices[arraySize()].HeaderType = header_type;
    devices[arraySize()].BIST = bist;

    devices[arraySize()].DeviceID = device_id;
    devices[arraySize()].VendorID = vendor_id;
    devices[arraySize()].Command = command;
    devices[arraySize()].Status = status;
    devices[arraySize()].BusNumber = bus;
    devices[arraySize()].DeviceNumber = device;
    devices[arraySize()].FunctionNumber = function;

    char classCode[256];
    char SClass[256];
    char BusNum[256];
    char DevNum[256];
    char FunNum[256];

    printf("%i:%i.%i Type: 0x%i, More precisely: 0x%i\n", bus, device, function, class_code, sub_class);
}

void check_device(uint8_t bus, uint8_t device) {
    check_function(bus, device, 0);

    uint8_t header_type = get_header_type(bus, device, 0);
    if((header_type & 0x80) != 0){
        for(uint8_t function = 1; function < 8; ++function){
            check_function(bus, device, function);
        }
    }
}

void detect_devices(){
    for(uint16_t bus = 0; bus < 256; ++bus) {
        for(uint8_t device = 0; device < 32; ++device) {
            check_device(bus, device);
        }
    }
}

uint32_t read_config_dword(uint8_t bus, uint8_t device, uint8_t function, uint8_t offset){
    uint32_t address =
        (uint32_t)(1 << 31)  //enabled
        | ((uint32_t)bus << 16)  //bus number
        | ((uint32_t)device << 11)  //device number
        | ((uint32_t)function << 8) //function number
        | ((uint32_t)offset & 0xfc); //Register number

    outl(PCI_CONFIG_ADDRESS, address);

    return inl(PCI_CONFIG_DATA);
}

uint16_t get_vendor_id(uint8_t bus, uint8_t device, uint8_t function){
    uint32_t large = read_config_dword(bus, device, function, 0);
    return large;
}

uint16_t get_device_id(uint8_t bus, uint8_t device, uint8_t function){
    uint32_t large = read_config_dword(bus, device, function, 0);
    return large >> 16;
}

uint16_t get_command(uint8_t bus, uint8_t device, uint8_t function){
    uint32_t large = read_config_dword(bus, device, function, 4);
    return large;
}

uint16_t get_status(uint8_t bus, uint8_t device, uint8_t function){
    uint32_t large = read_config_dword(bus, device, function, 4);
    return large >> 16;
}

uint8_t get_class_code(uint8_t bus, uint8_t device, uint8_t function){
    uint32_t large = read_config_dword(bus, device, function, 8);
    return large >> 24 & 0xFF;
}

uint8_t get_subclass(uint8_t bus, uint8_t device, uint8_t function){
    uint32_t large = read_config_dword(bus, device, function, 8);
    return large >> 16 & 0xFF;
}

uint8_t get_prog_if(uint8_t bus, uint8_t device, uint8_t function){
    uint32_t large = read_config_dword(bus, device, function, 8);
    return large >> 8 & 0xFF;
}

uint8_t get_revision_id(uint8_t bus, uint8_t device, uint8_t function){
    uint32_t large = read_config_dword(bus, device, function, 8);
    return large >> 0xFF;
}

uint8_t get_bist(uint8_t bus, uint8_t device, uint8_t function){
    uint32_t large = read_config_dword(bus, device, function, 12);
    return large >> 24 & 0xFF;
}

uint8_t get_header_type(uint8_t bus, uint8_t device, uint8_t function){
    uint32_t large = read_config_dword(bus, device, function, 12);
    return large >> 16 & 0xFF;
}

uint8_t get_latency_timer(uint8_t bus, uint8_t device, uint8_t function){
    uint32_t large = read_config_dword(bus, device, function, 12);
    return large >> 8 & 0xFF;
}

uint8_t get_cache_line_size(uint8_t bus, uint8_t device, uint8_t function){
    uint32_t large = read_config_dword(bus, device, function, 12);
    return large >> 0xFF;
}