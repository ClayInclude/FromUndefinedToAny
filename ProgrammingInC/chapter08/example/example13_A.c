#include <stdio.h>

void scalarMultiply(int row, int column, int (*matrix)[column], int scalar);
void displayMatrix(int row, int column, int matrix[row][column]);

int main(void)
{
    int matrix[3][5] =
        {
            [0] = {1, 2, 3, 4, 5},
            {12, 10, 52, 0, 7},
            {[2] = 2}};

    scalarMultiply(3, 5, matrix, 3);
    displayMatrix(3, 5, matrix);

    return 0;
}

void scalarMultiply(int row, int column, int (*matrix)[column], int scalar)
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

void displayMatrix(int row, int column, int matrix[row][column])
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
