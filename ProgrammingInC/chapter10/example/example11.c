#include <stdio.h>

void strToInt(char const *str);

int main(void)
{
    strToInt("fdsae3f325r2345");
    strToInt("-324123");
    strToInt("3245-342523");

    return 0;
}

void strToInt(char const *str)
{
    if (*str == '-' || (*str >= '0' && *str <= '9'))
    {
        printf("%c", *str);
    }

    while (*++str != '\0')
    {
        if (*str >= '0' && *str <= '9')
        {
            printf("%c", *str);
        }
    }

    printf("\n");
}
