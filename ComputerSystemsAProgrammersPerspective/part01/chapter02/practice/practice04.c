/**
 * practice04
 * @author Clay
 * @date 2020/3/14
 */

#include <stdio.h>

void test84(float x, float y);

int main(void)
{
    test84(1, 2);
    test84(3.111f, 3.1222f);
    test84(-1, -2);
    test84(0, 0);
    test84(1, -1);
    test84(-5, 8);
    test84(-0.0f, -8.0f);

    return 0;
}

typedef union
{
    float f;
    unsigned int u;
} FloatAndUnsigned;

unsigned int f2u(float f)
{
    FloatAndUnsigned fau = {f = f};

    return fau.u;
}

int floatLeq(float x, float y)
{
    unsigned int ux = f2u(x);
    unsigned int uy = f2u(y);
    unsigned int sx = ux >> 31u;
    unsigned int sy = uy >> 31u;

    return (~((ux << 1u) ^ 0u) && ~((uy << 1u) ^ 0u)) ||
        (sx && !sy) ||
        (!sx && !sy && ux <= uy) ||
        (sx && sy && ux >= uy);
}

void test84(float x, float y)
{
    char const *symbol = floatLeq(x, y) ? "<=" : ">";

    printf("%f %s %f.\n\n", x, symbol, y);
}
