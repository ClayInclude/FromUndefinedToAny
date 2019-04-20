#include <stdbool.h>
#include <stdio.h>

void countWords(char const *str);

int main(void)
{
    countWords("asdkfj aweifj... aifwh3 32fj");

    return 0;
}

bool isAlaph(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void countWords(char const *str)
{
    int words = 0;
    bool flag = false;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (isAlaph(str[i]))
        {
            if (!flag)
            {
                flag = true;
                ++words;
            }
        }
        else
        {
            if (flag)
            {
                flag = false;
            }
        }
    }

    printf("%s    word -- %i", str, words);

    return;
}
