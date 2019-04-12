#include <stdio.h>

int main(void)
{
    int fibo_1 = 0, fibo_2 = 1, current = 0;

    for (int i = 0; i < 20; ++i)
    {
        current = fibo_1 + fibo_2;
        printf("%i\n", current);

        fibo_1 = fibo_2;
        fibo_2 = current;
    }

    return 0;
}
