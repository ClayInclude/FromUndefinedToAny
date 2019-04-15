#include <stdio.h>

void autoStatic(void);

int main(void)
{
    for (int i = 0; i < 5; ++i)
    {
        autoStatic();
    }

    return 0;
}

void autoStatic(void)
{
    auto int autoVar = 1;
    static int staticVar = 1;

    printf("autoVar = %i, staticVar = %i\n", autoVar, staticVar);

    ++autoVar;
    ++staticVar;

    return;
}
