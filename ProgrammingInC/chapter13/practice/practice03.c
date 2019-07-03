/**
 * practice03
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MAX3(x, y, z) ((x) > (y) ? (x) > (z) ? (x) : (z) : (y) > (z) ? (y) : (z))
#define SHIFT(value, n) ((n) > 0 ? (value) << (n) : (value) >> (-n))
#define IS_UPPER_CASE(c) ((c) >= 'A' && (c) <= 'Z')
#define IS_LOWER_CASE(c) ((c) >= 'a' && (c) <= 'z')
#define IS_ALPHABETIC(c) IS_UPPER_CASE(c) || IS_LOWER_CASE(c)
#define IS_DIGIT(n) ((n) >= '0' && (n) <= '9')
#define ABSOLUTE_VALUE(n) ((n) >= 0 ? (n) : (-n))

int main(void)
{
    printf("%i\n", MIN(7, 10));
    printf("%i\n", MAX(7, 10));
    printf("%i\n", MAX3(3, 999, -1));
    printf("%i\n", SHIFT(3u, 3u));
    printf("%i\n", IS_ALPHABETIC('E'));
    printf("%i\n", IS_ALPHABETIC('a'));
    printf("%i\n", IS_ALPHABETIC('.'));
    printf("%i\n", IS_ALPHABETIC(0));
    printf("%i\n", IS_DIGIT('3'));
    printf("%i\n", IS_DIGIT(0));
    printf("%f\n", ABSOLUTE_VALUE(-999.3));

    return 0;
}
