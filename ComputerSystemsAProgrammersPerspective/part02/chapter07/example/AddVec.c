/**
 * AddVec
 * @author Clay
 * @date 2020/12/22
 */

int addCnt = 0;

void addVec(const int *x, const int *y, int *z, int n)
{
    ++addCnt;

    for (int i = 0; i < n; ++i)
    {
        z[i] = x[i] + y[i];
    }
}
