/**
 * example05
 * @author Clay
 * @date 2020/2/29
 */

#include <stdio.h>

void test1(unsigned int x, unsigned int y);

int main(void)
{
    test1(3000000000, 3000000000);
    test1(1, 3000000000);
    test1(1, 2);
    test1(3, 7);

    return 0;
}

int uAddOk(unsigned int x, unsigned int y)
{
    unsigned int s = x + y;

    return s >= x && s >= y;
}

void test1(unsigned int x, unsigned int y)
{
    char const *prompt = uAddOk(x, y) ? "" : " not";

    printf("%u + %u is%s OK\n", x, y, prompt);
}
