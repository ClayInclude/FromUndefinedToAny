/**
 * practice05
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char s[120] = {0};
    int m = 3, n = 5;
    FILE *file = fopen("infile", "r");

    if (!file)
    {
        printf("infile dosen't exist\n");

        return 1;
    }

    while (fgets(s, 120, file))
    {
        bool hasEndl = false;

        for (int i = 0; s[i]; ++i)
        {
            if (i >= m && i <= n)
            {
                if (s[i] == '\n') hasEndl = true;

                putchar(s[i]);
            }
        }

        if (!hasEndl) putchar('\n');
    }

    fclose(file);

    return 0;
}
