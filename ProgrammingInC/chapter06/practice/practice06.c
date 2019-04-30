#include <stdio.h>

void translate(char const *number);

int main(void)
{
    char number[12] = {0};

    scanf("%11s", number);
    printf("%zu", sizeof("number"));

    translate(number);

    return 0;
}

void translate(char const *number)
{
    char const *const en[10] =
        {
            "zero",
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine"
        };

    char const *p = number;

    while (*p != '\0')
    {
        printf("%s ", en[*p++ - 48]);
    }

    printf("\n");
}
