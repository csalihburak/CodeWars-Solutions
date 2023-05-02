/*
Write a function that when given a number >= 0, returns an Array of ascending length subarrays.

pyramid(0) => [ ]
pyramid(1) => [ [1] ]
pyramid(2) => [ [1], [1, 1] ]
pyramid(3) => [ [1], [1, 1], [1, 1, 1] ]
Note: the subarrays should be filled with 1s

Subarrays should not overlap; this will be tested. Dont forget to de-allocate memory in free_pyramid()
*/

#include <stdlib.h>

int **pyramid(unsigned n)
{
    int i = 0;
    int j = 0;
    int **arr = (int **)malloc(sizeof(int *) * n);
    while (i < n)
    {
        arr[i] = (int *)malloc(sizeof(int) * i + 1);
        while (j < i + 1)
        {
            arr[i][j] = 1;
            j++;
        }
        j = 0;
        i++;
    }
    return arr;
}

void free_pyramid(unsigned n, int *pyramid_array[n])
{
    // do your memory de-allocation here
}