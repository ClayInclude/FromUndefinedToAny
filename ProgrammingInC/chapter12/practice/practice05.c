/**
 * practice05
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>
#include <stdbool.h>

unsigned int _intSize(void);
bool bitTest(unsigned int value, unsigned int n);
unsigned int bitSet(unsigned int value, unsigned int n);

unsigned int intSize = 0;

int main(void)
{
    intSize = _intSize();

    printf("%i\n", bitTest(1, 0));
    printf("%i\n", bitSet(0, 3));

    return 0;
}

unsigned int _intSize(void)
{
    unsigned int i = ~0u, s = 0;

    while (i)
    {
        ++s;
        i >>= 1u;
    }

    return s;
}

bool bitTest(unsigned int value, unsigned int n)
{
    if (n >= intSize) return false;

    return value & (1u << n);
}

unsigned int bitSet(unsigned int value, unsigned int n)
{
    if (n >= intSize) return value;

    return value | (1u << n);
}
