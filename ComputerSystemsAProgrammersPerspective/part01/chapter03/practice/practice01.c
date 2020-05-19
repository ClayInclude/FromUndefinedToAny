/**
 * practice01
 * @author Clay
 * @date 2020/5/19
 */

#include <inttypes.h>

int64_t decode2(long int x, long int y, long int z)
{
    y -= z;
    x *= y;
    int64_t value = x;
    value <<= 63; // NOLINT(hicpp-signed-bitwise)
    value >>= 63; // NOLINT(hicpp-signed-bitwise)

    return value ^ y;
}

long int loop(long x, int n)
{
    long result = 0;

    for (long int mask = 1; mask; mask <<= n) // NOLINT(hicpp-signed-bitwise)
    {
        result |= x & mask; // NOLINT(hicpp-signed-bitwise)
    }

    return result;
}

long int creadAlt(long int const *xp)
{
    return !xp ? 0 : *xp;
}

typedef enum
{
    MODE_A,
    MODE_B,
    MODE_C,
    MODE_D,
    MODE_E
} modeT;

long int switch3(long *p1, long *p2, modeT action)
{
    long int result = 0;

    switch (action)
    {
    case MODE_A:
        result = *p2;
        *p2 = *p1;
        break;
    case MODE_B:
        result = *p1 + *p2;
        *p1 = result;
        break;
    case MODE_C:
        *p1 = 59;
        result = *p2;
        break;
    case MODE_D:
        result = *p2;
        *p1 = result;
    case MODE_E:
        result = 27;
        break;
    default:
        result = 12;
        break;
    }

    return result;
}
