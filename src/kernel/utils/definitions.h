#ifndef __DEFINITIONS_H_
#define __DEFINITIONS_H_

#define memSize_b 10240
#define memPos 0x1010
#define memShortSize memSize_b / 8

#define GET_WAIT 1
#define GET_NOWAIT 2

#define null 0
#define NULL 0
typedef long long int64_t;
typedef unsigned long long uint64_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef char int8_t;
typedef unsigned char uint8_t;
typedef unsigned int size_t;
typedef enum { false = 0, true = 1 } bool;

#endif
