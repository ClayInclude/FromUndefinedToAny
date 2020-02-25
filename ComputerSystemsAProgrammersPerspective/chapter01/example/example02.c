/**
 * example02
 * @author Clay
 * @date 2020/2/25
 */

#include <stdio.h>

void testShowBytes(int value);

void testShowBytes2();

void testShowBytes3();

void testShowBytes4();

int main(void)
{
    testShowBytes(12345);
    testShowBytes2();
    testShowBytes3();
    testShowBytes4();
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

void showInt(int value)
{
    showBytes((BytePointer) &value, sizeof(int));
}

void showFloat(float value)
{
    showBytes((BytePointer) &value, sizeof(float));
}

void showPointer(void *value)
{
    showBytes((BytePointer) &value, sizeof(void *));
}

void testShowBytes(int value)
{
    int iValue = value;
    float fValue = (float) value;
    int *pValue = &iValue;

    showInt(iValue);
    showFloat(fValue);
    showPointer(pValue);
}

void testShowBytes2()
{
    unsigned int value = 0x87654321;
    BytePointer pValue = (BytePointer) &value;

    showBytes(pValue, 1);
    showBytes(pValue, 2);
    showBytes(pValue, 3);
}

void testShowBytes3()
{
    showInt(3510593);
    showFloat(3510593.0f);
}

void testShowBytes4()
{
    showBytes((BytePointer) "12345", 6);
}
