#include <devices/serial.h>

void com_init(uint16_t port) {
    outb(port + 1, 0x00);
    outb(port + 3, 0x80);
    outb(port + 0, 0x03);
    outb(port + 1, 0x00);
    outb(port + 3, 0x03);
    outb(port + 2, 0xC7);
    outb(port + 4, 0x0B);
}

int com_received(uint16_t port) {
    return inb(port + 5) & 1;
}

char com_read(uint16_t port) {
    while(com_received(port) == 0);
    return inb(port);
}

int com_is_transmit_empty(uint16_t port) {
    return inb(port + 5) & 0x20;
}

void com_putchar(uint16_t port, char letter) {
    while(com_is_transmit_empty(port) == 0);
    outb(port, letter);
}

void com_print(uint16_t port, char* string) {
    uint16_t i;
    while(string[i]!='\0') {
        com_putchar(port, string[i]);
        i++;
    }
}