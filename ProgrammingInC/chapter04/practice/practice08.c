#include <stdio.h>

void nextMultiple(int i, int j);

int main(void)
{
    printf("         i         j     result\n");
    nextMultiple(365, 7);
    nextMultiple(12258, 23);
    nextMultiple(996, 4);

    return 0;
}

void nextMultiple(int i, int j)
{
    printf("%10d%10d     %-10d\n", i, j, i + j - i % j);
}
