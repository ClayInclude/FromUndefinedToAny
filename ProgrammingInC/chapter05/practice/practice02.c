#include <stdio.h>

int main(void)
{
    printf("n         n^2\n");

    for (int i = 1; i <= 10; ++i)
    {
        printf("%-10i%-10i\n", i, i * i);
    }

    return 0;
}
