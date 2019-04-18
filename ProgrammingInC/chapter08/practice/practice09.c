#include <stdio.h>

int lcm(int u, int v);

int main(void)
{
    printf("lcm(%i, %i) = %i\n", 3, 7, lcm(3, 7));
    printf("lcm(%i, %i) = %i\n", 1, 15, lcm(1, 15));
    printf("lcm(%i, %i) = %i\n", -3, -7, lcm(-3, -7));

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

int lcm(int u, int v)
{
    if (u < 0 || v < 0)
    {
        return 0;
    }

    return u * v / gcd(u, v);
}
