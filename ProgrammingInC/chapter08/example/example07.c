#include <stdio.h>

double absolute(double n);

int main(void)
{
    double number = 0;

    printf("Type in your number: ");
    scanf("%lf", &number);

    printf("The absolute value is %lf\n", absolute(number));

    return 0;
}

double absolute(double n)
{
    if (n < 0)
    {
        return -n;
    }

    return n;
}
