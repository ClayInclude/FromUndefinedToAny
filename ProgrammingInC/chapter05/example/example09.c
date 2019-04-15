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
    int temp = 0;

    if (n < 0)
    {
        n = -n;
        printf("-");
    }

    temp = n % 10;
    printf("%i", temp);

    n /= 10;

    if (n == 0)
    {
        printf("\n");

        return;
    }
    else
    {
        reverse(n);
    }
}
