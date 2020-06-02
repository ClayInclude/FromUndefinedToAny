/**
 * vec
 * @author Clay
 * @date 2020/5/21
 */

#include "vec.h"

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

void combine3(vecPtr v, dataT *dest)
{
    dataT *data = getVecStart(v);

    *dest = IDENT;

    for (long int i = 0, len = vecLength(v); i < len; ++i)
    {
        *dest = *dest OP data[i];
    }
}

void combine4(vecPtr v, dataT *dest)
{
    dataT *data = getVecStart(v);

    dataT acc = IDENT;

    for (long int i = 0, len = vecLength(v); i < len; ++i)
    {
        acc = acc OP data[i];
    }

    *dest = acc;
}

void combine5(vecPtr v, dataT *dest)
{
    dataT *data = getVecStart(v);

    dataT acc = IDENT;
    long int i = 0;
    long int length = vecLength(v);
    long int limit = length - 1;

    for (; i < limit; i += 2)
    {
        acc = acc OP data[i] OP data[i + 1];
    }

    for (; i < length; ++i)
    {
        acc = acc OP data[i];
    }

    *dest = acc;
}

void combine5_5(vecPtr v, dataT *dest)
{
    dataT *data = getVecStart(v);

    dataT acc = IDENT;
    long int i = 0;
    long int length = vecLength(v);
    long int limit = length - 4;

    for (; i < limit; i += 5)
    {
        acc = acc OP data[i] OP data[i + 1] OP data[i + 2] OP data[i + 3] OP data[i + 4];
    }

    for (; i < length; ++i)
    {
        acc = acc OP data[i];
    }

    *dest = acc;
}

void combine6(vecPtr v, dataT *dest)
{
    dataT *data = getVecStart(v);

    dataT acc0 = IDENT;
    dataT acc1 = IDENT;
    long int i = 0;
    long int length = vecLength(v);
    long int limit = length - 1;

    for (; i < limit; i += 2)
    {
        acc0 = acc0 OP data[i];
        acc1 = acc1 OP data[i + 1];
    }

    for (; i < length; ++i)
    {
        acc0 = acc0 OP data[i];
    }

    *dest = acc0 OP acc1;
}

void combine7(vecPtr v, dataT *dest)
{
    dataT *data = getVecStart(v);

    dataT acc = IDENT;
    long int i = 0;
    long int length = vecLength(v);
    long int limit = length - 1;

    for (; i < limit; i += 2)
    {
        acc = acc OP (data[i] OP data[i + 1]);
    }

    for (; i < length; ++i)
    {
        acc = acc OP data[i];
    }

    *dest = acc;
}

void combine4b(vecPtr v, dataT *dest)
{
    dataT *data = getVecStart(v);

    dataT acc = IDENT;

    for (long int i = 0, len = vecLength(v); i < len; ++i)
    {
        if (i >= 0 && i < v->len)
        {
            acc = acc OP data[i];
        }
    }

    *dest = acc;
}
