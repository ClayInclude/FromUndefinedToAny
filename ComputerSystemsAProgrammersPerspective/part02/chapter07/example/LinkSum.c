/**
 * LinkSum
 * @author Clay
 * @date 2020/12/14
 */

int sum(int *a, int n)
{
    int s = 0;

    for (int i = 0; i < n; ++i)
    {
        s += a[i];
    }

    return s;
}
