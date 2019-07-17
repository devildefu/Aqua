#include <memory.h>
#include "stdio.h"
#include "debug/debug.h"

static alloc_table mall_table;

void init_ram_alloc_table(alloc_table* tab) {
    mall_table = *tab;
}

void init_ram(void* start, void* end, uint32_t limit) {
    mall_table.start = start;
    mall_table.end = end;
    mall_table.alloc_limit = limit;
    
}

//Memory manager
const size_t mman_ptrs_start = 0x10000; //memory table starts at 64 KB
const size_t mman_ptrs_end = mman_ptrs_start + 0x80000; //512 KB memory table

size_t last_address = mman_ptrs_start;
typedef struct {
	unsigned start;
	unsigned end;
} mman_cell;

void mreserve(size_t address, size_t size);

void mman_init(){
	debug("Initializing memory manager");
	debug("Clearing memory");
	for(size_t i = mman_ptrs_start; i<mman_ptrs_end; i++){
		char* ptr = (char*) i;
		*ptr = 0x00;
	}
	debug("Reserving hardware addresses");
	mreserve(0x00000000, 0x01000000);//Reserved memory
	debug("Memory manager initialized.");
}

void mreserve(size_t start, size_t end){
	char* ptr = (char*)last_address;
	mman_cell* memcell = (mman_cell*)ptr;

	memcell->start = start;
	memcell->end = end;

	last_address += sizeof(mman_cell);
}

void* malloc(size_t size){
	size_t retry_count=0;
	while(1){
		char* ptr = (char*)last_address;
		
		mman_cell* memcell = (mman_cell*)ptr;
		if(memcell->start == 0x00 && memcell->end == 0x00){//Memory cell is free
			char* wanted = 0x00;
			char* startaddress = 0x00;
			char ok=0;
			while(!ok){
				ok=1;
				for(mman_cell* current = (mman_cell*)mman_ptrs_start; current<(mman_cell*)mman_ptrs_end; current++){
					if((unsigned)wanted + size > current->start&&(unsigned)wanted<current->end){
						ok=0;
						startaddress = (char*)current->end;
						break;
						//Look further for free memory block
					}
				}
				if(ok==0){
					wanted = startaddress;
				}
			}

			memcell->start = (unsigned)wanted;
			memcell->end = (unsigned)wanted + size;

			return wanted;
		}
		last_address += sizeof(mman_cell);
		if(last_address>=mman_ptrs_end){
			last_address = mman_ptrs_start;
		}
		retry_count++;
		if(retry_count>mman_ptrs_end-mman_ptrs_start){//Out of memory (no more space in pointer table)
			return 0x00;
		}
	}
}

void free(void* ptr){
	for(mman_cell* i = (mman_cell*)mman_ptrs_start; i<(mman_cell*)mman_ptrs_end; i++){
		if((char*)i->start == ptr){
			i->start = 0x00;
			i->end = 0x00;
		}
	}
}


int memcmp(const void* a, const void* b, unsigned int size) {
    if(size>0) {
        unsigned int goodbytes = 0;
        for(int i = 0; i<size; i++) {
            if(((const char*)a)[i] == ((const char*)b)[i]) goodbytes++;
        }
        if(goodbytes>=size) return 0;
        if(((const char*)a)[0] > ((const char*)b)[0]) return 1;
        if(((const char*)a)[0] < ((const char*)b)[0]) return -1;
    }
    return 1;
}

void* memcpy(void* destination, const void* from, unsigned int block_size) {
    if(block_size>0) {
        for(int i = 0; i<block_size; i++) {
            ((char*)destination)[i] = ((const char*)from)[i];
        }
    }
    return destination;
}

void* memset(void* ptr, char value, size_t num) {
    if(num>0) {
        for(int i = 0; i<num; i++) {
            ((char*)ptr)[i] = value;
        }
    }
    return ptr;
}
