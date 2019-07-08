/**
 * example01
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

#define DEBUG

int process(int i, int j, int k);

int main(void)
{
    int i = 0, j = 0, k = 0, nread = 0;
    nread = scanf("%d %d %d", &i, &j, &k);

#ifdef DEBUG
    fprintf(stderr, "Number of integres read = %i\n", nread);
    fprintf(stderr, "i = %i, j = %i, k = %i", i, j, k);
#endif

    printf("%i\n", process(i, j, k));

    return 0;
}

int process(int i, int j, int k)
{
    return i + j + k;
}
