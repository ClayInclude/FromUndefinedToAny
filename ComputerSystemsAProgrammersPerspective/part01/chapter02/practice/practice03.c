/**
 * practice03
 * @author Clay
 * @date 2020/3/12
 */

#include <stdint.h>
#include <stdio.h>

void test61(int x);

void test62(void);

void test63(int x, unsigned int u, int k);

void test64(unsigned int x);

void test65(unsigned int x);

void test66(unsigned int x);

void test67();

void test68(unsigned int n);

void test69(unsigned int x, unsigned int n);

void test70(int x, unsigned int n);

void test71(unsigned int word);

void test73(int x, int y);

void test74(int x, int y);

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "bugprone-narrowing-conversions"
int main(void)
{
    test61(0xFF111100);
    test61(0xFF1111FF);
    test61(0xFFFFFFFF);
    test61(0x00000000);
    test61(0x11111111);

    test62();

    test63(0x80000000, 0x80000000,31);
    test63(0xF0000000, 0xF0000000,31);
    test63(0xF0000000, 0xF0000000, 1);

    test64(1);
    test64(2);
    test64(3);
    test64(4);
    test64(8);

    test65(0x1);
    test65(0x2);
    test65(0x3);
    test65(0x11111);
    test65(0x2222);

    test66(0xffff);
    test66(0x6600);
    test66(0);
    test66(0x8000);

    test67();

    test68(6);
    test68(17);
    test68(32);

    test69(0x12345678, 4);
    test69(0x12345678, 20);
    test69(0x12345678, 0);

    test70(0, 0);
    test70(0, 1);
    test70(1, 1);
    test70(-1, 1);
    test70(-11, 4);

    test71(1);
    test71(0xffff);

    test73(12345, -54321);
    test73(2147483647, 1);
    test73(-2147483648, -1);
    test73(-1, -1);
    test73(1, 1);

    test74(1, 0x80000000);
    test74(0x80000000, 0);
    test74(0x80000000, 1);
    test74(0x80000000, -1);
    test74(100, 1);
    test74(100, -1);
    test74(100000000, 100000);
    test74(100, 100);
    test74(100, -100);
    test74(-100, -1);

    return 0;
}
#pragma clang diagnostic pop

int practice61_1(int x)
{
    return !(~x); // NOLINT(hicpp-signed-bitwise)
}

int practice61_2(int x)
{
    return !x;
}

int practice61_3(int x)
{
    return !~(x | ~0xffu); // NOLINT(hicpp-signed-bitwise)
}

int practice61_4(int x)
{
    return !(x & 0xffu << ((sizeof(x) - 1) << 3)); // NOLINT(hicpp-signed-bitwise)
}

void test61(int x)
{
    printf("1. x = 0x%x, result = %d.\n", x, practice61_1(x));
    printf("2. x = 0x%x, result = %d.\n", x, practice61_2(x));
    printf("3. x = 0x%x, result = %d.\n", x, practice61_3(x));
    printf("4. x = 0x%x, result = %d.\n", x, practice61_4(x));
    printf("\n");
}

int intShiftsAreArithmetic(void)
{
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCSimplifyInspection"
    return !~(~0x1 >> 1u); // NOLINT(hicpp-signed-bitwise)
#pragma clang diagnostic pop
}

void test62(void)
{
    char const *prompt = intShiftsAreArithmetic() ? "" : " not";

    printf("Int shifts are%s arithmetic.\n\n", prompt);
}

unsigned int srl(unsigned int x, int k)
{
    unsigned int xSra = (int) x >> k; // NOLINT(hicpp-signed-bitwise)
    unsigned int w = sizeof(x) * 8;

    return -(0x1u << (w - 1 - k)) & xSra;
}

unsigned int sra(int x, int k)
{
    unsigned int xSrl = (unsigned int) x >> k; // NOLINT(hicpp-signed-bitwise)
    unsigned int w = sizeof(x) * 8;

    return -((0x1u << (w - 1 - k)) & x) | xSrl; // NOLINT(hicpp-signed-bitwise)
}

void test63(int x, unsigned int u, int k)
{
    printf("x: 0x%x, >> %d = 0x%x\n", x, k, sra(x, k));
    printf("u: 0x%x, >>> %d = 0x%x\n", x, k, srl(u, k));
    printf("\n");
}

int anyOddOne(unsigned int x)
{
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCSimplifyInspection"
    return !!(x & 0xAAAAAAAAu);
#pragma clang diagnostic pop
}

void test64(unsigned int x)
{
    char const *prompt = anyOddOne(x) ? "yes" : "no";
    printf("0x%x %s!\n\n", x, prompt);
}

int oddOnes(unsigned int x)
{
    x ^= x >> 16u;
    x ^= x >> 8u;
    x ^= x >> 4u;
    x ^= x >> 2u;
    x ^= x >> 1u;
    x &= 1u;

    return (int) x;
}

void test65(unsigned int x)
{
    char const *prompt = oddOnes(x) ? "odd" : "even";
    printf("0x%x has %s ones.\n\n", x, prompt);
}

unsigned int leftmost_one(unsigned int x)
{
    x |= x >> 1u;
    x |= x >> 2u;
    x |= x >> 4u;
    x |= x >> 8u;
    x |= x >> 16u;

    return (x >> 1u) + (x & 1u);
}

void test66(unsigned int x)
{
    printf("0x%x --> 0x%x\n\n", x, leftmost_one(x));
}

int intSizeIs32()
{
    unsigned int setMsb = 1u << 15u << 15u << 1u;
    unsigned int beyondMsb = setMsb << 1u;

    return setMsb && !beyondMsb;
}

void test67()
{
    char const *prompt = intSizeIs32() ? "" : " not";
    printf("int size is%s 32.\n\n", prompt);
}

unsigned int lowerOneMask(unsigned int n)
{
    if (n < 1 || n > sizeof(unsigned int) << 3u)
    {
        return 0;
    }

    unsigned int offset = (sizeof(unsigned int) << 3u) - n;

    return -1u << offset >> offset;
}

void test68(unsigned int n)
{
    printf("n = %u, 0x%x.\n\n", n, lowerOneMask(n));
}

unsigned int rotateLeft(unsigned int x, unsigned int n)
{
    unsigned int w = sizeof(unsigned int) << 3u;

    return (x << n) | (x >> (w - n));
}

void test69(unsigned int x, unsigned int n)
{
    printf("x = 0x%x, n = %u --> 0x%x.\n\n", x, n, rotateLeft(x, n));
}

int fitsBit(int x, unsigned int n)
{
    unsigned int offset = (sizeof(x) << 3u) - n - 1;

    return !((x << offset >> offset) ^ x); // NOLINT(hicpp-signed-bitwise)
}

void test70(int x, unsigned int n)
{
    char const *prompt = fitsBit(x, n) ? "" : " not";
    printf("0x%x is%s fits %u-bit.\n\n", x, prompt, n);
}

int xByte(unsigned int word, unsigned int byteNum)
{
    return ((signed int) word << ((3 - byteNum) << 3)) >> 24u; // NOLINT(hicpp-signed-bitwise)
}

void test71(unsigned int word)
{
    printf("n = %u, 0x%x --> 0x%x.\n", 0, word, xByte(word, 0));
    printf("n = %u, 0x%x --> 0x%x.\n", 1, word, xByte(word, 1));
    printf("n = %u, 0x%x --> 0x%x.\n", 2, word, xByte(word, 2));
    printf("n = %u, 0x%x --> 0x%x.\n", 3, word, xByte(word, 3));
    printf("\n");
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
#pragma ide diagnostic ignored "bugprone-narrowing-conversions"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"

int saturatingAdd(int x, int y)
{
    unsigned int w = sizeof(int) << 3u;

    int diffSign = (x ^ y) >> (w - 1);
    int isOverflow = ((x + y) ^ x) >> (w - 1);
    int negSign = x >> (w - 1);
    int tMin = 1u << (w - 1);
    int tMax = tMin - 1;

    return (diffSign & (x + y)) +
        (~diffSign & ((isOverflow & ((negSign & tMin) + (~negSign & tMax))) + (~isOverflow & (x + y))));
}

#pragma clang diagnostic pop

void test73(int x, int y)
{
    printf("%d + %d = %d.\n\n", x, y, saturatingAdd(x, y));
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-narrowing-conversions"
#pragma ide diagnostic ignored "hicpp-signed-bitwise"

int tSubOk(int x, int y)
{
    unsigned int w = sizeof(int) << 3u;
    y = -y;

    int tMin = 1u << (w - 1);
    int notEqualTMin = tMin ^ y;

    int diffSign = (x ^ y) >> (w - 1);
    int isOverflow = ((x + y) ^ x) >> (w - 1);

    return notEqualTMin && (diffSign || ~isOverflow);
}

#pragma clang diagnostic pop

void test74(int x, int y)
{
    char const *prompt = tSubOk(x, y) ? "" : " not";
    printf("%d - %d is%s Ok.\n\n", x, y, prompt);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
#pragma ide diagnostic ignored "bugprone-narrowing-conversions"
int signedHighProd(int x, int y)
{
    return ((int64_t) x * y) >> 32;
}
#pragma clang diagnostic pop
