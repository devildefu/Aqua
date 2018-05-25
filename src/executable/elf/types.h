/* ELF Documentation:
 * http://www.skyfree.org/linux/references/ELF_Format.pdf
 * */

#ifndef ELF_TYPES_H
#define ELF_TYPES_H

#include <utils/definitions.h>

/*  ELF TYPES
 *  Elf32_Addr has 4 bytes
 *  Elf32_Half has 2 bytes
 *  Elf32_Off has 4 bytes
 *  Elf32_Sword has 4 bytes
 *  Elf32_Word has 4 bytes
 *
 *  Addr is different program address,
 *  Half medium integer,
 *  Off file offset,
 *  Sword is signed large integer,
 *  Word is just unsigned,
 *  Welp, also is needed 'unsigned char', but compiler has it builtin
 * */

typedef uint32_t Elf32_Addr;
typedef uint16_t Elf32_Half;
typedef uint32_t Elf32_Off;
typedef int32_t Elf32_Sword;
typedef uint32_t Elf32_Word;

#endif
