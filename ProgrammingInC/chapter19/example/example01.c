/**
 * example
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

typedef struct Fraction
{
    int numerator;
    int denominator;
} Fraction;

int main(void)
{
    Fraction f = {1, 3};

    printf("The fraction is %i/%i\n", f.numerator, f.denominator);

    return 0;
}
