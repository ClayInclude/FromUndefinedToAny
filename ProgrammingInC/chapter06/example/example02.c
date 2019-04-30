#include <stdio.h>

int main(void)
{
    int numberOfGrade = 0, i = 0, grade = 0;
    int gradeTotal = 0;
    int failureCount = 0;

    printf("Entering grades: \n");

    while (scanf("%i", &grade) && grade != EOF)
    {
        ++numberOfGrade;
        gradeTotal += grade;

        if (grade < 60)
        {
            ++failureCount;
        }

        getchar();
    }

    printf("Grade average = %.2f\n", (float) gradeTotal / numberOfGrade);
    printf("Number of failures = %i\n", failureCount);

    return 0;
}
