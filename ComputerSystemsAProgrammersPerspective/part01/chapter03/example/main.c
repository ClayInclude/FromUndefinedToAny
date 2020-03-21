/**
 * main
 * @author Clay
 * @date 2020/3/21
 */

void multiStore(long int x, long int y, long int *dest);

int main(void)
{
    long int d;

    multiStore(2, 3, &d);

    return 0;
}

long int multi2(long int x, long int y)
{
    return x * y;
}
