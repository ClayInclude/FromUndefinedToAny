#include <stdint.h>

/**
 * example01
 * @author Clay
 * @date 2020/4/1
 */

int main(void)
{
    return 0;
}

void decode1(long int *xp, long int *yp, long int *zp)
{
    long int x = *xp;
    long int y = *yp;
    long int z = *zp;

    *yp = x;
    *zp = y;
    *xp = z;
}

void test1(void)
{
    long int xp = 1;
    long int yp = 2;
    long int zp = 3;

    decode1(&xp, &yp, &zp);
}

int64_t scale(int64_t x, int64_t y, int64_t z)
{
    return x + 4 * y + 12 * z;
}

long int arith(long int x, long int y, long int z)
{
    long int t1 = x ^y; // NOLINT(hicpp-signed-bitwise)
    long int t2 = z * 48;
    long int t3 = t1 & 0x0f0f0f0f; // NOLINT(hicpp-signed-bitwise)
    long int t4 = t2 - t3;

    return t4;
}

long int arith2(long int x, long int y, long int z)
{
    long int t1 = x | y; // NOLINT(hicpp-signed-bitwise)
    long int t2 = t1 >> 3; // NOLINT(hicpp-signed-bitwise)
    long int t3 = ~t2; // NOLINT(hicpp-signed-bitwise)
    long int t4 = z - t3;

    return t4;
}

void switcher(int64_t a, int64_t b, int64_t c, int64_t *dest)
{
    int64_t val;

    switch (a)
    {
    case 5:
        c = b ^ 15; // NOLINT(hicpp-signed-bitwise)
    case 0:
        val = c + 112;
        break;
    case 2:
    case 7:
        val = (c + b) << 2; // NOLINT(hicpp-signed-bitwise)
        break;
    case 4:
        val = a;
        break;
    default:
        val = b;
        break;
    }

    *dest = val;
}

typedef enum
{
    NEG,
    ZERO,
    POS,
    OTHER
} rangeT;

rangeT findRange(float x)
{
    int result;

    if (x < 0)
    {
        result = NEG;
    }
    else if (x == 0)
    {
        result = ZERO;
    }
    else if (x > 0)
    {
        result = POS;
    }
    else
    {
        result = OTHER;
    }

    return result;
}
