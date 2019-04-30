#include <stdio.h>

int main(void)
{
    int x = 0, y = 0;

    printf("Enter two numbers: \n");
    scanf("%i %i", &x, &y);

    if (y % x)
    {
        printf("%i can not divide %i.\n", x, y);
    }
    else
    {
        printf("%i can divide %i.\n", x, y);
    }

    return 0;
}
