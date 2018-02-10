#pragma once

#include "definitions.h"

///////////////////////////
//SYS
extern char memory_allocated[memShortSize];

///////////////////////////
//BIT CONTROL

int check_bit(char* _byte_);
void set_bit(char* _byte_, unsigned char bit);

////////////////////////////
//BASIC RAM CONTROL

void* malloc(size_t size);
void free(void* ptr);
void* calloc(size_t nmemb, size_t size);
void* realloc(void* ptr, size_t size);

/////////////////////////////
//MEMORY CONTROL

int memcmp(const void* a, const void* b, unsigned int size);
void* memcpy(void* destination, const void* from, unsigned int block_size);
void* memset(void* ptr, char value, size_t num);
