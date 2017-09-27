#ifndef __KEYBOARD_H_
#define __KEYBOARD_H_

char getScancode();
char getchar();

//////////
///STR////
void atoi(char *str, int* a);

char* getStringn(unsigned int size); //<- Usses malloc. Adds chars from keyboard up to given limit
char* getStringc(char CHAR); //<- Usses malloc. Adds chars from keyboard until char is the same as given

int getStringnp(char* ptr, unsigned int ptr_size); //<- Does not use malloc. Adds chars up to size(limit)
int getStringcp(char* ptr, unsigned int ptr_size, char CHAR); //<- Does not use malloc. Adds chars up to limit until char is the same as given

int strcmp(const char* a, const char* b); //<- Compares to strings. Returns 0 if all strings is the same;

#endif
