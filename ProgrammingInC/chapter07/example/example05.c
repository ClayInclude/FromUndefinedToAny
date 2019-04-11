#include <stdio.h>

int main(void)
{
    int array[10] = {0, 1, 4, 9, 16};

    for (int i = 5; i < 10; ++i)
    {
        array[i] = i * i;
    }

    for (int i = 0; i < 10; ++i)
    {
        printf("array[%i] = %i\n", i, array[i]);
    }

    return 0;
}
