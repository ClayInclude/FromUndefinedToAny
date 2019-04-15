#include <stdio.h>

double F2C(double f);

int main(void)
{
    printf("C = (F - 32) / 1.8 = (%f - 32) / 1.8 = %f\n", 27.0, F2C(27));

    return 0;
}

double F2C(double f)
{
    return (f - 32) / 1.8;
}
