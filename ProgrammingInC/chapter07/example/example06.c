#include <stdio.h>

int main(void)
{
    char const *const word = "Hello!";

    for (int i = 0; word[i] != '\0'; ++i)
    {
        printf("%c", word[i]);
    }

    return 0;
}
