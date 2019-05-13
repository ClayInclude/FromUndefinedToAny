/**
 * practice13
 * @author Clay
 * @version V 1.0.0
 */

#include <ctype.h>
#include <stdio.h>

void test(char *str);

int main(void)
{
    char text[120] = "asdsfaw###ERQS";
    test(text);
    test((char []){""});
    test((char []){"5fa3f3wearfr4tFEDFWA"});
}

void upperCase(char *str)
{
    static int const offset = 'A' - 'a';

    while (*str != '\0')
    {
        if (islower(*str))
        {
            *str += offset;
        }

        ++str;
    }
}

void test(char *str)
{
    printf("%s uppercase : ", str);
    upperCase(str);
    printf("%s\n", str);
}
