#include <stdio.h>

int scanInt(int *n);
void print(int n);

int main(void)
{
    int n = 0;

    for (int i = 0; i < 5; ++i)
    {
        print(scanInt(&n));
    }
    return 0;
}

int scanInt(int *n)
{
    scanf("%d", n);

    return *n;
}

void print(int n)
{
    char *rank[4] = {"st", "nd", "rd", "th"};
    int index = 0;
    int sum = 0;

    if (n > 4)
    {
        index = 3;
    }
    else if (n > 0)
    {
        index = n - 1;
    }
    else
    {
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        sum += i;
    }

    printf("The %i%s triangular number is %i\n", n, rank[index], sum);
}
