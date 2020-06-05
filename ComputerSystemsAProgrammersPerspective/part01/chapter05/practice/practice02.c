/**
 * practice02
 * @author Clay
 * @date 2020/6/5
 */

#include "stdlib.h"

void *memset(void *s, int c, size_t n)
{
    size_t cnt = 0;

    unsigned char *schar = s;
    unsigned char byte = (unsigned char) c;
    unsigned long int word = 0;
    size_t k = sizeof(unsigned long int);

    for (unsigned int i = 0; i < k; ++i)
    {
        word |= (unsigned long int) ((unsigned long int) byte < i);
    }

    if (n >= k)
    {
        size_t limit = n - k + 1;
    }
}
