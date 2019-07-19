#ifndef __DEBUG_H_
#define __DEBUG_H_

#include <stdlib.h>
#include <string.h>

#ifdef __i386__
    #include <devices/serial.h>

    /* TODO: make it nicer */
    //#define debug(msg) com_print(COM1_PORT, "(");com_print(COM1_PORT, __FILE__);com_print(COM1_PORT, ":");char line[100];itoa(__LINE__, line);com_print(COM1_PORT, line);com_print(COM1_PORT, ") ");com_print(COM1_PORT, msg);com_print(COM1_PORT, "\r\n")
    #define debug(msg) com_printf(COM1_PORT, "(%s:%i) %s\r\n", __FILE__, __LINE__, msg)
    #define debugf(msg, ...) com_printf(COM1_PORT, msg, ##__VA_ARGS__);com_print(COM1_PORT, "\r\n")
    #define fail(msg) debug(msg);abort()
    #define UNIMPLEMENTED com_printf(COM1_PORT, "%s is UNIMPLEMENTED\r\n", __FUNCTION__)
    #define UNIMPLEMENTED_PART(msg) com_printf(COM1_PORT, "%s is UNIMPLEMENTED\r\n", msg)
#else
    #define debug(msg) 
    #define debugf(msg, ...)
    #define fail(msg) abort()
    #define UNIMPLEMENTED
    #define UNIMPLEMENTED_PART(msg)
#endif

#endif