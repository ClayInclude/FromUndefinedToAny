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
        {"ajar",     "partially opened"}
    };

int compareStrings(char const *str1, char const *str2)
{
    int flag = 0;
    int index = 0;

    while (true)
    {
        if (str1[index] == str2[index] && str1[index] != '\0')
        {
            ++index;
            continue;
        }

        flag = str1[index] - str2[index];
        break;
    }

    return flag;
}

void lookup(char const *key)
{
    int low = 0;
    int high = 9;

    while (low < high)
    {
        int mid = (low + high) / 2;
        int flag = compareStrings(key, dictionary[mid].word);
        if (flag == 0)
        {
            printf("%s: %s\n", key, dictionary[mid].definition);

            break;
        }
        else if (flag > 0)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
}
