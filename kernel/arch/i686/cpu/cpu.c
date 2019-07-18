#include <cpu/cpu.h>

void cpu_cpuid(int32_t reg, int32_t* eax, int32_t* ebx, int32_t* ecx, int32_t* edx) {
	asm volatile("cpuid"
				 : "=a"(*eax), "=b"(*ebx), "=c"(*ecx), "=d"(*edx)
				 : "0"(reg));
}

void cpu_info(CPU_INFO* _ptr) {
	//Variables for store cpu_cpuid return data
	int32_t eax, ebx, ecx, edx;

	/* TODO: Fix vendor name */
	char vendor[13];
	cpu_cpuid(0, &eax, (int32_t*)(vendor + 0), (int32_t*)(vendor + 8), (int32_t*)(vendor + 4));
	strcpy(vendor, _ptr->vendor);

	if(eax >= 0x01) {
		cpu_cpuid(0x01, &eax, &ebx, &ecx, &edx);

		if(edx & EDX_PSE) _ptr->pse = 1;
		if(edx & EDX_PAE) _ptr->pae = 1;
		if(edx & EDX_APIC) _ptr->apic = 1;
		if(edx & EDX_MTRR) _ptr->mtrr = 1;
		if(edx & EDX_TSC) _ptr->tsc = 1;
		if(edx & EDX_MSR) _ptr->msr = 1;
		if(edx & EDX_SSE) _ptr->sse = 1;
		if(edx & EDX_SSE2) _ptr->sse2 = 1;
		if(ecx & ECX_SSE3) _ptr->sse3 = 1;
		if(ecx & ECX_SSSE3) _ptr->ssse3 = 1;
		if(ecx & ECX_SSE41) _ptr->sse41 = 1;
		if(ecx & ECX_SSE42) _ptr->sse42 = 1;
		if(ecx & ECX_AVX) _ptr->avx = 1;
		if(ecx & ECX_F16C) _ptr->f16c = 1;
		if(ecx & ECX_RDRAND) _ptr->rdrand = 1;
	}

	cpu_cpuid(0x80000000, &eax, &ebx, &ecx, &edx);
	if(eax >= 0x80000001) {
		cpu_cpuid(0x80000001, &eax, &ebx, &ecx, &edx);
		if(edx & EDX_64_BIT) {
			strcpy("amd64", _ptr->architecture);
		} else {
			strcpy("i686", _ptr->architecture);
		}
	}

	/* TODO: Fix name */
	if(eax >= 0x80000004) {
		char name[48];
		cpu_cpuid(0x80000002, (int32_t*)(name + 0), (int32_t*)(name + 4), (int32_t*)(name + 8), (int32_t*)(name + 12));
		cpu_cpuid(0x80000003, (int32_t*)(name + 16), (int32_t*)(name + 20), (int32_t*)(name + 24), (int32_t*)(name + 28));
		cpu_cpuid(0x80000004, (int32_t*)(name + 32), (int32_t*)(name + 36), (int32_t*)(name + 40), (int32_t*)(name + 44));

		strcpy(name, _ptr->name);
	}
}

void cpu_print_info() {
	/* TODO: print to serial port instead of screen */
	CPU_INFO* info;
	cpu_info(info);

	//printf("CPU Vendor: %s\n", info->vendor);
	//printf("CPU Name: %s\n", info->name);
	//printf("CPU Architecture: %s\n", info->architecture);
	printf("CPU supported features: ");
	if(info->pse == 1) printf("PSE ");
	if(info->pae == 1) printf("PAE ");
	if(info->apic == 1) printf("APIC ");
	if(info->mtrr == 1) printf("MTRR");
	printf("\nCPU supported instructions: ");
	if(info->tsc == 1) printf("TSC ");
	if(info->msr == 1) printf("MSR ");
	if(info->sse == 1) printf("SSE ");
	if(info->sse2 == 1) printf("SSE2 ");
	if(info->sse3 == 1) printf("SSE3 ");
	if(info->ssse3 == 1) printf("SSSE3 ");
	if(info->sse41 == 1) printf("SSE41 ");
	if(info->sse42 == 1) printf("SSE42 ");
	if(info->avx == 1) printf("AVX ");
	if(info->f16c == 1) printf("F16C ");
	if(info->rdrand == 1) printf("RDRAND");
	printf("\n");
}