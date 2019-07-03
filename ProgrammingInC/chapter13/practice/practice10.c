/**
 * practice10
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

#define printx(arr, i) printf("%i\n", arr[i])
#define setx(arr, i, v) arr[(i)] = (v)

int main(void)
{
    int x[10] = {0};

    for (int i = 0; i < 10; ++i)
    {
        setx(x, i, i);
    }

    for (int i = 0; i < 10; ++i)
    {
        printx(x, i);
    }

    return 0;
}
