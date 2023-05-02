/*

Implement the method lastIndexOf (last_index_of in PHP and Python), which accepts a linked list (head) and a value, and returns the index (zero based) of the last occurrence of that value if exists, or -1 otherwise.

For example: Given the list: 1 -> 2 -> 3 -> 3, and the value 3, lastIndexOf / last_index_of should return 3.

The linked list is defined as follows:

struct List {
    struct List *next;
    int data;
};
Note: the list may be null/None and can hold any type of value.

Good luck!

*/

struct List
{
    struct List *next;
    int data;
};

int last_index_of(const struct List *list, int search_val)
{
    int i = 0;
    int a = 123;
    if (!list)
        return -1;
    while (list)
    {
        if (list->data == search_val)
            a = i;
        i++;
        list = list->next;
    }
    if (a == 123)
        return (-1);
    return a;
}