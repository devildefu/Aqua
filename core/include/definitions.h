#ifndef __DEFINITIONS_H_
#define __DEFINITIONS_H_

#define INT_MAX 2147483647

#define memSize_b 10240
#define memPos 0x1010
#define memShortSize memSize_b / 8

#define GET_WAIT 1
#define GET_NOWAIT 2

#define null 0
#define NULL 0
/* 8 bytes */
typedef long long int64_t;
typedef unsigned long long uint64_t;

/* 4 bytes */
typedef int int32_t;
typedef unsigned int uint32_t;

/* 2 bytes */
typedef short int16_t;
typedef unsigned short uint16_t;

/* 1 byte */
typedef char int8_t;
typedef unsigned char uint8_t;

typedef unsigned int size_t;
typedef enum { false = 0, true = 1 } bool;

#define _packed_ __attribute__((packed))

#endif
