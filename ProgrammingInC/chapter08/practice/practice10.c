#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool prime(int n);

int main(void)
{
    printf("prime(%i) = %i\n", 100, prime(100));
    printf("prime(%i) = %i\n", 37, prime(37));

    return 0;
}

bool prime(int n)
{
    int limit = (int) sqrt(n);

    for (int i = 3; i <= limit; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}
