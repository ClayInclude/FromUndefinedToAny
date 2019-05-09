#include <stdio.h>

void testRemoveString(char *src, int start, int numbers);

int main(void)
{
    char text[] = "the wrong son";
    testRemoveString(text, 4, 6);

    return 0;
}

void removeString(char *src, int start, int numbers)
{
    if (!numbers) return;

    src += start;
    char const *keep = src + numbers;

    while (*keep != '\0')
    {
        *src++ = *keep++;
    }

    *src = '\0';
}

void testRemoveString(char *src, int start, int numbers)
{
    printf("%s remove %i char from %i: ", src, numbers, start);
    removeString(src, start, numbers);
    printf("%s\n", src);
}
