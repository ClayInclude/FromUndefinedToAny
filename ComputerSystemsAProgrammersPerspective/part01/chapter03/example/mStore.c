/**
 * mstore
 * @author Clay
 * @date 2020/3/21
 */

long int multi2(long int x, long int y);

void multiStore(long int x, long int y, long int *dest)
{
    *dest = multi2(x, y);
}
