/**
 * example02
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

int main(void)
{
    int c = 0;

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }

    return 0;
}
