#include "binary_trees.h"

/**
* binary_tree_inorder - Traverses a binary tree using in-order traversal.
* @root: A pointer to the root node of the tree to traverse.
* @func: A pointer to a function to call for each node.
*
*/
void binary_tree_inorder(const binary_tree_t *root, void (*func)(int))
{
if (root != NULL && func != NULL)
{
/* Traverse the left subtree */
binary_tree_inorder(root->left, func);
/* Perform the action on the current node */
func(root->n);
/* Traverse the right subtree */
binary_tree_inorder(root->right, func);
}
}
