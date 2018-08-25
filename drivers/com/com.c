#include "com.h"

void COM_init(uint16_t port) {
    outb(port + 1, 0x00);
    outb(port + 3, 0x80);
    outb(port + 0, 0x03);
    outb(port + 1, 0x00);
    outb(port + 3, 0x03);
    outb(port + 2, 0xC7);
    outb(port + 4, 0x0B);
}

int COM_received(uint16_t port) {
    return inb(port + 5) & 1;
}

char COM_read(uint16_t port) {
    while(COM_received(port) == 0);
    return inb(port);
}

int COM_is_transmit_empty(uint16_t port) {
    return inb(port + 5) & 0x20;
}

void COM_write(uint16_t port, char letter) {
    while(COM_is_transmit_empty(port) == 0);
    outb(port, letter);
}