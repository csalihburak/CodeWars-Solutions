/*
Write a function that takes an integer as input, and returns the number of bits that are equal to one in the binary representation of that number. You can guarantee that input is non-negative.

Example: The binary representation of 1234 is 10011010010, so the function should return 5 in this case
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
size_t countBits(unsigned value)
{
    int i = 7;
    int j = 0;
    int count = 0;
    char *arr = malloc(sizeof(char) * 1000);
    while (value != 0)
    {
        if (value & 1)
            arr[j++] = '1';
        else
            arr[j++] = '0';
        value >>= 1;
        i--;
    }
    arr[j] = '\0';
    printf("%s\n", arr);
    for (i = 0; i < j; i++)
    {
        if (arr[i] == '1')
            count++;
    }
    return count;
}