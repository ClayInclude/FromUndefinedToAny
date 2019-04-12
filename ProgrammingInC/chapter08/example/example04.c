#include <stdio.h>

void calculateTriangularNumber(int n);

int main(void)
{
    calculateTriangularNumber(10);
    calculateTriangularNumber(20);
    calculateTriangularNumber(50);

    return 0;
}

void calculateTriangularNumber(int n)
{
    int triangularNumber = 0;

    for (int i = 1; i <= n; ++i)
    {
        triangularNumber += i;
    }

    printf("Triangular number %i is %i\n", n, triangularNumber);

    return;
}
