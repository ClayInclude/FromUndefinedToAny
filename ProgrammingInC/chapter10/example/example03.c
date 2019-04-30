#include <stdbool.h>
#include <stdio.h>

void concat(char *result, char const *str1, char const *str2);

int main(void)
{
    char result[120] = {0};

    concat(result, "Hello, ", "world\n");
    printf("%s", result);

    return 0;
}

void concat(char *result, char const *str1, char const *str2)
{
    int index = 0;

    for (int i = 0; str1[i] != '\0'; ++i, ++index)
    {
        result[index] = str1[i];
    }

    for (int i = 0; str2[i] != '\0'; ++i, ++index)
    {
        result[index] = str2[i];
    }

    result[index] = '\0';
}
