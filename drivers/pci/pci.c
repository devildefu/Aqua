#include "pci.h"

#define PCI_CONFIG_ADDRESS 0xCF8
#define PCI_CONFIG_DATA 0xCFC

PCI_DEVICE devices[65536];
size_t devicesInArray = 0;
bool inited = 0;

/* Get size of devices array */
size_t array_size(void) {
    return devicesInArray;
}

/* Check device and write device to device array */
void check_function(uint8_t bus, uint8_t device, uint8_t function) {
    if(inited == 1) {
        return;
    }

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

    devices[array_size()].BaseClass = class_code;
    devices[array_size()].SubClass = sub_class;
    devices[array_size()].RevisionID = revision_id;
    devices[array_size()].ProgIf = prog_if;
    devices[array_size()].CacheLineSize = cache_line_size;
    devices[array_size()].LatencyTimer = latency_timer;
    devices[array_size()].HeaderType = header_type;
    devices[array_size()].BIST = bist;

    devices[array_size()].DeviceID = device_id;
    devices[array_size()].VendorID = vendor_id;
    devices[array_size()].Command = command;
    devices[array_size()].Status = status;
    devices[array_size()].BusNumber = bus;
    devices[array_size()].DeviceNumber = device;
    devices[array_size()].FunctionNumber = function;

    //printf("%i:%i.%i Type: 0x%i, More precisely: 0x%i, Prog IF: 0x%i | Header: 0x%i ar: %i\n", bus, device, function, class_code, sub_class, prog_if, header_type, array_size());

    devicesInArray++;
}

//lspci
void lspci(void) {
    for(uint16_t device = 0; device < array_size(); ++device) {
        printf("%i:%i.%i VendorID: %i, Type: 0x%i, Class: 0x%i, Prog IF: 0x%i, Header: 0x%i\n", devices[device].BusNumber, devices[device].DeviceNumber, devices[device].FunctionNumber, devices[device].VendorID, devices[device].BaseClass, devices[device].SubClass, devices[device].ProgIf, devices[device].HeaderType);
    }
    //printf("%i:%i.%i Type: 0x%i, More precisely: 0x%i\n", bus, device, function, class_code, sub_class);
}

/* Pci functions */
    void init_pci(void) {
        detect_devices();
        inited = 1;
    }

/* Device functions */
    size_t number_of_devices(void) {
        return array_size();
    } 

    PCI_DEVICE get_device(size_t index) {
        return devices[index];
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

/* Read from pci device config */ 
    uint32_t read_config_dword(uint8_t bus, uint8_t device, uint8_t function, uint8_t offset){
        uint32_t address =
            (uint32_t)(1 << 31)          //enabled
            | ((uint32_t)bus << 16)      //bus number
            | ((uint32_t)device << 11)   //device number
            | ((uint32_t)function << 8)  //function number
            | ((uint32_t)offset & 0xfc); //Register number

        outl(PCI_CONFIG_ADDRESS, address);

        return inl(PCI_CONFIG_DATA);
    }

    uint16_t read_config_word(uint8_t bus, uint8_t device, uint8_t function, uint8_t offset){
        uint32_t value = read_config_dword(bus, device, function, offset);
        return (value >> ((offset & 3) * 8)) & 0xffff;
    }

    uint8_t read_config_byte(uint8_t bus, uint8_t device, uint8_t function, uint8_t offset){
        uint32_t value = read_config_dword(bus, device, function, offset);
        return (value >> ((offset & 3) * 8)) & 0xff;
    }

/* Write to pci device config */
    void write_config_byte(uint8_t bus, uint8_t device, uint8_t function, uint8_t offset, uint8_t value){
        uint32_t tmp = read_config_dword(bus, device, function, offset);

        tmp &= ~(0xff << ((offset & 3) * 8));
        tmp |= (value << ((offset & 3) * 8));

        write_config_dword(bus, device, function, offset, tmp);
    }

    void write_config_word(uint8_t bus, uint8_t device, uint8_t function, uint8_t offset, uint16_t value){
        uint32_t tmp = read_config_dword(bus, device, function, offset);

        tmp &= ~(0xffff << ((offset & 3) * 8));
        tmp |= (value << ((offset & 3) * 8));

        write_config_dword(bus, device, function, offset, tmp);
    }

    void write_config_dword (uint8_t bus, uint8_t device, uint8_t function, uint8_t offset, uint32_t value){
        uint32_t address =
            (uint32_t)(1 << 31)          //enabled
            | ((uint32_t)bus << 16)      //bus number
            | ((uint32_t)device << 11)   //device number
            | ((uint32_t)function << 8)  //function number
            | ((uint32_t)offset & 0xfc); //Register number

        outl(PCI_CONFIG_ADDRESS, address);

        outl(PCI_CONFIG_DATA, value);
    }

/* All get* functions */ 

    /* For standard pci device config */
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
