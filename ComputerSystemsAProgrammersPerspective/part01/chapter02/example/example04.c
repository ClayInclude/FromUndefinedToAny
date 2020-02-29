/**
 * example04
 * @author Clay
 * @date 2020/2/29
 */

#include <stdio.h>
#include <string.h>

void test1(float const *array, int length);
void test2(char const *s, char const *t);

int main(void)
{
    test1(NULL, 0);
    test1((float []){1, 3, 5, 6}, 4);

    test2("a", "b");
    test2("abc", "");
    test2("b", "abc");

    return 0;
}

double sumElements(float const *array, int length)
{
    double sum = 0;

    if (!array) return sum;

    for (int i = 0; i < length; ++i)
    {
        sum += array[i];
    }

    return sum;
}

int strLonger(char const *s, char const *t)
{
    return strlen(s) > strlen(t);
}

void test1(float const *array, int length)
{
    printf("%.2f\n", sumElements(array, length));
}

void test2(char const *s, char const *t)
{
    int result = strLonger(s, t);
    char const *prompt = result ? "" : " not";

    printf("%s is%s longer than %s\n", s, prompt, t);
}
