/**
 * practice11
 * @author Clay
 * @version V 1.0.0
 */

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

void testStrToInt(char const *str);

int main(void)
{
    testStrToInt("2345fseea");
    testStrToInt("0");
    testStrToInt("");
    testStrToInt("-0");
    testStrToInt("-323d3");

    return 0;
}

int strToInt(char const *str)
{
    int flag = 1;
    int sum = 0;

    if (*str == '\0') return 0;

    if (*str == '-')
    {
        flag = -1;
        ++str;
    }

    while (*str != '\0')
    {
        if (isdigit(*str))
        {
            sum = sum * 10 + *str - '0';
        }
        else
        {
            break;
        }

        ++str;
    }

    return sum * flag;
}

void testStrToInt(char const *str)
{
    printf("%s to int is :%i\n", str, strToInt(str));
}
