/**
 * example01
 * @author Clay
 * @version V 1.0.0
 */

#include <stdio.h>

int main(void)
{
    char c = 'X';
    char s[] = "abcdefghijklmnopqrstuvwxyz";
    int i = 425;
    short int j = 17;
    unsigned int u = 0xf179u;
    long int l = 75000l;
    long long int L = 0x1234567812345678ll;
    float f = 12.978f;
    double d = -97.4583;
    char *cp = &c;
    int *ip = &i;
    int c1 = 0, c2 = 0;

    printf("Intergers:\n");
    printf("%i %o %x %u\n", i, i, i, i);
    printf("%x %X %#x %#X\n", i, i, i, i);
    printf("%+i % i %07i %.7i\n", i, i, i, i);
    printf("%i %o %x %u\n", j, j, j, j);
    printf("%i %o %x %u\n", u, u, u, u);
    printf("%ld %lo %lx %lu\n", l, l, l, l);
    printf("%lli %llo %llx %llu\n", L, L, L, L);

    printf("\nFloats and Douobles:\n");
    printf("%f %e %g\n", f, f, f);
    printf("%.2f %.2g\n", f, f);
    printf("%.0f %.0g\n", f, f);
    printf("%7.2f %7.2g\n", f, f);
    printf("%lf %le %lg\n", d, d, d);
    printf("%.*lf\n", 3, d);
    printf("%*.*lf\n", 8, 2, d);

    printf("\nCharacters:\n");
    printf("%c\n", c);
    printf("%3c%3c\n", c, c);
    printf("%x\n", c);

    printf("\nStrings:\n");
    printf("%s\n", s);
    printf("%.5s\n", s);
    printf("%30s\n", s);
    printf("%20.5s\n", s);
    printf("%-20.5s\n", s);

    printf("\nPointers:\n");
    printf("%p %p\n", ip, cp);
    printf("This%n is fun.%n\n", &c1, &c2);
    printf("c1 = %i, c2 = %i\n", c1, c2);

    return 0;
}
