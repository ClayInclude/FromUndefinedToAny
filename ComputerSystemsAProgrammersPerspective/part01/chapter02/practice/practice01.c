/**
 * practice01
 * @author Clay
 * @date 2020/3/12
 */

#include <stdio.h>

void test(short int x, long int l, double d);

int main(void)
{
    test(12345, 12345, 12345.0);
    test(-10673, 1234511, 1234511.0);
    test(-12345, -12345, -12345.0);
    test(10673, -1234511, -1234511.0);
    test(0, 0, 0.0);
    test(1, 1, 1.0);
}

typedef unsigned char *BytePointer;

void showBytes(BytePointer pointer, size_t len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%.2x", pointer[i]);

        if (i < len - 1)
        {
            printf(" ");
        }
    }

    printf("\n");
}

void showShort(short int x)
{
    showBytes((BytePointer)&x, sizeof(short int));
}

void showLong(long int x)
{
    showBytes((BytePointer)&x, sizeof(long int));
}

void showDouble(double x)
{
    showBytes((BytePointer)&x, sizeof(double));
}

void test(short int x, long int l, double d)
{
    showShort(x);
    showLong(l);
    showDouble(d);
    printf("\n");
}
