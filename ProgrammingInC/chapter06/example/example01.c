#include <stdio.h>

int abs(int n);

int main(void)
{
    int number = 0;

    printf("Type in your number: ");
    scanf("%i", &number);

    printf("The absolute value is %i\n", abs(number));

    return 0;
}

int abs(int n)
{
    if (n < 0)
    {
        return -n;
    }

    return n;
}
