#ifndef CPU_H
#define CPU_H

#define ECX_SSE3                        (1 << 0)    // Streaming SIMD Extensions 3
#define ECX_PCLMULQDQ                   (1 << 1)    // PCLMULQDQ Instruction
#define ECX_DTES64                      (1 << 2)    // 64-Bit Debug Store Area
#define ECX_MONITOR                     (1 << 3)    // MONITOR/MWAIT
#define ECX_DS_CPL                      (1 << 4)    // CPL Qualified Debug Store
#define ECX_VMX                         (1 << 5)    // Virtual Machine Extensions
#define ECX_SMX                         (1 << 6)    // Safer Mode Extensions
#define ECX_EST                         (1 << 7)    // Enhanced SpeedStep Technology
#define ECX_TM2                         (1 << 8)    // Thermal Monitor 2
#define ECX_SSSE3                       (1 << 9)    // Supplemental Streaming SIMD Extensions 3
#define ECX_CNXT_ID                     (1 << 10)   // L1 Context ID
#define ECX_FMA                         (1 << 12)   // Fused Multiply Add
#define ECX_CX16                        (1 << 13)   // CMPXCHG16B Instruction
#define ECX_XTPR                        (1 << 14)   // xTPR Update Control
#define ECX_PDCM                        (1 << 15)   // Perf/Debug Capability MSR
#define ECX_PCID                        (1 << 17)   // Process-context Identifiers
#define ECX_DCA                         (1 << 18)   // Direct Cache Access
#define ECX_SSE41                       (1 << 19)   // Streaming SIMD Extensions 4.1
#define ECX_SSE42                       (1 << 20)   // Streaming SIMD Extensions 4.2
#define ECX_X2APIC                      (1 << 21)   // Extended xAPIC Support
#define ECX_MOVBE                       (1 << 22)   // MOVBE Instruction
#define ECX_POPCNT                      (1 << 23)   // POPCNT Instruction
#define ECX_TSC                         (1 << 24)   // Local APIC supports TSC Deadline
#define ECX_AESNI                       (1 << 25)   // AESNI Instruction
#define ECX_XSAVE                       (1 << 26)   // XSAVE/XSTOR States
#define ECX_OSXSAVE                     (1 << 27)   // OS Enabled Extended State Management
#define ECX_AVX                         (1 << 28)   // AVX Instructions
#define ECX_F16C                        (1 << 29)   // 16-bit Floating Point Instructions
#define ECX_RDRAND                      (1 << 30)   // RDRAND Instruction

#define EDX_FPU                         (1 << 0)    // Floating-Point Unit On-Chip
#define EDX_VME                         (1 << 1)    // Virtual 8086 Mode Extensions
#define EDX_DE                          (1 << 2)    // Debugging Extensions
#define EDX_PSE                         (1 << 3)    // Page Size Extension
#define EDX_TSC                         (1 << 4)    // Time Stamp Counter
#define EDX_MSR                         (1 << 5)    // Model Specific Registers
#define EDX_PAE                         (1 << 6)    // Physical Address Extension
#define EDX_MCE                         (1 << 7)    // Machine-Check Exception
#define EDX_CX8                         (1 << 8)    // CMPXCHG8 Instruction
#define EDX_APIC                        (1 << 9)    // APIC On-Chip
#define EDX_SEP                         (1 << 11)   // SYSENTER/SYSEXIT instructions
#define EDX_MTRR                        (1 << 12)   // Memory Type Range Registers
#define EDX_PGE                         (1 << 13)   // Page Global Bit
#define EDX_MCA                         (1 << 14)   // Machine-Check Architecture
#define EDX_CMOV                        (1 << 15)   // Conditional Move Instruction
#define EDX_PAT                         (1 << 16)   // Page Attribute Table
#define EDX_PSE36                       (1 << 17)   // 36-bit Page Size Extension
#define EDX_PSN                         (1 << 18)   // Processor Serial Number
#define EDX_CLFLUSH                     (1 << 19)   // CLFLUSH Instruction
#define EDX_DS                          (1 << 21)   // Debug Store
#define EDX_ACPI                        (1 << 22)   // Thermal Monitor and Software Clock Facilities
#define EDX_MMX                         (1 << 23)   // MMX Technology
#define EDX_FXSR                        (1 << 24)   // FXSAVE and FXSTOR Instructions
#define EDX_SSE                         (1 << 25)   // Streaming SIMD Extensions
#define EDX_SSE2                        (1 << 26)   // Streaming SIMD Extensions 2
#define EDX_SS                          (1 << 27)   // Self Snoop
#define EDX_HTT                         (1 << 28)   // Multi-Threading
#define EDX_TM                          (1 << 29)   // Thermal Monitor
#define EDX_PBE                         (1 << 31)   // Pending Break Enable

// ------------------------------------------------------------------------------------------------
// Extended Function 0x01

#define EDX_SYSCALL                     (1 << 11)   // SYSCALL/SYSRET
#define EDX_XD                          (1 << 20)   // Execute Disable Bit
#define EDX_1GB_PAGE                    (1 << 26)   // 1 GB Pages
#define EDX_RDTSCP                      (1 << 27)   // RDTSCP and IA32_TSC_AUX
#define EDX_64_BIT                      (1 << 29)   // 64-bit Architecture

#include <kernel/include/definitions.h>

typedef struct {
    /* CPU basic informations */
        char vendor[13];
        char name[48];
        char architecture[5];
    /* CPU features */
        uint8_t pse;
        uint8_t pae;
        uint8_t apic;
        uint8_t mtrr;
    /* CPU instructions */
        uint8_t tsc;
        uint8_t msr;
        uint8_t sse;
        uint8_t sse2;
        uint8_t sse3;
        uint8_t ssse3;
        uint8_t sse41;
        uint8_t sse42;
        uint8_t avx;
        uint8_t f16c;
        uint8_t rdrand;
} CPU_INFO;

void cpuid(int32_t reg, int32_t* eax, int32_t* ebx, int32_t* ecx, int32_t* edx) {
    asm volatile( "cpuid"
            : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx)
            : "0" (reg) );
}

void CPUInfo(CPU_INFO* _ptr) {
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

void CPUInfoPrint(CPU_INFO* _ptr) {
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

#endif
