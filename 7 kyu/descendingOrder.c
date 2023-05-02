/*
Your task is to make a function that can take any non-negative integer as an argument and return it with its digits in descending order. Essentially, rearrange the digits to create the highest possible number.

Examples:
Input: 42145 Output: 54421

Input: 145263 Output: 654321

Input: 123456789 Output: 987654321


*/


#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
uint64_t *sort_(uint64_t *arr, int len)
{
    int temp = 0;
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    return arr;
}

uint64_t descendingOrder(uint64_t n)
{
    int len1 = 0;
    uint64_t *arr = malloc(sizeof(uint64_t) * 1000);
    int i = 0;
    while (n != 0)
    {
        len1++;
        arr[i++] = n % 10;
        n /= 10;
    }
    for (i = 0; i < len1; i++)
        printf(" before: %d \n", arr[i]);
    arr = sort_(arr, len1);
    for (i = 0; i < len1; i++)
        printf(" after: %d ", arr[i]);
    i = 0;
    uint64_t res = 0;
    printf("\n");
    i = 0;
    while (i < len1)
    {
        res = (res * 10) + arr[i];
        i++;
    }
    printf("res '%d'\n", res);
    return (res);
}