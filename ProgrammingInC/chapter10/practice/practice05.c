#include <stdio.h>
#include <stdbool.h>

int findString(char const *str, char const *find);

int main(void)
{
    printf("%s.subString(%s) = %i\n", "subString", "sub", findString("subString", "sub"));
    printf("%s.subString(%s) = %i\n", "123", "3", findString("123", "3"));
    printf("%s.subString(%s) = %i\n", "1234", "345", findString("1234", "345"));
    printf("%s.subString(%s) = %i\n", "ab", "ab", findString("ab", "ab"));
    printf("%s.subString(%s) = %i\n", "34", "ab", findString("34", "ab"));
    return 0;
}

int findString(char const *str, char const *find)
{
    char const *temp = str;
    bool flag = false;

    while (*temp != '\0')
    {
        if (*temp == *find)
        {
            flag = true;
            int i = 0;

            while (++i)
            {
                if (*(temp + i) != *(find + i))
                {
                    if (*(find + i) == '\0') break;

                    flag = false;
                    break;
                }
                else if (*(temp + i) == '\0' && *(find + i) == '\0')
                {
                    break;
                }
            }
        }

        if (flag)
        {
            return temp - str;
        }

        ++temp;
    }

    return -1;
}
