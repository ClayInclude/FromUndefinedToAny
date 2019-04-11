#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int cache[50] = {2, 3};
    int primeIndex = 2;
    bool flag = true;

    for (int p = 5; !cache[49]; p += 2)
    {
        int limit = sqrt(p);

        flag = true;

        for (int i = 1; cache[i] <= limit; ++i)
        {
            if (p % cache[i] == 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cache[primeIndex++] = p;
            printf("%i\n", p);
        }
    }

    return 0;
}
