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
