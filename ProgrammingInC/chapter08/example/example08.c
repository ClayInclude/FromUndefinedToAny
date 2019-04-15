#include <stdio.h>

double squareRoot(double n);

int main(void)
{
    printf("%lf\n", squareRoot(0));
    printf("%lf\n", squareRoot(1));
    printf("%lf\n", squareRoot(0.09));
    printf("%lf\n", squareRoot(2));
    printf("%lf\n", squareRoot(4));
    printf("%lf\n", squareRoot(100));

    return 0;
}

double absolute(double n)
{
    if (n < 0)
    {
        return -n;
    }

    return n;
}

#define EPSILON 0.000000000000001

double squareRoot(double n)
{
    double square = 1;

    if (n < 0)
    {
        printf("Negative argument to squareRoot\n");

        return -1;
    }

    while (absolute(square * square - n) > EPSILON)
    {
        square = (square + n / square) / 2;
    }

    return square;
}
