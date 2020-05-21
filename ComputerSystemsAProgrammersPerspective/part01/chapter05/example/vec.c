/**
 * vec
 * @author Clay
 * @date 2020/5/21
 */

#include <stdlib.h>
#include "vec.h"

vecPtr newVec(long int len)
{
    vecPtr result = (vecPtr) malloc(sizeof(vecRec));
    dataT *data = NULL;

    if (!result)
    {
        return NULL;
    }

    result->len = len;

    if (len > 0)
    {
        data = (dataT *) calloc(len, sizeof(dataT));

        if (!data)
        {
            free((void *) result);

            return NULL;
        }
    }

    result->data = data;

    return result;
}

int getVecElement(vecPtr v, long int index, dataT *dest)
{
    if (index < 0 || index >= v->len)
    {
        return 0;
    }

    *dest = v->data[index];

    return 1;
}

long int vecLength(vecPtr v)
{
    return v->len;
}

void combine1(vecPtr v, dataT *dest)
{
    *dest = IDENT;

    for (long int i = 0; i < vecLength(v); ++i)
    {
        dataT val;

        getVecElement(v, i, &val);
        *dest = *dest OP val;
    }
}

void combine2(vecPtr v, dataT *dest)
{
    *dest = IDENT;

    for (long int i = 0, len = vecLength(v); i < len; ++i)
    {
        dataT val;

        getVecElement(v, i, &val);
        *dest = *dest OP val;
    }
}

long int min(long int x, long int y)
{
    return x < y ? x : y;
}

long int max(long int x, long int y)
{
    return x < y ? y : x;
}

void increase(long int *xp, long int v)
{
    *xp += v;
}

long
