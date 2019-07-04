/**
 * practice01
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

typedef int (*funcPtr)(void);

int test(void);

int main(void)
{
    funcPtr p = test;

    printf("%i\n", p());

    return 0;
}

int test(void)
{
    return 1;
}
