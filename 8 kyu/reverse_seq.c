/*
Build a function that returns an array of integers from n to 1 where n>0.

Example : n=5 --> [5,4,3,2,1]
*/

#include <stdlib.h>

unsigned short *reverse_seq(unsigned short n)
{
    if (n == 0)
        return NULL;
    unsigned short *arr = malloc(sizeof(unsigned short) * n);
    int i = 0;
    while (n >= 1)
        arr[i++] = n--;
    return arr;
}