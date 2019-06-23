#ifndef __DEBUG_H_
#define __DEBUG_H_

#include <devices/serial.h>
#include <stdlib.h>

#define debug(msg) com_print(COM1_PORT, msg);com_print(COM1_PORT, "\r\n")
#define fail(msg) com_print(COM1_PORT, msg);abort()

#endif