#ifndef TAR_H
#define TAR_H

struct _Tar {
	char filename[100];
	char mode[8];
	char oid[8];
	char gid[8];
	char size[12];
	char time[12];
	char checksum[8];
	char type[1];
};

typedef struct _Tar Tar;

#endif