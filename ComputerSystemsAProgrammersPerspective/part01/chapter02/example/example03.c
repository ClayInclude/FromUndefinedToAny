/**
 * example03
 * @author Clay
 * @date 2020/2/26
 */

#include <stdio.h>

void testBoolOr(int x, int y);

void testBoolXor(int x, int y);

int main(void)
{
    testBoolOr(0x1234, 0x0);
    testBoolOr(0x123, (int)~0x0u);

    testBoolXor(0x1234, 0x0);
    testBoolXor(0x123, (int)~0x0u);

    return 0;
}

unsigned int bis(unsigned int x, unsigned int m)
{
    return x | m;
}

unsigned int bic(unsigned int x, unsigned int m)
{
    return x & ~m;
}

unsigned int boolOr(unsigned int x, unsigned int y)
{
    return bis(x, y);
}

unsigned int boolXor(unsigned int x, unsigned int y)
{
    return bis(bic(x, y), bic(y, x));
}

void testBoolOr(int x, int y)
{
    printf("x: %x, y: %x, or: %x\n", x, y, boolOr(x, y));
}

void testBoolXor(int x, int y)
{
    printf("x: %x, y: %x, xor: %x\n", x, y, boolXor(x, y));
}
