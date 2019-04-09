#include <stdio.h>

int factorial(int n);

int main(void)
{
    printf("n         n!\n");

    for (int i = 1; i <= 10; ++i)
    {
        printf("%-10i%-10i\n", i, factorial(i));
    }
}

int factorial(int n)
{
    if (n < 0)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
