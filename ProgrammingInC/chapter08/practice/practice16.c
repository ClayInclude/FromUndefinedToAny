#include <stdbool.h>
#include <stdio.h>

bool isExit = false;

void getNumberAndBase(void);
void convert(void);
void displayConvertedNumber(void);

int main(void)
{
    getNumberAndBase();

    if (isExit)
    {
        return 1;
    }
    convert();
    displayConvertedNumber();

    return 0;
}

char const baseDigital[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

char result[64] = {0};
int number = 0;
int base = 0;

void clear()
{
    for (int i = 0; i < 64; ++i)
    {
        result[i] = '\0';
    }
}

void getNumberAndBase(void)
{
    printf("Number to be converted?\n");
    scanf_s("%i", &number);

    while (true)
    {

        printf("Base?\n");
        scanf_s("%i", &base);

        if (base == 0)
        {
            isExit = true;
            printf("Program is Exit.\n");

            return;
        }
        else if (base <= 1 || base > 16)
        {
            printf("Illegal base!\n");
        }
        else
        {
            break;
        }
    }
}

void convert()
{
    bool flag = true;
    int index = 0;
    char temp[64] = {'\0'};
    int i = 0;

    if (number < 0)
    {
        number = -number;
        flag = false;
    }
    else if (number == 0)
    {
        printf("0\n");

        return;
    }

    clear();

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
}

void displayConvertedNumber(void)
{
    printf("%s\n", result);
}
