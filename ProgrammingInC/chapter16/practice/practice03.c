/**
 * practice03
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>
#include <ctype.h>

void copyFile(FILE *in, FILE *out);

int main(void)
{
    /* current path */
    char const *in = "infile";
    char const *out = "outfile";

    FILE *inFile = fopen(in, "r");
    if (!inFile)
    {
        printf("infile dosen't exist\n");

        return 1;
    }

    FILE *outFile = fopen(out, "w");
    if (!outFile)
    {
        printf("outfile open fail\n");

        return 2;
    }

    copyFile(inFile, outFile);
    fclose(inFile);
    fclose(outFile);

    return 0;
}

void copyFile(FILE *in, FILE *out)
{
    int c = 0;

    while ((c = fgetc(in)) != EOF)
    {
        fputc(toupper(c), out);
    }
}
