#include <stdio.h>

void scalarMultiply(int (*matrix)[5], int scalar);
void displayMatrix(int (*matrix)[5]);

int main(void)
{
    int matrix[3][5] =
        {
            [0] = {1, 2, 3, 4, 5},
            {12, 10, 52, 0, 7},
            {[2] = 2}};

    scalarMultiply(matrix, 3);
    displayMatrix(matrix);

    return 0;
}

void scalarMultiply(int (*matrix)[5], int scalar)
{
    for (int row = 0; row < 3; ++row)
    {
        for (int column = 0; column < 5; ++column)
        {
            matrix[row][column] *= scalar;
        }
    }

    return;
}

void displayMatrix(int (*matrix)[5])
{
    for (int row = 0; row < 3; ++row)
    {
        for (int column = 0; column < 5; ++column)
        {
            printf("%i ", *(*(matrix + row) + column));
        }

        printf("\n");
    }

    return;
}
