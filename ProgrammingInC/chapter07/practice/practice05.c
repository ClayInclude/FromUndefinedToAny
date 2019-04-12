#include <stdio.h>

int main(void)
{
    int numbers[10] = {1};

    for (int j = 0; j < 10; ++j)
    {
        for (int i = 0; i < j; ++i)
        {
            numbers[j] += numbers[i];
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        printf("%i ", numbers[i]);
    }

    printf("\n");

    return 0;
}
