/**
 * Main2
 * @author Clay
 * @date 2020/12/22
 */

#include <stdio.h>
#include "Vector.h"

int x[2] = {1, 2};
int y[2] = {3, 4};
int z[2];

int main(void)
{
    addVec(x, y, z, 2);

    printf("z = {%d, %d}\n", z[0], z[1]);

    return 0;
}
