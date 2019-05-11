/**
 * practice07
 * @author Clay
 * @version 2019/5/9
 */

#include <stdio.h>
#include <limits.h>

void testInsertString(char *str, int start, char const *insert);

int main(void)
{
    char text[20] = "the wrong son";

    testInsertString(text, 10, "per");

    return 0;
}

void insertString(char *str, int start, char const *insert)
{
    int offset = 0;
    int length = 0;
    while (insert[offset++] != '\0');
    while (str[length++] != '\0');

    --offset;

    for (int i = length; i >= start; --i)
    {
        str[i + offset] = str[i];
    }

    for (int i = 0; insert[i] != '\0'; ++i)
    {
        str[start + i] = insert[i];
    }
}

void testInsertString(char *str, int start, char const *insert)
{
    printf("%s insert %s from %i: ", str, insert, start);
    insertString(str, start, insert);
    printf("%s\n", str);
}
