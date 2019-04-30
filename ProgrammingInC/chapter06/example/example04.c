#include <stdbool.h>
#include <stdio.h>

bool isOdd(int n);

int main(void)
{
    char const *const desc[2] = {"even", "odd"};
    char const *currentDesc = NULL;
    int number = 0;

    printf("Enter your number to be tested:\n");
    scanf("%i", &number);

    if (isOdd(number))
    {
        currentDesc = desc[1];
    }
    else
    {
        currentDesc = desc[0];
    }

    printf("The number is %s.\n", currentDesc);

    return 0;
}

bool isOdd(int n)
{
    return n % 2;
}
