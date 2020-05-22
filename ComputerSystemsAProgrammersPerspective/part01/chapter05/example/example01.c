/**
 * example01
 * @author Clay
 * @date 2020/5/21
 */

void twiddle1(long int *xp, long int const *yp)
{
    *xp += *yp;
    *xp += *yp;
}

void twiddle2(long int *xp, long int const *yp)
{
    *xp += 2 * *yp;
}

void swap(long int *xp, long int *yp)
{
    *xp = *xp + *yp;
    *yp = *xp - *yp;
    *xp = *xp - *yp;
}

long int counter = 0;

long int f()
{
    return counter++;
}

long int func1()
{
    return f() + f() + f() + f();
}

long int func2()
{
    return 4 * f();
}

long int func1in()
{
    long int t = counter++;

    t += counter++;
    t += counter++;
    t += counter++;

    return t;
}

long int func1opt()
{
    long t = 4 * counter + 6;
    counter += 4;

    return t;
}

void pSum1(float const a[], float p[], long int n)
{
    p[0] = a[0];

    for (long int i = 1; i < n; ++i)
    {
        p[i] = p[i - 1] + a[i];
    }
}

void pSum2(float const a[], float p[], long int n)
{
    long int i = 1;

    p[0] = a[0];

    for (; i < n - 1; i += 2)
    {
        float midVal = p[i - 1] + a[i];

        p[i] = midVal;
        p[i + 1] = midVal + a[i + 1];
    }

    if (i < n)
    {
        p[i] = p[i - 1] + a[i];
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

long int square(long int x)
{
    return x * x;
}
