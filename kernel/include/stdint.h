#ifndef __STDINT_H_
#define __STDINT_H_

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

typedef int intptr_t;
typedef unsigned uintptr_t;

typedef unsigned int size_t;

typedef long long_t;
typedef unsigned long ulong_t;

#define UINT64_MAX 0xFFFFFFFFFFFFFFFF
#define UINT32_MAX 0xFFFFFFFF

#define UINTPTR_MAX UINT32_MAX

/* Number of digits in decimal numbers for MAX of variables */
#define UINT64_MAX_DECIMAL_BITS 20 
#define UINT32_MAX_DECIMAL_BITS 10
#define UINT16_MAX_DECIMAL_BITS 5
#define  UINT8_MAX_DECIMAL_BITS 3

#endif
