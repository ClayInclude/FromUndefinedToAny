#include <stdio.h>

void printMessage(void);

int main(void)
{
    for (int i = 0; i < 5; ++i)
    {
        printMessage();
    }

    return 0;
}

void printMessage(void)
{
    printf("Programming is fun.\n");
}
