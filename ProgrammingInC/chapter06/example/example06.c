#include <stdbool.h>
#include <stdio.h>

int getSign(int n);

int main(void)
{
    int number = 0;

    printf("Please type in a number:\n");
    scanf("%i", &number);

    printf("Sign = %i\n", getSign(number));

    return 0;
}

int getSign(int n)
{
    if (n > 0)
    {
        return 1;
    }
    else if (n == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
