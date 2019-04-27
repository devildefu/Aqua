#include <kernel/include/cpu.h>

void cpuid(int32_t reg, int32_t* eax, int32_t* ebx, int32_t* ecx, int32_t* edx) {
    asm volatile( "cpuid"
            : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx)
            : "0" (reg) );
}

void cpu_info(CPU_INFO* _ptr) {
    //Variables for store cpuid return data
    int32_t eax, ebx, ecx, edx;

    char vendor[13];
    cpuid(0, &eax, (int32_t*)(vendor + 0), (int32_t*)(vendor + 8), (int32_t*)(vendor + 4));
    strcpy(vendor, _ptr->vendor);

    if (eax >= 0x01) {
        cpuid(0x01, &eax, &ebx, &ecx, &edx);

        if (edx & EDX_PSE)      _ptr->pse = 1;
        if (edx & EDX_PAE)      _ptr->pae = 1;
        if (edx & EDX_APIC)     _ptr->apic = 1;
        if (edx & EDX_MTRR)     _ptr->mtrr = 1;
        if (edx & EDX_TSC)      _ptr->tsc = 1;
        if (edx & EDX_MSR)      _ptr->msr = 1;
        if (edx & EDX_SSE)      _ptr->sse = 1;
        if (edx & EDX_SSE2)     _ptr->sse2 = 1;
        if (ecx & ECX_SSE3)     _ptr->sse3 = 1;
        if (ecx & ECX_SSSE3)    _ptr->ssse3 = 1;
        if (ecx & ECX_SSE41)    _ptr->sse41 = 1;
        if (ecx & ECX_SSE42)    _ptr->sse42 = 1;
        if (ecx & ECX_AVX)      _ptr->avx = 1;
        if (ecx & ECX_F16C)     _ptr->f16c = 1;
        if (ecx & ECX_RDRAND)   _ptr->rdrand = 1;
    }

    cpuid(0x80000000, &eax, &ebx, &ecx, &edx);
    if (eax >= 0x80000001) {
        cpuid(0x80000001, &eax, &ebx, &ecx, &edx);
        if (edx & EDX_64_BIT) {
            strcpy("amd64", _ptr->architecture);
        } else {
            strcpy("i686", _ptr->architecture);
        }
    }

    if (eax >= 0x80000004) {
        char name[48];
        cpuid(0x80000002, (int32_t*)(name +  0), (int32_t*)(name +  4), (int32_t*)(name +  8), (int32_t*)(name + 12));
        cpuid(0x80000003, (int32_t*)(name + 16), (int32_t*)(name + 20), (int32_t*)(name + 24), (int32_t*)(name + 28));
        cpuid(0x80000004, (int32_t*)(name + 32), (int32_t*)(name + 36), (int32_t*)(name + 40), (int32_t*)(name + 44));

        strcpy(name, _ptr->name);
    }
}

void cpu_print_info(CPU_INFO* _ptr) {
    printf("CPU Vendor: %s\n", _ptr->vendor);
    printf("CPU Name: %s\n", _ptr->name);
    printf("CPU Architecture: %s\n", _ptr->architecture);
    printf("CPU supported features: ");
    if (_ptr->pse == 1)      printf("PSE ");
    if (_ptr->pae == 1)      printf("PAE ");
    if (_ptr->apic == 1)     printf("APIC ");
    if (_ptr->mtrr == 1)     printf("MTRR");
    printf("\nCPU supported instructions: ");
    if (_ptr->tsc == 1)      printf("TSC ");
    if (_ptr->msr == 1)      printf("MSR ");
    if (_ptr->sse == 1)      printf("SSE ");
    if (_ptr->sse2 == 1)     printf("SSE2 ");
    if (_ptr->sse3 == 1)     printf("SSE3 ");
    if (_ptr->ssse3 == 1)    printf("SSSE3 ");
    if (_ptr->sse41 == 1)    printf("SSE41 ");
    if (_ptr->sse42 == 1)    printf("SSE42 ");
    if (_ptr->avx == 1)      printf("AVX ");
    if (_ptr->f16c == 1)     printf("F16C ");
    if (_ptr->rdrand == 1)   printf("RDRAND");
    printf("\n");
}