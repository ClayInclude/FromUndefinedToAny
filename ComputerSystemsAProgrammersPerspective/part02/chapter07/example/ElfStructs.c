#include <stddef.h>

/**
 * ElfStructs
 * @author Clay
 * @date 2020/12/21
 */

typedef struct
{
    /**
     * String table offset
     */
    int name;

    /**
     * Function or data (4 bits)
     */
    char type: 4;
    /**
     * Local or global (4 bits)
     */
    char binding: 4;

    /**
     * Unused
     */
    char reserved;

    /**
     * Section header index
     */
    short section;

    /**
     * Section offset or absolute address
     */
    long value;

    /**
     * Object size in bytes
     */
    long size;
} Elf64Symbol;

enum RelaType
{
    R_X86_64_PC32,

    R_X86_64_32
};

typedef struct
{
    /**
     * Offset of the reference to relocate
     */
    long offset;

    /**
     * Relocation type
     */
    enum RelaType type: 32;

    /**
     * Symbol table index
     */
    long symbol: 32;

    /**
     * Constant part of relocation expression
     */
    long addend;
} ELF64_Rela;

#define SECTION_SIZE 10
#define ENTRY_SIZE 10

#define ADDR(s) s

long section[SECTION_SIZE];
ELF64_Rela entry[ENTRY_SIZE];

void relocate()
{
    size_t *refPtr, refAddr;

    for (int i = 0; i < SECTION_SIZE; ++i)
    {
        int s = section[i];

        for (int j = 0; j < ENTRY_SIZE; ++j)
        {
            refPtr = (size_t *) (s + entry[j].offset);

            if (entry[j].type == R_X86_64_PC32)
            {

            }

            switch (entry[j].type)
            {
                case R_X86_64_PC32:
                {
                    refAddr = ADDR(s) + entry[j].offset;
                    *refPtr = (size_t) (ADDR(entry[j].symbol) + entry[j].addend - refAddr);

                    break;
                }
                case R_X86_64_32:
                    *refPtr = (size_t) (ADDR(entry[j].symbol) + entry[j].addend);
                    break;
                default:
                    break;
            }
        }
    }
}
