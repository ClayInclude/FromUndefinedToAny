#include <stdio.h>

int scanInt(int *n);
void print(int n);

int main(void)
{
    int n = 0, count = 0;

    printf("Enter The Counts: ");
    scanInt(&count);

    for (int i = 0; i < count; ++i)
    {
        print(scanInt(&n));
    }
}

int scanInt(int *n)
{
    scanf_s("%d", n);

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

    return;
}
