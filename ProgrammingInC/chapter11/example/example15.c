/**
 * example15
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

int stringLength(char const *str);

int main(void)
{
    printf("%i ", stringLength("stringLength test"));
    printf("%i ", stringLength(""));
    printf("%i\n", stringLength("complete"));

    return 0;
}

int stringLength(char const *const str)
{
    char const *end = str;

    while (*end) ++end;

    return end - str;
}
