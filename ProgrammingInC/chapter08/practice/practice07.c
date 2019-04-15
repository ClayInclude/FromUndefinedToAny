#include <stdio.h>

unsigned long long xToTheN(unsigned long long x, unsigned long long n);

int main(void)
{
    printf("%i^%i = %llu\n", 111, 3, xToTheN(111, 3));

    return 0;
}

unsigned long long xToTheN(unsigned long long x, unsigned long long n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return x * xToTheN(x, n - 1);
    }
}
