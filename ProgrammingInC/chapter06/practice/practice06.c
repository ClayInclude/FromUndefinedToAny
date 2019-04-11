#include <stdio.h>

void translate(char const *number);

int main(void)
{
    char const number[12] = {0};

    scanf_s("%s", number, 12);
    printf("%zu", sizeof("number"));

    translate(number);
}

void translate(char const *number)
{
    char const *const en[10] =
        {"zero",
         "one",
         "two",
         "three",
         "four",
         "five",
         "six",
         "seven",
         "eight",
         "nine"};

    char const *p = number;

    while (*p != '\0')
    {
        printf("%s ", en[*p++ - 48]);
    }

    printf("\n");

    return;
}
