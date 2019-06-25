#ifndef __DEBUG_H_
#define __DEBUG_H_

#include <stdlib.h>
#ifdef __i386__
    #include <devices/serial.h>

    #define debug(msg) com_print(COM1_PORT, msg);com_print(COM1_PORT, "\r\n")
    #define fail(msg) com_print(COM1_PORT, msg);abort()
#elif __arm__
    #define debug(msg) 
    #define fail(msg) abort()
#endif

#endif