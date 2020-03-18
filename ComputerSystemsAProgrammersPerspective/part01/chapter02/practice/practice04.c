/**
 * practice04
 * @author Clay
 * @date 2020/3/14
 */

#include <stdio.h>
#include <math.h>

void test84(float x, float y);

void test90(int x);

void test92(float f);

void test93(float f);

void test94(float f);

void test95(float f);

void test96(float f);

void test97(int x);

int main(void)
{
    test84(1, 2);
    test84(3.111f, 3.1222f);
    test84(-1, -2);
    test84(0, 0);
    test84(1, -1);
    test84(-5, 8);
    test84(-0.0f, -8.0f);

    test90(-150);
    test90(-149);
    test90(-127);
    test90(-126);
    test90(-105);
    test90(-10);
    test90(-1);
    test90(-0);
    test90(1);
    test90(3);
    test90(100);
    test90(127);
    test90(128);

    printf("practice 92: -f\n");
    test92(0.0f);
    test92(-1.0f);
    test92(1.0f);
    test92(1111111.0f);
    test92(14123.0f);
    test92(-1723.423f);
    test92(2147483647.0f);
    test92(-2147483648.0f);
    test92(-217483647.0f);
    test92(0.5f);
    test92(1.1111f);
    test92(-0.0f);
    printf("\n");

    printf("practice 93: |f|\n");
    test93(0.0f);
    test93(-1.0f);
    test93(1.0f);
    test93(1111111.0f);
    test93(14123.0f);
    test93(-1723.423f);
    test93(2147483647.0f);
    test93(-2147483648.0f);
    test93(-217483647.0f);
    test93(0.5f);
    test93(1.1111f);
    test93(-0.0f);
    printf("\n");

    printf("practice 94: 2 * f\n");
    test94(0.0f);
    test94(-1.0f);
    test94(1.0f);
    test94(1111111.0f);
    test94(14123.0f);
    test94(-1723.423f);
    test94(2147483647.0f);
    test94(-2147483648.0f);
    test94(-217483647.0f);
    test94(0.5f);
    test94(1.1111f);
    test94(-0.0f);
    printf("\n");

    printf("practice 95: 0.5 * f\n");
    test95(0.0f);
    test95(-1.0f);
    test95(1.0f);
    test95(1111111.0f);
    test95(14123.0f);
    test95(-1723.423f);
    test95(2147483647.0f);
    test95(-2147483648.0f);
    test95(-217483647.0f);
    test95(0.5f);
    test95(1.1111f);
    test95(-0.0f);
    printf("\n");

    printf("practice 96 f2i:\n");
    test96(0.0f);
    test96(-1.0f);
    test96(1.0f);
    test96(1111111.0f);
    test96(14123.0f);
    test96(-1723.423f);
    test96(2147483647.0f);
    test96(-2147483648.0f);
    test96(-217483647.0f);
    test96(0.5f);
    test96(-0.5f);
    test96(1.1111f);
    test96(-0.0f);
    printf("\n");

    printf("practice 97 i2f:\n");
    test97(0);
    test97(1);
    test97(-1);
    test97(-0);
    test97(111);
    test97(-111);
    test97(421345);
    test97(2147483647);
    test97(2147483600);
    test97(-2147483647);
    test97(2100000000);
    test97(20000000);
    test97(10000000);
    test97(-2147483648);
    test97(-3213);
    test97(3213);
    printf("\n");

    return 0;
}

unsigned int f2u(float f)
{
    return *(unsigned *) &f;
}

float u2f(unsigned int u)
{
    return *(float *) &u;
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

float fPwr2(int x)
{
    unsigned int exp, frac;

    if (x < -149)
    {
        exp = 0;
        frac = 0;
    }
    else if (x < -126)
    {
        exp = 0;
        frac = 1u << (unsigned int) (-126 - x);
    }
    else if (x < 128)
    {
        exp = x + 127;
        frac = 0;
    }
    else
    {
        exp = 255;
        frac = 0;
    }

    return u2f((exp << 23u) | frac);
}

void test90(int x)
{
    printf("2^%d = %f.\n\n", x, fPwr2(x));
}

typedef unsigned int floatBits;

int power(int x, int y)
{
    int result = 1;

    if (y == 0)
    {
        return result;
    }
    else if (y > 0)
    {
        for (int i = y; i; --i)
        {
            result *= x;
        }
    }
    else
    {
        for (int i = y; i; ++i)
        {
            result /= x;
        }
    }

    return result;
}

#define B 32u
#define S 1u
#define E 8u
#define F 23u
#define BIAS (power(2, (E - 1)) - 1)
#define MAX_EXP (power(2, (E)) - 1)
#define INT_MIN -2147483647 - 1

#define SIGN(f) ((f) >> ((B) - (S)))
#define EXP(f) ((f) << (S) >> ((S) + (F)))
#define FRAC(f) ((f) << ((S) + (E)) >> ((S) + (E)))
#define FLOAT(s, e, f) ((unsigned int) (((s) << ((B) - (S))) | ((e) << (F)) | (f)))

floatBits floatNegate(floatBits f)
{
    floatBits sign = SIGN(f);
    floatBits exp = EXP(f);
    floatBits frac = FRAC(f);

    if (exp == MAX_EXP && frac != 0)
    {
        return f;
    }
    else
    {
        return FLOAT((unsigned int)!sign, exp, frac);
    }
}

void test92(float f)
{
    printf("%f = %f\n", -f, u2f(floatNegate(f2u(f))));
}

floatBits floatAbsVal(floatBits f)
{
    floatBits exp = EXP(f);
    floatBits frac = FRAC(f);

    if (exp == MAX_EXP && frac != 0)
    {
        return f;
    }
    else
    {
        return FLOAT(0u, exp, frac);
    }
}

void test93(float f)
{
    printf("%f = %f\n", fabsf(f), u2f(floatAbsVal(f2u(f))));
}

floatBits floatTwice(floatBits f)
{
    floatBits sign = SIGN(f);
    floatBits exp = EXP(f);
    floatBits frac = FRAC(f);

    if (exp == MAX_EXP && frac != 0)
    {
        return f;
    }
    else
    {
        if (exp < MAX_EXP - 1)
        {
            return FLOAT(sign, (exp + 1), frac);
        }
        else
        {
            return FLOAT(sign, exp + 1, 0u);
        }
    }
}

void test94(float f)
{
    printf("%f = %f\n", 2 * f, u2f(floatTwice(f2u(f))));
}

floatBits floatHalf(floatBits f)
{
    floatBits sign = SIGN(f);
    floatBits exp = EXP(f);
    floatBits frac = FRAC(f);

    if (exp == MAX_EXP && frac != 0)
    {
        return f;
    }
    else
    {
        if (exp > 1)
        {
            return FLOAT(sign, exp - 1, frac);
        }
        else if (exp == 0)
        {
            return FLOAT(sign, exp, frac >> 1u);
        }
        else
        {
            return FLOAT(sign, 0u, (1u << F | frac) >> 1u);
        }
    }
}

void test95(float f)
{
    printf("%f = %f\n", 0.5 * f, u2f(floatHalf(f2u(f))));
}

int float2int(floatBits f)
{
    floatBits sign = SIGN(f);
    floatBits exp = EXP(f);
    floatBits frac = FRAC(f);

    if (exp == MAX_EXP)
    {
        if (frac != 0)
        {
            return sign ? 0x80000000 : // NOLINT(bugprone-narrowing-conversions,cppcoreguidelines-narrowing-conversions)
                   0x7fffffff;
        }
        else
        {
            return 0x80000000; // NOLINT(bugprone-narrowing-conversions,cppcoreguidelines-narrowing-conversions)
        }
    }
    else
    {
        int e;

        if (exp == 0)
        {
            return 0;
        }
        else
        {
            e = (int) exp - BIAS;
        }

        if (e < 0)
        {
            return sign ? -0 : 0;
        }
        else if (e < F)
        {
            return (int) (((1u << F) | frac) << (B - F - 1u) >> (B - 1 - e));
        }
        else if (e < B - 1)
        {
            return ((1u << F) | frac) // NOLINT(bugprone-narrowing-conversions,cppcoreguidelines-narrowing-conversions)
                << (unsigned int) (e - F);
        }
        else
        {
            return 0x80000000; // NOLINT(bugprone-narrowing-conversions,cppcoreguidelines-narrowing-conversions)
        }
    }
}

void test96(float f)
{
    printf("%f = %d\n", f, float2int(f2u(f)));
}

floatBits int2float(int x)
{
    floatBits sign = 0;
    floatBits exp = 0;
    floatBits frac = 0;
    floatBits toEven = 0;

    if (!x)
    {
        return 0;
    }
    else if (x == INT_MIN)
    {
        return FLOAT(1u, ((B - S) + BIAS), 0u);
    }

    if (x < 0)
    {
        x = -x;

        sign = 1;
    }
    else
    {
        sign = 0;
    }

    unsigned int i = 1;

    for (; i < B - 1; ++i)
    {
        if (!((unsigned int) x >> i))
        {
            break;
        }
    }

    floatBits e = i - 1;
    exp = e + BIAS;

    if (e > F)
    {
        unsigned int offset = e - F;
        unsigned int roundMid = 1u << (offset - 1);
        unsigned int rest = x & (~0u >> (B - offset)); // NOLINT(hicpp-signed-bitwise)

        frac = (unsigned int) x >> offset;
        frac = frac & (~0u >> (B - F));

        if (rest > roundMid || ((rest == roundMid) && (frac & 0x1u)))
        {
            toEven = 1;
        }
    }
    else
    {
        frac = (x & (~0u >> (B - e))) << (F - e); // NOLINT(frac hicpp-signed-bitwise,hicpp-signed-bitwise)
    }

    if (toEven)
    {
        if (frac == (~0u >> (B - F)))
        {
            frac = 0;
            exp += 1;
        }
        else
        {
            frac += 1;
        }
    }

    return FLOAT(sign, exp, frac);
}

void test97(int x)
{
    printf("%f = %f\n", (float) x, u2f(int2float(x)));
}
