#include "binary_trees.h"

/**
* binary_tree_is_root - Checks if a n is a root of a binary tree.
* @n: A pointer to the n to check.
*
* Return: If the n is a root - 1.
*         Otherwise - 0.
*/
int binary_tree_is_root(const binary_tree_t *n)
{
if (n == NULL || n->parent != NULL)
return (0);

return (1);
}
