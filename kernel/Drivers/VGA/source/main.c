//Kirid VGA Driver
//#include "../include/Display.h"
//#include "../include/CRTC.h"
#include "../include/main.h"
#include "../include/VGA_DEF.h"
#include "../../../Include/definitions.h"
#define	pokeb(S,O,V)		*(unsigned char *)(16uL * (S) + (O)) = (V)
#define	peekb(S,O)		*(unsigned char *)(16uL * (S) + (O))

unsigned char MISC = 0xE3;
unsigned char SEQ[] = {
    0x99, 0x01, 0x00, 0x02
};
unsigned char CRTC[] = {
    0x5F, 0x4F, 0x50, 0x82, 0x54, 0x80, 0x0B, 0x3E, 0x00, 0x40, 0xEA, 0x8C, 0xDF, 0x28, 0x00, 0xE7, 0x04, 0xE3
};
unsigned char GC[] = {
    0x99, 0x99, 0x99, 0x99, 0x99, /*HERE*/ 0x00, 0x05
};
unsigned char AC[] = {
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, /*HERE*/ 0x01, 0x00, 0x0F, 0x00, 0x00
};

static inline void outb(uint16_t port, uint8_t val) {
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

static inline uint8_t inb(uint16_t port) {
	uint8_t ret;
	asm volatile ("inb %1, %0"
			: "=a"(ret)
			: "Nd"(port) );
	return ret;
}

static unsigned get_fb_seg(void)
{
	unsigned seg;

	outb(VGA_GC_INDEX, 6);
	seg = inb(VGA_GC_DATA);
	seg >>= 2;
	seg &= 3;
	switch(seg)
	{
	case 0:
	case 1:
		seg = 0xA000;
		break;
	case 2:
		seg = 0xB000;
		break;
	case 3:
		seg = 0xB800;
		break;
	}
	return seg;
}

static void vpokeb(unsigned off, unsigned val)
{
	pokeb(get_fb_seg(), off, val);
}

static unsigned vpeekb(unsigned off)
{
	return peekb(get_fb_seg(), off);
}

static void write_pixel1(unsigned x, unsigned y, unsigned c)
{
	unsigned wd_in_bytes;
	unsigned off, mask;

	c = (c & 1) * 0xFF;
	wd_in_bytes = 640 / 8;
	off = wd_in_bytes * y + x / 8;
	x = (x & 7) * 1;
	mask = 0x80 >> x;
	vpokeb(off, (vpeekb(off) & ~mask) | (c & mask));
}

void test(void) {
    unsigned i;

    outb(VGA_MISC_WRITE, MISC); //Set Miscellaneous register

    // SEQUENCER registers
    for(i = 0; i < 4; i++) {
        if(SEQ[i]!=0x99) {
            outb(VGA_SEQ_INDEX, i);
            outb(VGA_SEQ_DATA, SEQ[i]);
        }
    }

    // unclock CRTC registers
    outb(VGA_CRTC_INDEX, 0x03);
    outb(VGA_CRTC_DATA, inb(VGA_CRTC_DATA) | 0x80);
    outb(VGA_CRTC_INDEX, 0x11);
    outb(VGA_CRTC_DATA, inb(VGA_CRTC_DATA) & ~0x80);

    // CRTC registers
    for(i = 0; i < 18; i++) {
        outb(VGA_CRTC_INDEX, i);
        outb(VGA_CRTC_DATA, CRTC[i]);
    }

    // Graphics Controller registers
    for(i = 0; i < 7; i++) {
        if(GC[i]!=0x99) {
            outb(VGA_GC_INDEX, i);
            outb(VGA_GC_DATA, GC[i]);
        }
    }

    // Attribute Controller registers
    for(i = 0; i < 15; i++) {
        if(AC[i]!=0x99) {
            (void)inb(VGA_INSTAT_READ);
            outb(VGA_AC_INDEX, i);
            outb(VGA_AC_WRITE, AC[i]);
        }
    }

    (void)inb(VGA_INSTAT_READ);
    outb(VGA_AC_INDEX, 0x20);

    write_pixel1(5, 5, 1);
    write_pixel1(1, 1, 2);
}

void startVGA(void) {
    test();
    //DisableDisplay();
    //UnlockCRTC();

    //LoadRegisters();
    //ClearScreen();

    //LockCRTC();
    //EnableDisplay();
}