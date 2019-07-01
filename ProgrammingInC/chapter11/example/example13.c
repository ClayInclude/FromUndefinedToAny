/**
 * example13
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

void copyString(char *to, char const *from);

int main(void)
{
    char const *from = "A string to be copied.";
    char to[50] = {0};

    copyString(to, from);
    printf("%s\n", to);

    copyString(to, "So is this");
    printf("%s\n", to);

    return 0;
}

void copyString(char *to, char const *from)
{
    if (!to || !from)
    {
        return;
    }

    for (; *from != '\0'; ++from, ++to)
    {
        *to = *from;
    }

    *to = '\0';
}
