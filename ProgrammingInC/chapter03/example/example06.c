/* This program adds tow interger values
   and displays the results */

#include <stdio.h>

int main(void)
{
    // Declare variables
    int value1 = 0, value2 = 0, sum = 0;

    // Assign values and calculate their sum
    value1 = 50;
    value2 = 50;
    sum = value1 + value2;

    // Display the result
    printf("The sum of %i and %i is %i\n", value1, value2, sum);

    return 0;
}

