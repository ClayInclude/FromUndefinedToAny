#include <stdbool.h>
#include <stdio.h>

bool equalStrings(char const *str1, char const *str2);

int main(void)
{
    char str1[20] = "hahahaha   ha";
    char str2[15] = "hahaha";
    char str3[15] = "hahaha";

    printf("%s equal %s = %i\n", str1, str2, equalStrings(str1, str2));
    printf("%s equal %s = %i\n", str2, str3, equalStrings(str2, str3));
    printf("%s equal %s = %i\n", str1, str3, equalStrings(str1, str3));

    return 0;
}

bool equalStrings(char const *str1, char const *str2)
{
    bool flag = true;
    int index = 0;

    while (true)
    {
        if (str1[index] == str2[index])
        {
            if (str1[index] == '\0')
            {
                break;
            }
        }
        else
        {
            flag = false;
        }

        ++index;
    }

    return flag;
}
