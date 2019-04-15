#include <stdio.h>

int triangularNumber(int n);

int main(void)
{
    printf("n         number\n");

    for (int i = 5; i <= 50; i += 5)
    {
        triangularNumber(i);
    }

    return 0;
}

int triangularNumber(int n)
{
    int result = 0;

    if (n <= 0)
    {
        result = 0;
    }
    else
    {
        result = n * (n + 1) / 2;
    }

    printf("%-10i%-10i\n", n, result);

    return result;
}
