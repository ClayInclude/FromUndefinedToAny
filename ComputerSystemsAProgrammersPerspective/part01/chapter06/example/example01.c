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

int sumArray3d(int const a[][N][N])
{
    int sum = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                sum += a[i][j][k];
            }
        }
    }

    return sum;
}

typedef struct
{
    int vel[3];
    int acc[3];
} point;

void clear1(point *const p, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            p[i].vel[j] = 0;
        }

        for (int j = 0; j < 3; ++j)
        {
            p[i].acc[j] = 0;
        }
    }
}

void clear2(point *const p, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            p[i].vel[j] = 0;
            p[i].acc[j] = 0;
        }
    }
}

void clear3(point *const p, int n)
{
    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            p[i].vel[j] = 0;
        }

        for (int i = 0; i < n; ++i)
        {
            p[i].acc[j] = 0;
        }
    }
}
