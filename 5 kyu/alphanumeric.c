/*
In this example you have to validate if a user input string is alphanumeric. The given string is not nil/null/NULL/None, so you don't have to check that.

The string has the following conditions to be alphanumeric:

At least one character ("" is not valid)
Allowed characters are uppercase / lowercase latin letters and digits from 0 to 9
No whitespaces / underscore
*/

#include <stdbool.h>

bool alphanumeric(const char *strin)
{
    int i = 0;
    if (strin[i] == 0)
    {
        return false;
    }
    printf("\n'%s'\n", strin);
    while (strin && strin[i])
    {
        if (((strin[i] >= 'a' && strin[i] <= 'z') || (strin[i] >= 'A' && strin[i] <= 'Z') || (strin[i] >= '0' && strin[i] <= '9')))
        {

            printf("%c", strin[i]);
            i++;
        }
        else
            return false;
    }
    if (i == strlen(strin))
        return true;
    return false;
}