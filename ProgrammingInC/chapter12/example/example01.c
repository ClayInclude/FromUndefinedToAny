/**
 * example01
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

int main(void)
{
    unsigned int word1 = 077u, word2 = 0150u, word3 = 0210u;

    printf("%o ", word1 & word2);
    // printf("%o ", word1 & word1);
    // word1 & word1 == word1
    printf("%o ", word1);
    printf("%o ", word1 & word2 & word3);
    printf("%o\n", word1 & (unsigned int)1);

    return 0;
}
