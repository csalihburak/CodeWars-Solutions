/*
Complete the solution so that the function will break up camel casing, using a space between words.

Example
"camelCasing"  =>  "camel Casing"
"identifier"   =>  "identifier"
""             =>  ""

*/

#include <stddef.h> // NULL

// returned buffer should be dynamically allocated and will be freed by a caller
char *solution(const char *camelCase)
{
    char *arr = malloc(sizeof(char) * 10000);
    int i = 0;
    int j = 0;
    if (!camelCase)
        return NULL;
    while (camelCase[i])
    {
        if (camelCase[i] >= 65 && camelCase[i] <= 90)
            arr[j++] = ' ';
        arr[j++] = camelCase[i];
        i++;
    }
    arr[j] = '\0';
    return arr;
}