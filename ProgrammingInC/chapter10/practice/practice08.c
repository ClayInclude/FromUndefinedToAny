/**
 * practice08
 * @author Clay
 * @version 2019/5/10
 */

#include <stdbool.h>
#include <stdio.h>

bool testReplaceString(char *str, char const *find, char const *insert);
void testRemoveAll(char *str, char const *find);

int main(void)
{
    char text[100] = "the wrong          person";
    testReplaceString(text, "rong", " !!!! ");
    testRemoveAll(text, " ");
}

int findString(char const *str, char const *find)
{
    char const *temp = str;
    bool flag = false;

    while (*temp != '\0')
    {
        if (*temp == *find)
        {
            flag = true;
            int i = 0;

            while (++i)
            {
                if (*(temp + i) != *(find + i))
                {
                    if (*(find + i) == '\0') break;

                    flag = false;
                    break;
                }
                else if (*(temp + i) == '\0' && *(find + i) == '\0')
                {
                    break;
                }
            }
        }

        if (flag)
        {
            return temp - str;
        }

        ++temp;
    }

    return -1;
}

void removeString(char *str, int start, int numbers)
{
    if (!numbers) return;

    str += start;
    char const *keep = str + numbers;

    while (*keep != '\0')
    {
        *str++ = *keep++;
    }

    *str = '\0';
}

void insertString(char *str, int start, char const *insert)
{
    int offset = 0;
    int length = 0;
    while (insert[offset++] != '\0');
    while (str[length++] != '\0');

    --offset;

    for (int i = length; i >= start; --i)
    {
        str[i + offset] = str[i];
    }

    for (int i = 0; insert[i] != '\0'; ++i)
    {
        str[start + i] = insert[i];
    }
}

bool replaceString(char *str, char const *find, char const *insert)
{
    int index = findString(str, find);
    if (index == -1) return false;

    int length = 0;
    while (find[length++] != '\0');
    --length;

    removeString(str, index, length);
    insertString(str, index, insert);

    return true;
}

bool testReplaceString(char *str, char const *find, char const *insert)
{
    printf("%s replace %s with %s: ", str, find, insert);
    bool flag = replaceString(str, find, insert);
    printf("%s\n", str);

    return flag;
}

void testRemoveAll(char *str, char const *find)
{
    printf("%s replace all %s: ", str, find);
    while (replaceString(str, find, ""));
    printf("%s\n", str);
}
