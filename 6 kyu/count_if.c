/*
Implement the method countIf (count_if in PHP and Python), which accepts a linked list (head) and a predicate function, and returns the number of elements which apply to the given predicate.

For example: Given the list: 1 -> 2 -> 3, and the predicate x => x >= 2, countIf / count_if should return 2, since x >= 2 applies to both 2 and 3.

The linked list is defined as follows:

struct Node {
    struct Node *next;
    int data;
};
Note: the list may be null and can hold any type of value.

Good luck!
*/

#include <stdbool.h>

struct Node
{
    struct Node *next;
    int data;
};

typedef bool (*predicate_func)(int);

int count_if(const struct Node *list, predicate_func predicate)
{
    int res = 0;
    while (list)
    {
        if (predicate(list->data))
            res++;
        list = list->next;
    }
    return res;
}