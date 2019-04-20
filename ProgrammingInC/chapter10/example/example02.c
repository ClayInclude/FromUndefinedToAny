#include <stdbool.h>
#include <stdio.h>

typedef struct __String
{
    struct __String *self;
    char _string[120];

    int (*length)(struct __String *self);
} String;

int String_length(String *self)
{
    int index = 0;

    while (true)
    {
        if (self->_string[index] == '\0')
        {
            break;
        }

        ++index;
    }

    return index;
}

String __String_new(char const *str)
{
    int index = 0;
    String s = {&s, {0}, &String_length};

    while (true)
    {
        if (str[index] == '\0')
        {
            break;
        }
        s._string[index] = str[index];

        ++index;
    }

    s._string[index] = '\0';

    return s;
}
struct
{
    String (*new)(char const *str);
} _String = {&__String_new};

int main(void)
{
    String s1 = _String.new("Aster"), s2 = _String.new("at"), s3 = _String.new("awe");

    printf("%i %i %i\n", s1.length(&s1), s2.length(&s2), s3.length(&s3));

    return 0;
}
