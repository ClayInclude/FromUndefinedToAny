#include <stdbool.h>
#include <stdio.h>

bool isEnd = false;
double answer = 0;

void add(double n);
void sub(double n);
void mul(double n);
void div(double n);
void save(double n);
void end(void);

int main(void)
{

    char op = 0;
    double number = 0;

    while (!isEnd)
    {
        scanf_s("%lf %c", &number, &op, 1);

        switch (op)
        {
            case 'S':
                save(number);
                break;
            case '+':
                add(number);
                break;
            case '-':
                sub(number);
                break;
            case '*':
                mul(number);
                break;
            case '/':
                div(number);
                break;
            case 'E':
                end();
                break;
            default:
                isEnd = true;
                break;
        }

        printf("%f\n", answer);
    }

    return 0;
}

void add(double n)
{
    answer += n;

    return;
}

void sub(double n)
{
    answer -= n;

    return;
}

void mul(double n)
{
    answer *= n;

    return;
}

void div(double n)
{
    if (n == 0)
    {
        printf("Divide by ZERO!\n");

        return;
    }

    answer /= n;

    return;
}

void save(double n)
{
    answer = n;

    return;
}

void end(void)
{
    isEnd = true;

    return;
}
