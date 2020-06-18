/**
 * example01
 * @author Clay
 * @date 2020/6/18
 */

#define N 1
#define M 1

int sumVec(int const v[])
{
    int sum = 0;

    for (int i = 0; i < N; ++i)
    {
        sum += v[i];
    }

    return sum;
}

int sumArrayRows(int const a[][N])
{
    int sum = 0;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            sum += a[i][j];
        }
    }

    return sum;
}

int sumArrayColumns(int const a[][N])
{
    int sum = 0;

    for (int j = 0; j < N; ++j)
    {
        for (int i = 0; i < M; ++i)
        {
            sum += a[i][j];
        }
    }

    return sum;
}
