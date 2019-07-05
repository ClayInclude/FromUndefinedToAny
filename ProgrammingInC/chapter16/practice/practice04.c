/**
 * practice04
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

int main(void)
{
    /* current path */
    char const *in1 = "infile1";
    char const *in2 = "infile2";

    FILE *inFile1 = fopen(in1, "r");
    if (!inFile1)
    {
        printf("infile1 dosen't exist\n");

        return 1;
    }

    FILE *inFile2 = fopen(in2, "r");
    if (!inFile2)
    {
        printf("infile2 dosen't exist\n");

        return 2;
    }

    int c1 = 0, c2 = 0;

    while ((c1 = fgetc(inFile1)) != EOF && (c2 = fgetc(inFile2)) != EOF)
    {
        putchar(c1);
        putchar(c2);
    }

    if (c1 != EOF)
    {
        putchar(c1);

        while ((c1 = fgetc(inFile1)) != EOF) putchar(c1);
    }

    if (c2 != EOF)
    {
        putchar(c2);

        while ((c2 = fgetc(inFile2)) != EOF) putchar(c2);
    }

    fclose(inFile1);
    fclose(inFile2);

    return 0;
}
