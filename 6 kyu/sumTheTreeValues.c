/*
DESCRIPTION:
Given a node object representing a binary tree:

Node:
  value: <int>,
  left: <Node> or null,
  right: <Node> or null
write a function that returns the sum of all values, including the root. Absence of a node will be indicated with a null value.

Examples:

10
| \
1  2
=> 13

1
| \
0  0
    \
     2
=> 3

*/

#include <stdio.h>
struct node
{
    int value;
    struct node *left;
    struct node *right;
};

int sumTheTreeValues(struct node *root)
{
    return (root == NULL) ? 0 : root->value + sumTheTreeValues(root->left) + sumTheTreeValues(root->right);
}