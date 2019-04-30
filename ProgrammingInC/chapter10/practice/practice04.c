#include <stdio.h>

void substr(char const *source, char *sub, int index, int num);

int main(void)
{
    char sub[20] = {0};

    substr("fasefawef", sub, 2, 3);
    substr("character", sub, 4, 3);
    substr("two words", sub, 4, 20);

    return 0;
}

void substr(char const *source, char *sub, int index, int num)
{
    int _i = index;

    for (int i = 0; i < index; ++i)
    {
        if (source[i] == '\0')
        {
            return;
        }
    }

    int i = 0;

    while (source[index] != '\0' && i < num)
    {
        sub[i++] = source[index++];
    }

    sub[i] = '\0';

    printf("%s's substring from %i to %i is %s\n", source, _i, _i + i - 1, sub);
}
