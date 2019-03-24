#ifndef COM_H
#define COM_H

#define COM1_PORT 0x3F8
#define COM2_PORT 0x2F8
#define COM3_PORT 0x3E8
#define COM4_PORT 0x2E8

/* uint16_t */
#include <core/include/ports.h>

void com_init(uint16_t port);
char com_read(uint16_t port);
void com_write(uint16_t port, char letter);
void com_print(uint16_t port, char* string);

#endif