/**
 * practice02
 * @author Clay
 * @date 2020/3/12
 */

#include <stdio.h>

void test1(void);

void test2(unsigned int x, unsigned int y);

void test3(unsigned int x, unsigned int i, unsigned char b);

int main(void)
{
    test1();

    test2(0x89abcdef, 0x76543210);

    test3(0x12345678, 2, 0xAB);
    test3(0x12345678, 0, 0xAB);

    return 0;
}

int isLittleEndian(void)
{
    unsigned int x = 0x10;

    return (x >> 9u) == 0;
}

unsigned int practice59(unsigned int x, unsigned int y)
{
    unsigned int flag = 0xff;

    return (x & flag) | (y & ~flag);
}

unsigned int replaceByte(unsigned int x, unsigned int i, unsigned int b)
{
    return (x & ~(0xffu << i * 8u)) | (b << i * 8u);
}

void test1(void)
{
    char const *prompt = isLittleEndian() ? "" : " not";
    printf("This is%s little endian.\n", prompt);
}

void test2(unsigned int x, unsigned int y)
{
    printf("0x%x\n", practice59(x, y));
}

void test3(unsigned int x, unsigned int i, unsigned char b)
{
    printf("replace_byte(0x%x, %d, 0x%x) --> 0x%x\n", x, i, b, replaceByte(x, i, b));
}
