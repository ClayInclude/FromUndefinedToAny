#include <stdio.h>

int main(void)
{
    int numbers[1024] = {0};

    for (int i = 2; i < 1024; ++i)
    {
        if (numbers[i] == 0)
        {
            printf("%i\n", i);

            for (int j = 2; j * i < 1024; ++j)
            {
                numbers[j * i] = 1;
            }
        }
    }

    return 0;
}
