/*
Given two arrays of strings a1 and a2 return a sorted array r in lexicographical order of the strings of a1 which are substrings of strings of a2.

Example 1:
a1 = ["arp", "live", "strong"]

a2 = ["lively", "alive", "harp", "sharp", "armstrong"]

returns ["arp", "live", "strong"]

Example 2:
a1 = ["tarp", "mice", "bull"]

a2 = ["lively", "alive", "harp", "sharp", "armstrong"]

returns []

Notes:
Arrays are written in "general" notation. See "Your Test Cases" for examples in your language.
In Shell bash a1 and a2 are strings. The return is a string where words are separated by commas.
Beware: In some languages r must be without duplicates.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **sort(char **arr, int l)
{
    int i = 0;
    int j = 0;
    int a = 0;
    char *temp;
    char *tut;
    for (i = 0; i < l; i++)
        for (j = 0; j < l; j++)
        {
            if (arr[i][0] < arr[j][0])
            {
                temp = strdup(arr[i]);
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else if (arr[i][0] == arr[j][0])
            {
                a = 0;
                while ((arr[i][a] == arr[j][a]) && (arr[i][a] && arr[j][a]))
                    a++;
                if (arr[i][a] < arr[j][a])
                {
                    temp = strdup(arr[i]);
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    return arr;
}

char **inArray(char *array1[], int sz1, char *array2[], int sz2, int *lg)
{
    int i = 0;
    char **temp = array1;
    int j = 0;
    int k = 0;
    char **arr = malloc(sizeof(char *) * 100);
    while (i < sz1)
    {
        j = 0;
        while (j < sz2)
        {
            if (strstr(array2[j], array1[i]) != NULL)
            {
                arr[k] = malloc(sizeof(char) * (strlen(array1[i] + 1)));
                printf("j = %d array1[%d] = %s\n", j, i, array1[i]);
                arr[k++] = strdup(array1[i]);
                break;
            }
            j++;
        }
        i++;
    }
    printf("%d\n", k);
    arr = sort(arr, k);
    *lg = k;
    return arr;
}