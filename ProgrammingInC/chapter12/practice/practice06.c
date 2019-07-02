/**
 * practice06
 * @author Clay
 * @version V 1.0.0
 */

unsigned int _intSize(void);

unsigned int intSize = 0;

int main(void)
{
    intSize = _intSize();

    return 0;
}

unsigned int _intSize(void)
{
    unsigned int i = ~0u, s = 0;

    while (i)
    {
        ++s;
        i >>= 1u;
    }

    return s;
}
