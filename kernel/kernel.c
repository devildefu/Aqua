#include "Include/vga.h"
#include "Include/keyboard.h"
#include "Include/string.h"
#include "Include/time.h"
#include "Include/memory.h"
#include "kernelData.h"
#include "Include/cpu.h"
#include "Include/io.h"
#include "Shell/Shell.h"
#include "Drivers/ATA/ata.h"

void kmain(void) {
	clear();
	color(0x0F);

	//Kernel Logs
	CPU_INFO cpuData;
	CPUInfo(&cpuData);

	puts("[Kernel] Kernel Version: ");
	puts(kernelVer);
	newLine();
	puts("[CPU] Manufacturer: ");
	puts(cpuData.vendor);
	newLine();
	puts("[CPU] Name: ");
	puts(cpuData.name);
	newLine();
	//puts("[Kernel] Starting main shell...");

	//shell();
	puts("[Disks] Detected: ");
	newLine();
	puts("0x1F0: ");
	puts(inb(0x1F0));
	newLine();
	puts("0x1F1: ");
	puts(inb(0x1F1));
	newLine();
	puts("0x1F2: ");
	puts(inb(0x1F2));
	newLine();
	puts("0x1F3: ");
	puts(inb(0x1F3));
	newLine();
	puts("0x1F4: ");
	puts(inb(0x1F4));
	newLine();
	puts("0x1F5: ");
	puts(inb(0x1F5));
	newLine();
	puts("0x1F6: ");
	puts(inb(0x1F6));
	newLine();
	puts("0x1F7: ");
	puts(inb(0x1F7));
	newLine();

	outb(0x1F5, 0xA0);
	newLine();
	puts("0x1F6: ");
	puts(inb(0x1F5));
	outb(0x1F7, 0xEC);
	puts(inb(0x1F7));

	newLine();
	puts("[Kernel] Exit");

	return;
}
