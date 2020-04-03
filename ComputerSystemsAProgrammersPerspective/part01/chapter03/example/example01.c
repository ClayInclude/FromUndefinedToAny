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
