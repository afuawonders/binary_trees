#include "binary_trees.h"

/**
* binary_tree_is_leaf(const binary_tree_t *nod)
*  - Checks if a node is a leaf in a binary tree.
* @nod: A pointer to the nod to check.
*
* Return: 1 if the nod is a leaf, 0 otherwise.
*/
int binary_tree_is_leaf(const binary_tree_t *nod)
{
if (nod == NULL || nod->left != NULL || nod->right != NULL)
return (0);

return (1);
}
