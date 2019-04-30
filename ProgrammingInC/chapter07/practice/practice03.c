#include <stdio.h>

int main(void)
{
    int ratingCounters[11] = {0}, response = 0;

    printf("Enter your responses: (enter 999 to exit)\n");

    while (scanf("%i", &response) && response != 999)
    {
        if (response < 1 || response > 10)
        {
            printf("Bad response: %i\n", response);
        }
        else
        {
            ++ratingCounters[response - 1];
        }
    }

    printf("\nRating Number of Resposed\n");
    printf("-------------------------\n");

    for (int i = 0; i < 10; ++i)
    {
        printf("%4i%14i\n", i + 1, ratingCounters[i]);
    }

    return 0;
}
