#include <stdio.h>

int main(void)
{
    float value1 = 0, value2 = 0, result = 0;
    char op = 0;

    printf("Type in your expression.\n");
    scanf_s("%f %c %f", &value1, &op, 1, &value2);

    if (op == '+')
    {
        result = value1 + value2;
    }
    else if (op == '-')
    {
        result = value1 - value2;
    }
    else if (op == '*')
    {
        result = value1 * value2;
    }
    else if (op == '/')
    {
        result = value1 / value2;
    }

    printf("%.2f\n", result);

    return 0;
}
