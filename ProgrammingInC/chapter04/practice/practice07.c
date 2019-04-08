#include <stdio.h>

int main(void)
{
    double x = 3.31 * 10 - 8 * 2.01 * 10 - 7;
    double y = 7.16 * 10 - 6 + 2.01 * 10 - 8;
    double result = x / y;

    printf("(3.31 * 10 - 8 * 2.01 * 10 - 7) / (7.16 * 10 - 6 + 2.01 * 10 - 8) = %e", result);

    return 0;
}
