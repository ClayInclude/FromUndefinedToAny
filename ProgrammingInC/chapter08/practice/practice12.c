#include <stdio.h>

void transposeMatrix(double (*source)[5], double (*destination)[4]);
void displayMatrix_5(double (*matrix)[5]);
void displayMatrix_4(double (*matrix)[4]);

int main(void)
{
    double source[4][5] =
        {{1,  2,  3,  4,  5},
         {6,  7,  8,  9,  10},
         {11, 12, 13, 14, 15},
         {16, 17, 18, 19, 20}
        };
    double destination[5][4] = {0};

    transposeMatrix(source, destination);

    displayMatrix_5(source);
    displayMatrix_4(destination);

    return 0;
}

void displayMatrix_5(double (*matrix)[5])
{
    for (int row = 0; row < 4; ++row)
    {
        for (int column = 0; column < 5; ++column)
        {
            printf("%.0lf ", *(*(matrix + row) + column));
        }

        printf("\n");
    }
}

void displayMatrix_4(double (*matrix)[4])
{
    for (int row = 0; row < 5; ++row)
    {
        for (int column = 0; column < 4; ++column)
        {
            printf("%.0lf ", *(*(matrix + row) + column));
        }

        printf("\n");
    }
}

void transposeMatrix(double (*source)[5], double (*destination)[4])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            (*(destination + j))[i] = (*(source + i))[j];
        }
    }
}
