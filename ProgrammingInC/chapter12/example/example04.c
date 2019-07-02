/**
 * example04
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

unsigned int rotate(unsigned int value, int n);
unsigned int _intSize(void);

unsigned int intSize = 0;

int main(void)
{
    unsigned int w1 = 0xabcdef00u, w2 = 0xffff1122u;

    intSize = _intSize();

    printf("%x\n", rotate(w1, 8));
    printf("%x\n", rotate(w1, -16));
    printf("%x\n", rotate(w2, 4));
    printf("%x\n", rotate(w2, -2));
    printf("%x\n", rotate(w1, 0));
    printf("%x\n", rotate(w1, 44));

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

unsigned int rotateLeft(unsigned int value, unsigned int n)
{
    unsigned int leftPart = value >> (intSize - n), rightPart = value << n;

    return leftPart | rightPart;
}

unsigned int rotateRight(unsigned int value, unsigned int n)
{
    unsigned int leftPart = value >> n, rightPart = value << (intSize - n);

    return leftPart | rightPart;
}

unsigned int rotate(unsigned int value, int n)
{
    if (n > 0)
    {
        return rotateLeft(value, (unsigned int) n);
    }
    else
    {
        return rotateRight(value, (unsigned int) -n);
    }
}
