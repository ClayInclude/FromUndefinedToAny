#include <stdio.h>

int main(void)
{
    double x = 0, y = 0;

    printf("Enter two numbers: \n");
    scanf("%lf %lf", &x, &y);

    if (y)
    {
        printf("%f / %f = %.2f\n", x, y, x / y);
    }
    else
    {
        printf("Division by ZERO!.\n");

        return 1;
    }

    return 0;
}
