#include <stdbool.h>
#include <stdio.h>

void convert(int n, int base, char *result);

int main(void)
{
    char result[64] = {0};

    convert(10, 2, result);
    convert(10, 8, result);
    convert(10, 16, result);
    convert(100, 2, result);
    convert(10, 8, result);
    convert(10, 16, result);
    convert(128362, 16, result);
}

char const baseDigital[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void clear(char *array, int length)
{
    for (int i = 0; i < length; ++i)
    {
        array[i] = '\0';
    }
}

void convert(int n, int base, char *result)
{
    bool flag = true;
    int number = n;
    int remain = 0;
    int index = 0;
    char temp[64] = {'\0'};
    int i = 0;

    if (base <= 1 || base > 16)
    {
        printf("Illegal base!");

        return;
    }

    if (n < 0)
    {
        n = -n;
        flag = false;
    }
    else if (n == 0)
    {
        printf("0\n");

        return;
    }

    clear(result, 64);

    for (; number && index < 63; ++index)
    {
        temp[index] = baseDigital[number % base];
        number /= base;
    }

    if (!flag)
    {
        result[i++] = '-';
    }

    --index;
    for (; index >= 0; ++i, --index)
    {
        result[i] = temp[index];
    }

    result[i] = '\0';

    printf("%s\n", result);

    return;
}
