#include "Include/vga.h"
#include "Include/keyboard.h"
#include "Include/string.h"
#include "Include/time.h"
#include "Include/memory.h"
#include "kernelData.h"
#include "Include/cpu.h"


void kmain(void) {
	clear();
	color(0x0F);
	puts(kernelVer);

	CPU_INFO cpuData;
	CPUInfo(&cpuData);
	//puts(cpuData.name);

	return;
}
