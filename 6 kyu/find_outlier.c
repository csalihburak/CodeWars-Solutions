/*
You are given an array (which will have a length of at least 3, but could be very large) containing integers. The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N. Write a method that takes the array as an argument and returns this "outlier" N.

Examples
[2, 4, 0, 100, 4, 11, 2602, 36]
Should return: 11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21]
Should return: 160 (the only even number)

*/

#include <stdlib.h>

int find_odd(int *arr, int l)
{
    int i = 0;
    while (i < l)
    {
        if (arr[i] % 2 != 0)
            return arr[i];
        i++;
    }
    return 0;
}
int find_even(int *arr, int l)
{
    int i = 0;
    while (i < l)
    {
        if (arr[i] % 2 == 0)
            return arr[i];
        i++;
    }
    return 0;
}

int find_outlier(const int *arr, size_t count)
{
    int i = 0;
    int j = 0;
    int tut = 0;
    while (i < count)
    {
        if (arr[i] % 2 == 0)
            tut++;
        i++;
    }
    if (tut > 1)
        return (find_odd(arr, count));
    return (find_even(arr, count));
}