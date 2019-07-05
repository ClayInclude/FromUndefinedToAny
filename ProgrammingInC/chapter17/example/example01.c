/**
 * example01
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *in, *out;
    int c;

    if (argc != 3)
    {
        fprintf(stderr, "Need two files names\n");

        return 1;
    }

    if (!(in = fopen(argv[1], "r")))
    {
        fprintf(stderr, "Can't read %s.\n", argv[1]);

        return 2;
    }

    if (!(out = fopen(argv[2], "w")))
    {
        fprintf(stderr, "Can't write %s.\n", argv[2]);

        return 3;
    }

    while ((c = fgetc(in)) != EOF)
    {
        fputc(c, out);
    }

    printf("File has been copied.\n");

    fclose(in);
    fclose(out);

    return 0;
}
