#include <stdio.h>

int cache[16] = {0};

int fibonacci(int n);

int main(void)
{
    printf("%i\n", fibonacci(15));

    return 0;
}

int fibonacci(int n)
{
    if (n < 0)
    {
        printf("Error!\n");

        return -1;
    }
    else if (n == 0)
    {
        return n;
    }
    else if (n == 1)
    {
        if (cache[n] == 0)
        {
            cache[n] = n;
        }

        return n;
    }
    else
    {
        if (cache[n])
        {
            return cache[n];
        }

        return cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
}
