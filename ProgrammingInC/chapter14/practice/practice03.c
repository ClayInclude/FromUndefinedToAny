/**
 * practice03
 * @author Clay
 * @version V 1.0.0
 */

int main(void)
{
    float f = 1.0;
    short int i = 100;
    long int l = 500l;
    double d = 15.00;

    float v1 = f + i;
    double v2 = l / d;
    float v3 = (long)(i / l) + f;
    long int v4 = l * i;
    float v5 = f / 2;
    double v6 = i / (d + f);
    double v7 = l / (i * 2.0);
    double v8 = l + i / (double)1;

    return 0;
}
