#include <stdbool.h>
#include <stdio.h>

void readLine(char *line);

int main(void)
{
    char line[80] = {0};

    readLine(line);
    printf("Line is %s", line);

    return 0;
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

    return;
}
