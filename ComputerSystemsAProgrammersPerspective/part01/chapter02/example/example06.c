/**
 * example06
 * @author Clay
 * @date 2020/3/10
 */

#include <stdio.h>

void test1(int x);

int main(void)
{
    test1(16);
    test1(17);
    test1(0);
    test1(-16);
    test1(-17);
    test1(8);
    test1(-8);

    return 0;
}

int div16(int x)
{
    return (int) ((x + ((x >> 31u) & 0xfu)) >> 4u); // NOLINT(hicpp-signed-bitwise)
}

void test1(int x)
{
    printf("%d / 16 = %d\n", x, div16(x));
}
