#include <stdio.h>

void reverse(int n);

int main(void)
{
    reverse(0);
    reverse(3124433);
    reverse(13579);
    reverse(-0);
    reverse(-13579);

    return 0;
}

void reverse(int n)
{
    if (n < 0)
    {
        n = -n;
        printf("-");
    }

    if (n == 0)
    {
        printf("\n");

        return;
    }
    else
    {
        int temp = n % 10;

        printf("%i", temp);
        reverse(n / 10);
    }
}
