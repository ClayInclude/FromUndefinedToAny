#include <stdio.h>

int main(void)
{
    float value1 = 0, value2 = 0, result = 0;
    char op = 0;

    printf("Type in your expression.\n");
    scanf("%f %c %f", &value1, &op, &value2); // NOLINT(cert-err34-c)

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
        if (value2 == 0)
        {
            printf("Division by ZERO!.\n");

            return 1;
        }
        else
        {
            result = value1 / value2;
        }
    }
    else
    {
        printf("Unkown operator.\n");

        return 2;
    }

    printf("%.2f\n", result);

    return 0;
}
