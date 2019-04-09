#include <stdio.h>

int main(void)
{
    int count = 0;

    while (count < 5)
    {
        printf("%d\n", ++count);
    }

    return 0;
}
