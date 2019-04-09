#include <stdio.h>

int main(void)
{
    int dollars = 0, cents = 0;

    for (int count = 0; count < 10; ++count)
    {
        printf("Enter dollars: ");
        scanf_s("%i", &dollars);
        printf("Enter cents: ");
        scanf_s("%i", &cents);

        dollars += cents / 100;
        cents %= 100;

        printf("$%i.%.2i\n\n", dollars, cents);
    }

    return 0;
}
