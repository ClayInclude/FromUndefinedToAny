#include <stdio.h>

int getTotal(int n);

int main(void)
{
    printf("value     total\n");
    printf("%-10i%-10i\n", 2155, getTotal(2155));
    printf("%-10i%-10i\n", 0, getTotal(0));
    printf("%-10i%-10i\n", 7, getTotal(7));
    printf("%-10i%-10i\n", 15, getTotal(15));
    printf("%-10i%-10i\n", -15, getTotal(-15));
}

int getTotal(int n)
{
    if (n < 0)
    {
        n = -n;
    }

    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n % 10 + getTotal(n / 10);
    }
}
