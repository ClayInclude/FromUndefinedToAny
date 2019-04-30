#include <stdio.h>

int minimum(int const *array);

int main(void)
{
    int score[10] = {0};

    printf("Enter 10 scores\n");

    for (int i = 0; i < 10; ++i)
    {
        scanf("%i", &score[i]);
    }

    printf("Minimum score is %i\n", minimum(score));

    return 0;
}

int minimum(int const *array)
{
    int min = *array;
    for (int i = 1; i < 10; ++i)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}
