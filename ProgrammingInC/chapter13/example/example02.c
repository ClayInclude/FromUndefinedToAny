/**
 * example02
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

#define PI 3.141592654

double circumference(double r);
double area(double r);
double volume(double r);

int main(void)
{
    printf("radius = 1; %.4f %.4f %.4f\n", circumference(1), area(1), volume(1));
    printf("radius = 4.98; %.4f %.4f %.4f\n", circumference(4.98), area(4.98), volume(4.98));

    return 0;
}

double circumference(double r)
{
    return 2 * PI * r;
}

double area(double r)
{
    return PI * r * r;
}

double volume(double r)
{
    return 4.0 / 3.0 * PI * r * r * r;
}
