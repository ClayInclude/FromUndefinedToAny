/**
 * example06
 * @author Clay
 * @date 2020/3/9
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void *copyElements(void *eleSrc[], int eleCnt, size_t eleSize)
{
    uint64_t requestSize = eleCnt * (uint64_t) eleSize;
    size_t realSize = eleCnt * eleSize;

    if (requestSize != realSize)
    {
        return NULL;
    }

    void *result = malloc(realSize);

    if (!result)
    {
        return NULL;
    }

    void *next = result;
    for (int i = 0; i < eleCnt; ++i)
    {
        memcpy(next, eleSrc[i], eleSize);

        next += eleSize;
    }

    return result;
}
