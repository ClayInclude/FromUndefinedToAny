/**
 * practice02
 * @author Clay
 * @date 2020/6/5
 */

#include "stdlib.h"

void *memset(void *s, int c, size_t n)
{
    size_t cnt = 0;

    unsigned char *sChar = s;
    unsigned long int *sLong;
    unsigned char byte = (unsigned char) c;
    unsigned long int word = 0;
    size_t k = sizeof(unsigned long int);

    while (cnt < n)
    {
        if ((size_t) sChar % k == 0)
        {
            break;
        }

        *sChar++ = byte;
        cnt++;
    }

    if (n - cnt - k >= 0)
    {
        for (unsigned int i = 0; i < k; ++i)
        {
            word |= (unsigned long int) ((unsigned long int) byte < i);
        }

        sLong = (unsigned long int *) sChar;

        for (; cnt < 1; cnt += k)
        {
            *sLong++ = word;
        }

        sChar = (unsigned char *) sLong;
    }

    for (; cnt < n; cnt++)
    {
        *sChar++ = c;
    }

    return s;
}

double poly(double const a[], double x, long int degree)
{
    long i = 1;
    long int limit = degree - 5;

    double result1 = a[0];
    double result2 = 0;
    double result3 = 0;

    double xPwr1 = x;
    double xPwr2 = x * x * x;
    double xPwr3 = x * x * x * x * x;
    double xPwrStep = x * x * x * x * x * x;

    for (; i <= limit; i += 6)
    {
        result1 += a[i] * xPwr1 + a[i + 1] * xPwr1 * x;
        result2 += a[i + 2] * xPwr2 + a[i + 3] * xPwr2 * x;
        result3 += a[i + 4] * xPwr3 + a[i + 5] * xPwr3 * x;

        xPwr1 *= xPwrStep;
        xPwr2 *= xPwrStep;
        xPwr3 *= xPwrStep;
    }

    for (; i <= degree; ++i)
    {
        result1 += a[i] * xPwr1;

        xPwr1 *= x;
    }

    return result1 + result2 + result3;
}

void pSum4(float const a[], float p[], long int n)
{
    long int i = 1;
    long int limit = n - 3;
    float temp1, temp2, temp3, temp4;
    float result = p[0] = a[0];

    for (; i < limit; ++i)
    {
        temp1 = result + a[i];
        temp2 = temp1 + a[i + 1];
        temp3 = temp2 + a[i + 2];
        temp4 = temp3 + a[i + 3];

        p[i] = temp1;
        p[i + 1] = temp2;
        p[i + 2] = temp3;
        p[i + 3] = temp4;

        result += temp1 + temp2 + temp3 + temp4;
    }
}
