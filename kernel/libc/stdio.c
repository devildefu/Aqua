#include <definitions.h>
#include <stdio.h>
#include <string.h>
#include <video/tty.h>

int fopen(const char* name, FILE* f) {
	int ret;
	f->pr(F_OPEN, &ret, sizeof(ret), f);
	return ret;
}

int fclose(FILE* f) {
	int ret;
	f->pr(F_CLOSE, &ret, sizeof(ret), f);
	return ret;
}

int fseek(FILE* f, int offset, int mode) {
	return (int)f->pr(F_SEEK, &offset, sizeof(int) * 2, f);
}

int fread(void* ptr, size_t size, size_t nitems, FILE* f) {
	return (int)f->pr(F_READ, &ptr, sizeof(void*) + sizeof(size_t) * 2, f);
}

int fwrite(const void* ptr, size_t size, size_t nitems, FILE* f) {
	return (int)f->pr(F_WRITE, &ptr, sizeof(void*) + sizeof(size_t) * 2, f);
}
