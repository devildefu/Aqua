#ifndef __MEMORY_H_
#define __MEMORY_H_

#include <stddef.h>
#include <stdint.h>

typedef struct _alloc_table {

	void* start;
	void* end;

	uint32_t alloc_limit;

} alloc_table;

typedef struct _alloc_data {

	void* start;
	uint32_t size;

	struct _alloc_data *left, *right;

} alloc_data;

void set_ram_alloc_table(alloc_table* al);
void init_ram(void* start, void* end, uint32_t alloc_limit);

void mman_init();
void* malloc(size_t size);
void free(void* ptr);

int memcmp(const void* a, const void* b, unsigned int size);
void* memcpy(void* destination, const void* from, unsigned int block_size);
void* memset(void* ptr, char value, size_t num);

#endif
