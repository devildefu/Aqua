#include "debug/debug.h"
#include "stdio.h"
#include <memory.h>

static alloc_table mall_table;

void init_ram_alloc_table(alloc_table* tab) {
	mall_table = *tab;
}

void init_ram(void* start, void* end, uint32_t limit) {
	mall_table.start = start;
	mall_table.end = end;
	mall_table.alloc_limit = limit;
}

/* Memory table starts at 1 MB */
const size_t mman_ptrs_start = 0x01000000;
/* 512 KB memory table */
const size_t mman_ptrs_end = mman_ptrs_start + 0x80000;

size_t last_address = mman_ptrs_start;
typedef struct {
	unsigned start;
	unsigned end;
} mman_cell;

void mreserve(size_t address, size_t size);

void mman_init() {
	debug("Initializing memory manager");
	debug("Clearing memory");
	for(size_t i = mman_ptrs_start; i < mman_ptrs_end; i++) {
		char* ptr = (char*)i;
		*ptr = 0x00;
	}
	debug("Reserving hardware addresses");
	/* Reserved memory */
	mreserve(0x00000000, 0x01000000);
	mreserve(mman_ptrs_start, mman_ptrs_end);
	/* Memory table */
	debug("Memory manager initialized.");
}

void mreserve(size_t start, size_t end) {
	char* ptr = (char*)last_address;
	mman_cell* memcell = (mman_cell*)ptr;

	memcell->start = start;
	memcell->end = end;

	last_address += sizeof(mman_cell);
}

void* malloc(size_t size) {
	size_t retry_count = 0;
	while(1) {
		char* ptr = (char*)last_address;

		mman_cell* memcell = (mman_cell*)ptr;
		/* Memory cell is free */
		if(memcell->start == 0x00 && memcell->end == 0x00) {
			char* wanted = 0x00;
			char* startaddress = 0x00;
			char ok = 0;
			while(!ok) {
				ok = 1;
				for(mman_cell* current = (mman_cell*)mman_ptrs_start; current < (mman_cell*)mman_ptrs_end; current++) {
					if((unsigned)wanted + size > current->start && (unsigned)wanted < current->end) {
						ok = 0;
						startaddress = (char*)current->end;
						break;
						/* Look further for free memory block */
					}
				}
				if(ok == 0) {
					wanted = startaddress;
				}
			}

			memcell->start = (unsigned)wanted;
			memcell->end = (unsigned)wanted + size;

			return wanted;
		}
		last_address += sizeof(mman_cell);
		if(last_address >= mman_ptrs_end) {
			last_address = mman_ptrs_start;
		}
		retry_count++;
		/* Look further for free memory block */
		if(retry_count > mman_ptrs_end - mman_ptrs_start) {
			return 0x00;
		}
	}
}

void free(void* ptr) {
	for(mman_cell* i = (mman_cell*)mman_ptrs_start; i < (mman_cell*)mman_ptrs_end; i++) {
		if((char*)i->start == ptr) {
			i->start = 0x00;
			i->end = 0x00;
		}
	}
}