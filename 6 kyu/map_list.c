/*
Implement the method map, which accepts a linked list (head) and a mapping function, and returns a new linked list (head) where every element is the result of applying the given mapping method to each element of the original list.

For example: Given the list: 1 -> 2 -> 3, and the mapping function x => x * 2, map should return 2 -> 4 -> 6

The linked list is defined as follows:

struct Node {
  struct Node *next;
  int data;
};
Note: the list may be null and can hold any type of value.

Good luck!
*/

#include <stddef.h>

typedef struct Node
{
    struct Node *next;
    int data;
} node;

typedef int (*map_func)(int);

/* return a fresh new list
   allocate each node on the heap, so that the list can be freed recursively
   do not mutate or re-use the input list
*/

struct Node *map_list(const struct Node *list, map_func f)
{
    node *new_list = calloc(sizeof(node), sizeof(node));
    node *temp = new_list;
    int a = 0;
    if (!list)
        return NULL;
    while (list)
    {
        a = f(list->data);
        new_list->data = a;
        if (list->next)
            new_list->next = calloc(sizeof(node), sizeof(node));
        new_list = new_list->next;
        list = list->next;
    }
    return temp;
}