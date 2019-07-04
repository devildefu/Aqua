#ifndef __FILE_H_
#define __FILE_H_

#include <stdint.h>
#include <stddef.h>

typedef enum _SEEK_L_ {
    SEEK_SET = 0,
    SEEK_CUR = 1,
    SEEK_END = 2
} SEEK_L;

typedef enum _PROCEDURES_L_ {
    F_SEEK = 0,
    F_WRITE = 1,
    F_READ = 2,
    F_OPEN = 3,
    F_CLOSE = 4

} PROCEDURES_L;

struct _FILE_;

/* FILE procedure. Used for IO calls */
typedef void*(*FILE_PROCEDURE)(int procedure, void* p, uint32_t size, struct _FILE_* that);

typedef struct _FILE_ {
    void* data;
    FILE_PROCEDURE pr;
} FILE;

int fopen(const char* name, FILE* f);
int fclose(FILE* f);
int fseek(FILE* f, int offset, int mode);
int fread(void* ptr, size_t size, size_t nitems, FILE* f);
int fwrite(const void* ptr, size_t size, size_t nitems, FILE* f);



#endif
