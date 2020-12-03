/**
 * critical
 * @author Clay
 * @date 2020/12/3
 */

#include "stdbool.h"
#include "stdnoreturn.h"

enum RESOURCE_TYPE
{
    RESOURCE_A = 1
};

void enterCritical(enum RESOURCE_TYPE res)
{

}

void exitCritical(enum RESOURCE_TYPE res)
{

}

noreturn void p1(void)
{
    while (true)
    {
        // preceding code

        enterCritical(RESOURCE_A);

        // critical section

        exitCritical(RESOURCE_A);

        // following code
    }
}

noreturn void p2(void)
{
    while (true)
    {
        // preceding code

        enterCritical(RESOURCE_A);

        // critical section

        exitCritical(RESOURCE_A);

        // following code
    }
}

noreturn void p3(void)
{
    while (true)
    {
        // preceding code

        enterCritical(RESOURCE_A);

        // critical section

        exitCritical(RESOURCE_A);

        // following code
    }
}
