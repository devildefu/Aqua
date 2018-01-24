#pragma once
#include "definitions.h"

void atoi(char *str, int* a);

//void d2s(double n, char* string, size_t size, char dot) //<- Converts number to string

char* getStringn(char* ptr, unsigned int ptr_size); //<- Does not use malloc. Adds chars up to size(limit). Returns ptr
char* getStringc(char* ptr, unsigned int ptr_size, char CHAR); //<- Does not use malloc. Adds chars up to limit until char is the same as given. Returns ptr;

int strcmp(const char* a, const char* b); //<- Compares two strings. Returns 0 if all strings is the same;
