#include <math.h>
#include <stdarg.h>
#include <stdio.h>

double polynomial(double x, int max, ...);

int main(void)
{
    double result = polynomial(2.55, 3, 3.0, -5.0, 0.0, 6.0);

    printf("3x^3 - 5x^2 + 6 = %f\n", result);

    return 0;
}

double power(double x, int y)
{
    if (y < 0)
    {
        return 0;
    }
    else if (y == 0)
    {
        return 1;
    }
    else if (y == 1)
    {
        return x;
    }
    else
    {
        return x * power(x, y - 1);
    }
}

/**
 * x, max, a_max, a_max - 1 ... a_1, a_0
 * @param x
 * @param max
 * @param args args.length == max - 1
 */
double polynomial(double x, int max, ...)
{
    double sum = 0;

    va_list args = NULL;
    va_start(args, max);

    for (int i = 0; i <= max; ++i)
    {
        double a = va_arg(args, double);
        sum += a * power(x, max - i);
    }

    va_end(args);

    return sum;
}
