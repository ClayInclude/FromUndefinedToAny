/**
 * practice12
 * @author Clay
 * @version V 1.0.0
 */

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

double testStrToFloat(char const *str);

int main(void)
{
    testStrToFloat("23.45fseea");
    testStrToFloat("0.");
    testStrToFloat("");
    testStrToFloat("-.0");
    testStrToFloat("-.323d3");

    return 0;
}

double strToFloat(char const *str)
{
    int flag = 1;
    int sum = 0;
    double realPart = 0;
    bool hasReal = false;

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
        else if (*str++ == '.')
        {
            hasReal = true;
            break;
        }
        else
        {
            break;
        }

        ++str;
    }

    if (hasReal)
    {
        int index = 1;
        while (*str != '\0')
        {
            if (isdigit(*str))
            {
                realPart += (*str - '0') / pow(10, index);
                ++str, ++index;
            }
            else
            {
                break;
            }
        }
    }

    return (sum + realPart) * flag;
}

double testStrToFloat(char const *str)
{
    printf("%s to int is :%lf\n", str, strToFloat(str));
}
