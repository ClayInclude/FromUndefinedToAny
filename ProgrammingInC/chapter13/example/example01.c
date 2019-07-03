/**
 * example01
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

#define YES 1
#define NO 0

int isEven(int num);

int main(void)
{
    printf("%s\n", isEven(17) == YES ? "yes" : "no");
    printf("%s\n", isEven(0) == YES ? "yes" : "no");
}

int isEven(int num)
{
    return num % 2 == 0 ? YES : NO;
}
