#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool isPrime(int n);

int main(void)
{
    printf("2 ");

    for (int p = 3; p <= 50; p += 2)
    {
        if (isPrime(p))
        {
            printf("%i ", p);
        }
    }

    printf("\n");

    return 0;
}

bool isPrime(int n)
{
    int limit = sqrt(n);

    for (int i = 3; i <= limit; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}
