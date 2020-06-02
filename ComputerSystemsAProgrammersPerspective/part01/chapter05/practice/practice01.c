/**
 * practice01
 * @author Clay
 * @date 2020/6/2
 */

#include "../example/vec.h"

void inner4(vecPtr u, vecPtr v, dataT *dest)
{
    long int i;
    long int length = vecLength(u);
    dataT *uData = getVecStart(u);
    dataT *vData = getVecStart(v);
    dataT sum = (dataT) 0;

    for (i = 0; i < length; ++i)
    {
        sum += uData[i] * vData[i];
    }

    *dest = sum;
}

void inner5(vecPtr u, vecPtr v, dataT *dest)
{
    long int i;
    long int length = vecLength(u);
    long int limit = length - 5;
    dataT *uData = getVecStart(u);
    dataT *vData = getVecStart(v);
    dataT sum = (dataT) 0;

    for (i = 0; i < limit; i += 6)
    {
        sum += uData[i] * vData[i];
        sum += uData[i + 1] * vData[i + 1];
        sum += uData[i + 2] * vData[i + 2];
        sum += uData[i + 3] * vData[i + 3];
        sum += uData[i + 4] * vData[i + 4];
        sum += uData[i + 5] * vData[i + 5];
    }

    for (; i < length; ++i)
    {
        sum += uData[i] * vData[i];
    }

    *dest = sum;
}

void inner6(vecPtr u, vecPtr v, dataT *dest)
{
    long int i;
    long int length = vecLength(u);
    long int limit = length - 5;
    dataT *uData = getVecStart(u);
    dataT *vData = getVecStart(v);
    dataT sum1 = (dataT) 0;
    dataT sum2 = (dataT) 0;
    dataT sum3 = (dataT) 0;
    dataT sum4 = (dataT) 0;
    dataT sum5 = (dataT) 0;
    dataT sum6 = (dataT) 0;

    for (i = 0; i < limit; i += 6)
    {
        sum1 += uData[i] * vData[i];
        sum2 += uData[i + 1] * vData[i + 1];
        sum3 += uData[i + 2] * vData[i + 2];
        sum4 += uData[i + 3] * vData[i + 3];
        sum5 += uData[i + 4] * vData[i + 4];
        sum6 += uData[i + 5] * vData[i + 5];
    }

    for (; i < length; ++i)
    {
        sum1 += uData[i] * vData[i];
    }

    *dest = sum1 + sum2 + sum3 + sum4 + sum5 + sum6;
}

void inner7(vecPtr u, vecPtr v, dataT *dest)
{
    long int i;
    long int length = vecLength(u);
    long int limit = length - 5;
    dataT *uData = getVecStart(u);
    dataT *vData = getVecStart(v);
    dataT sum = (dataT) 0;

    for (i = 0; i < limit; i += 6)
    {
        sum += (uData[i] * vData[i]
            + uData[i + 1] * vData[i + 1]
            + uData[i + 2] * vData[i + 2]
            + uData[i + 3] * vData[i + 3]
            + uData[i + 4] * vData[i + 4]
            + uData[i + 5] * vData[i + 5]);
    }

    for (; i < length; ++i)
    {
        sum += uData[i] * vData[i];
    }

    *dest = sum;
}
