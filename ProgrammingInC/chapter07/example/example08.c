#include <stdio.h>

int fibonacci(int n, int *cache);

int main(void)
{
    int numFibs = 0;

    printf("How many Fibonacci numbers do you want?\n");
    scanf("%i", &numFibs);

    int cache[numFibs + 1];

    for (int i = 0; i <= numFibs; ++i)
    {
        cache[i] = 0;
    }

    printf("%i\n", fibonacci(numFibs, cache));

    return 0;
}

int fibonacci(int n, int *cache)
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

        return cache[n] = fibonacci(n - 1, cache) + fibonacci(n - 2, cache);
    }
}
