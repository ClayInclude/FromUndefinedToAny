#include <stdbool.h>
#include <stdio.h>

void concat(char *source, char const *str);

int main(void)
{
    char source[120] = "hello, ";

    concat(source, "world\n");
    printf("%s", source);

    return 0;
}

void concat(char *source, char const *str)
{
    int index = 0;

    while (true)
    {
        if (source[index] == '\0')
        {
            break;
        }

        ++index;
    }

    for (int i = 0; str[i] != '\0'; ++i, ++index)
    {
        source[index] = str[i];
    }

    source[index] = '\0';
}
