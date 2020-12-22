/**
 * MulVec
 * @author Clay
 * @date 2020/12/22
 */

int mulCnt = 0;

void mulVec(const int *x, const int *y, int *z, int n)
{
    ++mulCnt;

    for (int i = 0; i < n; ++i)
    {
        z[i] = x[i] * y[i];
    }
}
