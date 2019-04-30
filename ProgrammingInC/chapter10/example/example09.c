#include <stdbool.h>
#include <stdio.h>

void lookup(char const *key);

int main(void)
{
    lookup("abyss");
    lookup("acumen");

    return 0;
}

typedef struct
{
    char word[15];
    char definition[50];
} entry;

entry const dictionary[] =
    {
        {"aardvark", "a burrowing African mammal"},
        {"abyss",    "a bottomless pit"},
        {"acumen",   "mentally sharp; keen"},
        {"addle",    "to become confused"},
        {"aerie",    "a high nest"},
        {"affix",    "to append; attach"},
        {"agar",     "a jelly made from seaweed"},
        {"ahoy",     "a nautical call of greeting"},
        {"aigrette", "an ornamental cluster of feathers"},
        {"ajar",     "partially opened"}};

bool equalStrings(char const *str1, char const *str2)
{
    bool flag = true;
    int index = 0;

    while (true)
    {
        if (str1[index] == str2[index])
        {
            if (str1[index] == '\0')
            {
                break;
            }
        }
        else
        {
            flag = false;
        }

        ++index;
    }

    return flag;
}

void lookup(char const *key)
{
    for (int i = 0; i < 10; ++i)
    {
        if (equalStrings(key, dictionary[i].word))
        {
            printf("%s: %s\n", key, dictionary[i].definition);

            break;
        }
    }
}
