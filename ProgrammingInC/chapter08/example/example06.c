#include <stdio.h>

int gcd(int u, int v);

int main(void)
{
    printf("%i and %i gcd is %i\n", 15, 35, gcd(15, 35));
    printf("%i and %i gcd is %i\n", 150, 35, gcd(150, 35));
    printf("%i and %i gcd is %i\n", 35, 150, gcd(35, 150));
    printf("%i and %i gcd is %i\n", 1026, 405, gcd(1026, 405));

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;

    *x = *y;
    *y = temp;
}

int gcd(int u, int v)
{
    if (u < v)
    {
        swap(&u, &v);
    }

    if (v == 0)
    {
        return u;
    }
    else
    {
        return gcd(v, u % v);
    }
}
