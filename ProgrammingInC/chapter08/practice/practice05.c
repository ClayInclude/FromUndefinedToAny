#include <stdio.h>

double squareRoot(double n, double epsilon);

int main(void)
{
    printf("%lf\n", squareRoot(0.0001, 0.000000001));
    printf("%lf\n", squareRoot(1.2644, 0.000000001));
    printf("%lf\n", squareRoot(0.09, 0.000000001));
    printf("%lf\n", squareRoot(2, 0.000000001));
    printf("%lf\n", squareRoot(4000000000, 0.000000001));
    printf("%lf\n", squareRoot(100000000, 0.000000001));

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

double squareRoot(double n, double epsilon)
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
