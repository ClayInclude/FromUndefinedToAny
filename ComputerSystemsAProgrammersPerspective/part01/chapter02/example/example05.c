/**
 * example05
 * @author Clay
 * @date 2020/2/29
 */

#include <stdio.h>
#include <stdint.h>

void test1(unsigned int x, unsigned int y);

void test2(int x, int y);

void test3(int x, int y);

void test4(int x, int y);

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

    test3(2100000000, 2100000000);
    test3(-2100000000, -2100000000);
    test3(1, -3);
    test3(3, 999999999);

    test4(2100000000, 2100000000);
    test4(-2100000000, -2100000000);
    test4(1, -3);
    test4(3, 999999999);

    return 0;
}

int uAddOk(unsigned int x, unsigned int y)
{
    unsigned int s = x + y;

    return s >= x && s >= y;
}

int tAddOk(int x, int y)
{
    int sum = x + y;

    unsigned int negOver = x < 0 && y < 0 && sum >= 0;
    unsigned int posOver = x >= 0 && y >= 0 && sum < 0;

    return !(negOver || posOver);
}

int tMultiOk(int x, int y)
{
    int p = x * y;

    return !x || p / x == y;
}

int tMultiOk32(int32_t x, int32_t y)
{
    int64_t p = (int64_t) x * y;

    return x * y == p;
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

void test3(int x, int y)
{
    char const *prompt = tMultiOk(x, y) ? "" : " not";

    printf("%d * %d is%s OK\n", x, y, prompt);
}

void test4(int32_t x, int32_t y)
{
    char const *prompt = tMultiOk32(x, y) ? "" : " not";

    printf("%d * %d is%s OK\n", x, y, prompt);
}
