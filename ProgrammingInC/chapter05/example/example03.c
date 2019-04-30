#include <stdio.h>

void print(int n, int max);

int main(void)
{
    print(100, 0);
    print(200, 10);

    return 0;
}

int getIndex(int n)
{
    if (n > 4)
    {
        return 3;
    }
    else if (n > 0)
    {
        return n - 1;
    }
    else
    {
        return -1;
    }
}

void print(int n, int max)
{
    char *rank[4] = {"st", "nd", "rd", "th"};
    int index = 0;
    int sum = 0;

    if (n > 0)
    {
        index = getIndex(n);
    }
    else
    {
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        sum += i;

        if (max >= i)
        {
            printf("The %i%s triangular number is %i\n", i, rank[getIndex(i)], sum);
        }
    }

    if (max == 0)
    {
        printf("The %i%s triangular number is %i\n", n, rank[index], sum);
    }
}
