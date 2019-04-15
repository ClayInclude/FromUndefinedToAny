#include <stdio.h>

unsigned long long int factorial(unsigned long long int n);

int main(void)
{
    for (unsigned long long int i = 0; i <= 20; ++i)
    {
        printf("%llu\n", factorial(i));
    }

    return 0;
}

unsigned long long int factorial(unsigned long long int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
