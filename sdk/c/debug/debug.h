#ifndef __DEBUG_H_
#define __DEBUG_H_

#include <devices/serial.h>

#define debug(msg) com_print(COM1_PORT, msg);com_print(COM1_PORT, "\r\n")

#endif