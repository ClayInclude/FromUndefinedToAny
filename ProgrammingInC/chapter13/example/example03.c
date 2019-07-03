/**
 * example03
 * @author Clay
 * @version V 1.0.0
 */

#include "example03.h"
#include <stdio.h>

int main(void)
{
    float liters, gallons;

    printf("*** Liters to Gallons ***\n\n");
    printf("Enter the number of liters: ");
    scanf("%f", &liters);

    gallons = liters * QUARTS_PER_LITER / 4.0;
    printf("%g liters = %g gallons\n", liters, gallons);

    return 0;
}
