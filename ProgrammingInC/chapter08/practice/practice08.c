#include <math.h>
#include <stdio.h>

double x1 = 0;
double x2 = 0;
double delta = 0;

void equation(double a, double b, double c);

int main(void)
{
    double a = 1;
    double b = -4;
    double c = 4;

    printf("%lfx^2 + %lfx + %lf = 0\n", a, b, c);

    equation(a, b, c);
    printf("x1 = %lf, x2 = %lf\n", x1, x2);

    return 0;
}

void quadratic(double a, double b, double c)
{
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
}

void linear(double b, double c)
{
    if (fabs(b - 0) < 0.00000000001)
    {
        printf("Divided by ZERO!\n");

        return;
    }

    x1 = x2 = -c / b;
}

void equation(double a, double b, double c)
{
    if (fabs(a - 0) < 0.00000000001)
    {
        linear(b, c);

        return;
    }
    else
    {
        delta = b * b - 4 * a * c;

        if (a > 0)
        {
            quadratic(a, b, c);
        }
        else
        {
            printf("Complex Answer!\n");

            return;
        }
    }
}
