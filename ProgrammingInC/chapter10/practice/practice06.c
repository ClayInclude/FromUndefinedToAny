#include <stdio.h>

void testRemoveString(char *str, int start, int numbers);

int main(void)
{
    char text[] = "the wrong son";
    testRemoveString(text, 4, 6);

    return 0;
}

void removeString(char *str, int start, int numbers)
{
    if (!numbers) return;

    str += start;
    char const *keep = str + numbers;

    while (*keep != '\0')
    {
        *str++ = *keep++;
    }

    *str = '\0';
}

void testRemoveString(char *str, int start, int numbers)
{
    printf("%s remove %i char from %i: ", str, numbers, start);
    removeString(str, start, numbers);
    printf("%s\n", str);
}
