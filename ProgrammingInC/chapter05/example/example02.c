#include <stdio.h>

void print(int n);

int main(void)
{
    print(1);
    print(2);
    print(3);
    print(4);
    print(5);
    print(200);

    return 0;
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
