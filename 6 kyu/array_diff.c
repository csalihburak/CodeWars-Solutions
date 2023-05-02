/*
Your goal in this kata is to implement a difference function, which subtracts one list from another and returns the result.

It should remove all values from list a, which are present in list b keeping their order.

array_diff({1, 2}, 2, {1}, 1, *z) == {2} (z == 1)
If a value is present in b, all of its occurrences must be removed from the other:

array_diff({1, 2, 2, 2, 3}, 5, {2}, 1, *z) == {1, 3} (z == 2)
NOTE: In C, assign return array length to pointer *z

*/


#include <stdlib.h>

//  return a dynamically allocated array
//  assign the length of this array to *z
//  memory will be freed by the test suite
int ifexists(int z[], int u, int v)
{
    int i;
    if (u == 0)
        return 0;
    for (i = 0; i <= u; i++)
        if (z[i] == v)
            return (1);
    return (0);
}
int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int *arr = malloc(sizeof(int) * 1000);
    while (i < n1)
    {
        while (j < n2)
        {
            if (arr1[i] == arr2[j])
                break;
            j++;
        }
        if (j == n2)
            arr[k++] = arr1[i];
        j = 0;
        i++;
    }
    for (i = 0; i < k; i++)
        printf("%d,", arr[i]);
    printf("\n");
    *z = k;
    return arr;
}