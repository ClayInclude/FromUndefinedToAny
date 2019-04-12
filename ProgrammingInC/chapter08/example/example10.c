#include <stdio.h>

int minimum(int *array, int n);

int main(void)
{
    int score[10] = {0, 0, -1, 9};
    int grade[35] = {2, 3, 32, 34, -43, -333, 44444};

    printf("Minimum score is %i\n", minimum(score, 10));
    printf("Minimum grade is %i\n", minimum(grade, 35));

    return 0;
}

int minimum(int *array, int n)
{
    int min = *array;
    for (int i = 1; i < n; ++i)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}
