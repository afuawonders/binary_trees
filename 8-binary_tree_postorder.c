#include "binary_trees.h"

/**
* binary_tree_postorder - Traverses a binary tree using post-order traversal.
* @root: A pointer to the root node of the tree to traverse.
* @func: A pointer to a function to call for each node.
*/
void binary_tree_postorder(const binary_tree_t *root, void (*func)(int))
{
if (root != NULL && func != NULL)
{
binary_tree_postorder(root->left, func);
binary_tree_postorder(root->right, func);
func(root->n);
}
}
