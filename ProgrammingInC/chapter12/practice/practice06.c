/**
 * practice06
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>
#include <math.h>

unsigned int _intSize(void);

unsigned int intSize = 0;

int bitpatSearch(unsigned int source, unsigned int pattern, unsigned int length);
unsigned int bitpatGet(unsigned int source, unsigned int start, unsigned int length);
unsigned int bitpatSet(unsigned int source, unsigned int value, unsigned int start, unsigned int length);

int main(void)
{
    intSize = _intSize();

    printf("%x\n", bitpatGet(0xf1, 0, 4));
    printf("%x\n", bitpatGet(0xf1, 4, 4));
    printf("%x\n", bitpatSet(0xf1, 0x1, 4, 4));
    printf("%x\n", bitpatSet(0xf1, 0xc, 0, 4));
    printf("%i\n", bitpatSearch(0xf1, 0x1, 4));
    printf("%i\n", bitpatSearch(0xf1, 0x1, 3));
    printf("%i\n", bitpatSearch(0xf1, 0xf, 4));
    printf("%i\n", bitpatSearch(0xf1, 0xf, 3));
    printf("%i\n", bitpatSearch(0xf1, 0x3, 3));

    return 0;
}

unsigned int _intSize(void)
{
    unsigned int i = ~0u, s = 0;

    while (i)
    {
        ++s;
        i >>= 1u;
    }

    return s;
}

unsigned int bitSet(unsigned int source, unsigned int start, unsigned int length)
{
    unsigned int value = (unsigned int)pow(2, length) - 1;

    return source | (value << start);
}

unsigned int bitClear(unsigned int source, unsigned int start, unsigned int length)
{
    unsigned int value = (unsigned int)pow(2, length) - 1;

    return source & ~(value << start);
}

int bitpatSearch(unsigned int source, unsigned int pattern, unsigned int length)
{
    unsigned int p = (bitSet(0, 0, length) & pattern);
    int flag = -1;

    for (int i = 0, len = intSize - length; i <= len; ++i)
    {
        if (p == bitpatGet(source, i, length))
        {
            flag = i;

            break;
        }
    }

    return flag;
}

unsigned int bitpatGet(unsigned int source, unsigned int start, unsigned int length)
{
    if (!length) return 0;

    return source << (intSize - start - length) >> (intSize - length);
}



unsigned int bitpatSet(unsigned int source, unsigned int value, unsigned int start, unsigned int length)
{
    unsigned int s = bitClear(source, start, length);
    unsigned int v = (bitSet(0, 0, length) & value) << start;

    return s | v;
}
