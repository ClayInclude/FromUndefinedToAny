/**
 * practice06
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char s[120] = {0};
    int c = 0;
    FILE *file = fopen("infile", "r");

    if (!file)
    {
        printf("infile dosen't exist\n");

        return 1;
    }

    bool isEOF = false;

    do
    {
        for (int i = 0; i < 2; ++i)
        {
            if (fgets(s, 120, file))
            {
                puts(s);
            }
            else
            {
                isEOF = true;

                break;
            }
        }

        c = getchar();
        getchar();

        if (c == 'q')
        {
            break;
        }
    } while (!isEOF);

    fclose(file);

    return 0;
}
