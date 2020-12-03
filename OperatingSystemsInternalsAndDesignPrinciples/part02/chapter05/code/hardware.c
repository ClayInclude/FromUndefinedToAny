/**
 * hardware
 * @author Clay
 * @date 2020/12/3
 */

#include "stdbool.h"
#include "stdnoreturn.h"
#include "stdarg.h"
#include "stdio.h"

void disableInterrupts(void)
{

}

void enableInterrupts(void)
{

}

void parBegin(void (*p)(int), int num, ...)
{
    va_list vaList;

    va_start(vaList, num);

    for (int i = 0; i < num; ++i)
    {
        (*p)(va_arg(vaList, int));
    }

    va_end(vaList);
}


noreturn void p1(void)
{
    while (true)
    {
        disableInterrupts();

        // critical section

        enableInterrupts();

        // remainder
    }
}

int compareAndSwap(int *word, int testVal, int newVal)
{
    int oldVal = *word;

    if (oldVal == testVal)
    {
        *word = newVal;
    }

    return oldVal;
}

void exchange(int *registerV, int *memoryV)
{
    int temp = *memoryV;

    *memoryV = *registerV;
    *registerV = temp;
}

int bolt;

noreturn void swapP(int i)
{
    while (true)
    {
        while (compareAndSwap(&bolt, 0, 1) == 1)
        {

        }

        // critical section

        bolt = 0;

        // remainder
    }
}

noreturn void exchangeP(int i)
{
    while (true)
    {
        int key = 1;

        do
        {
            exchange(&key, &bolt);
        } while (key != 0);

        // critical section

        bolt = 0;

        // remainder
    }
}

int main(void)
{
    bolt = 0;

    parBegin(swapP, 5, 1, 2, 3, 4, 5);
    parBegin(exchangeP, 5, 6, 7, 8, 9, 10);

    return 0;
}
