#include <stdio.h>

int main(void)
{
    float value1 = 0, value2 = 0, result = 0;
    char op = 0;

    printf("Type in your expression.\n");
    scanf_s("%f %c %f", &value1, &op, 1, &value2);

    switch (op)
    {
        case '+':
            result = value1 + value2;
            break;
        case '-':
            result = value1 - value2;
            break;
        case '*':
            result = value1 * value2;
            break;
        case '/':
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
        break;
        default:
            printf("Unkown operator.\n");

            return 2;
    }

    printf("%.2f\n", result);

    return 0;
}
