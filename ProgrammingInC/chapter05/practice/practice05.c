#include <stdio.h>

int main(void)
{
    int doubleN = 1;

    printf("Table of Powers of Two\n");
    printf("n * 2 to the n\n");
    printf("-------------------\n");

    for (int n = 0; n <= 10; ++n)
    {
        printf("%-10i%-10i\n", n, doubleN);
        doubleN *= 2;
    }

    return 0;
}
