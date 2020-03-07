/**
 * example05
 * @author Clay
 * @date 2020/2/29
 */

#include <stdio.h>

void test1(unsigned int x, unsigned int y);

void test2(int x, int y);

int main(void)
{
    test1(3000000000, 3000000000);
    test1(1, 3000000000);
    test1(1, 2);
    test1(3, 7);

    test2(2100000000, 2100000000);
    test2(-2100000000, -2100000000);
    test2(1, -3);
    test2(3, 999999999);

    return 0;
}

int uAddOk(unsigned int x, unsigned int y)
{
    unsigned int s = x + y;

    return s >= x && s >= y;
}

int tAddOk(int x, int y)
{
    if (x > 0 && y > 0)
    {
        return x + y > 0;
    }
    else if (x < 0 && y < 0)
    {
        return x + y < 0;
    }
    else
    {
        return 1;
    }
}

void test1(unsigned int x, unsigned int y)
{
    char const *prompt = uAddOk(x, y) ? "" : " not";

    printf("%u + %u is%s OK\n", x, y, prompt);
}

void test2(int x, int y)
{
    char const *prompt = tAddOk(x, y) ? "" : " not";

    printf("%d + %d is%s OK\n", x, y, prompt);
}
