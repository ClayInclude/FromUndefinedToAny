/**
 * practice14
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

void intToStr(int n);

int main(void)
{
    intToStr(234);
    intToStr(0);
    intToStr(-324);
}

void intToStr(int n)
{
    printf("%i to string: ", n);

    int index = 0;
    char str[20] = "";

    if (n == 0)
    {
        printf("0\n");

        return;
    }
    else if (n < 0)
    {
        printf("-");
        n = -n;
    }

    while (n != 0)
    {
        str[index++] = n % 10 + '0';
        n /= 10;
    }

    for (index--; index >= 0; --index)
    {
        printf("%c", str[index]);
    }

    printf("\n");
}
