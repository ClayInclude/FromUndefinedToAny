#include <stdio.h>

int main(void)
{
    char s1[120] = {0}, s2[120] = {0}, s3[120] = {0};

    printf("Enter text:\n");
    scanf_s("%s%s%s", s1, sizeof(s1), s2, sizeof(s2), s3, sizeof(s3));

    printf("s1 = %s, s2 = %s, s3 = %s\n", s1, s2, s3);

    return 0;
}
