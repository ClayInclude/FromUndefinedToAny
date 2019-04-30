#include <stdbool.h>
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

void _reverse(int n)
{
    int temp = n % 10;

    printf("%i", temp);

    n /= 10;

    if (n == 0)
    {
        return;
    }
    else
    {
        _reverse(n);
    }
}

void reverse(int n)
{
    bool flag = false;

    if (n < 0)
    {
        n = -n;
        flag = true;
    }

    _reverse(n);

    if (flag)
    {
        printf("-");
    }

    printf("\n");
}
