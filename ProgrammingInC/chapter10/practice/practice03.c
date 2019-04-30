#include <stdbool.h>
#include <stdio.h>

int countWords(char const *str);
void readLine(char *line);

int main(void)
{
    char str[120] = {0};
    bool endOfText = false;
    int total = 0;

    printf("Type in your text.\n");

    while (!endOfText)
    {
        readLine(str);

        if (str[0] == '\0')
        {
            endOfText = true;
        }

        total += countWords(str);
    }

    printf("There are %i words in the above text!.\n", total);

    return 0;
}

bool isAlaph(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int countWords(char const *str)
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
            if (flag && str[i] != '\'')
            {
                flag = false;
            }
        }
    }

    return words;
}

void readLine(char *line)
{
    int index = -1;
    int c = 0;

    do
    {
        c = getchar();

        if (c == EOF || c == '\0' || c == '\n')
        {
            break;
        }

        line[++index] = c;

    } while (true);

    line[++index] = '\0';
}
