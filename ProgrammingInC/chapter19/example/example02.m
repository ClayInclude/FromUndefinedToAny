#import <stdio.h>
#import <objc/Object.h>

@interface Fraction : Object
{
    int numerator;
    int denominator;
}

- (void)setNumerator:(int)n;
- (void)setDenominator:(int)d;
- (void)print;

@end

@implementation Fraction;

- (int)numerator {
    return numerator;
}

- (int)denominator {
    return denominator;
}

- (void)setNumerator:(int)n {
    numerator = n;
}

- (void)setDenominator:(int)d {
    denominator = d;
}

- (void)print {
    printf("The value of the fraction is %i/%i\n", numerator, denominator);
}

int main(void)
{
    Fraction *f = [Fraction new];

    [f setNumerator: 1];
    [f setDenominator: 3];

    printf("The numerator is %i, and the denominator is %i\n", [f numerator], [f denominator]);

    [f print];
    [f free];

    return 0;
}
