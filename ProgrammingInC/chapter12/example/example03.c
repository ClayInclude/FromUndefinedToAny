/**
 * example03
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

unsigned int shift(unsigned int value, int n);

int main(void)
{
    unsigned int w1 = 0177777u, w2 = 0444u;

    printf("%o\t%o\n", shift(w1, 5), w1 << (unsigned int) 5);
    printf("%o\t%o\n", shift(w1, -6), w1 >> 6u);
    printf("%o\t%o\n", shift(w2, 0), w2 >> 0u);
    printf("%o\n", shift(shift(w1, -3), 3));

    return 0;
}

unsigned int shift(unsigned int value, int n)
{
    if (n > 0)
    {
        return value << (unsigned int) n;
    }
    else
    {
        return value >> (unsigned int) (-n);
    }
}
