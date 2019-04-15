#include <stdio.h>

long double squareRoot(long double n, long double epsilon);

int main(void)
{
    printf("%Lf\n", squareRoot(0.00000001, 0.00000000001));
    printf("%Lf\n", squareRoot(1.2644, 0.00000000001));
    printf("%Lf\n", squareRoot(0.09, 0.00000000001));
    printf("%Lf\n", squareRoot(2, 0.00000000001));
    printf("%Lf\n", squareRoot(4000000000.0, 0.00000000001));
    printf("%Lf\n", squareRoot(10000000000000000, 0.00000000001));

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

long double squareRoot(long double n, long double epsilon)
{
    double square = 1;

    if (n < 0)
    {
        printf("Negative argument to squareRoot\n");

        return -1;
    }

    while (absolute((square * square) / n - 1) > epsilon)
    {
        square = (square + n / square) / 2;
    }

    return square;
}
