#include <stdio.h>

struct month
{
    int days;
    char name[4];
};

int main(void)
{
    const struct month months[12] =
        {
            {31, "Jan"},
            {28, "Feb"},
            {31, "Mar"},
            {30, "Apr"},
            {31, "May"},
            {30, "Jun"},
            {31, "Jul"},
            {31, "Aug"},
            {30, "Sep"},
            {31, "Oct"},
            {30, "Nov"},
            {31, "Dec"}};

    printf("Month Number of Days\n");
    printf("----- ------ -- ----\n");

    for (int i = 0; i < 12; ++i)
    {
        printf("%s: %i\n", months[i].name, months[i].days);
    }

    return 0;
}
