#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#ifdef _i386_
#include <video/tty.h>
#endif

void atoi(char* str, int* a);

//void d2s(double n, char* string, size_t size, char dot) //<- Converts number to string

char* get_stringn(char* ptr, unsigned int ptr_size); //<- Does not use malloc. Adds chars up to size(limit). Returns ptr
char* get_stringc(char* ptr, unsigned int ptr_size, char CHAR); //<- Does not use malloc. Adds chars up to limit until char is the same as given. Returns ptr;

int strcmp(const char* a, const char* b); //<- Compares two strings. Returns 0 if all strings is the same;

void htoa(uint32_t h, char* t);
void itoa(int32_t h, char* t);

bool reverse(void* _ptr, size_t size);
bool itos(int32_t integer, char* _ptr);

size_t strlen(const char* str);
char* strcpy(char* src, char* dest);