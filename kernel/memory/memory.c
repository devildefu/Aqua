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

void* m_alloc(size_t size) {
}