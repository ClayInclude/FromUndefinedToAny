#include <stdbool.h>
#include <stdio.h>

bool isDigit(char c);
bool isAlpha(char c);

int main(void)
{
    char c;

    printf("Enter a single character:\n");
    scanf_s("%c", &c);

    if (isAlpha(c))
    {
        printf("It's an alphabetic character.\n");
    }
    else if (isDigit(c))
    {
        printf("It's a digit.\n");
    }
    else
    {
        printf("It's a special character.\n");
    }

    return 0;
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool isAlpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
