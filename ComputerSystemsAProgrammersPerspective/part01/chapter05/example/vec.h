/**
 * vec
 * @author Clay
 * @date 2020/5/21
 */

#ifndef FROM_UNDEFINED_TO_ANY_VEC_H
#define FROM_UNDEFINED_TO_ANY_VEC_H

#include <stdlib.h>

typedef long int dataT;

typedef struct
{
    long int len;
    dataT *data;
} vecRec, *vecPtr;

#define IDENT 1
#define OP *

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

dataT *getVecStart(vecPtr v)
{
    return v->data;
}

#endif //FROM_UNDEFINED_TO_ANY_VEC_H
