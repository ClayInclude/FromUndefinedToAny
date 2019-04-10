#include <stdbool.h>
#include <stdio.h>

bool isOdd(int n);

int main(void)
{
    char const *desc[2] = {"even", "odd"};
    int number = 0;

    printf("Enter your number to be tested:\n");
    scanf_s("%i", &number);

    printf("The number is %s.\n", desc[isOdd(number)]);

    return 0;
}

bool isOdd(int n)
{
    return n % 2;
}
