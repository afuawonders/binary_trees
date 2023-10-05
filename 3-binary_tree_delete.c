#include "binary_trees.h"


/**
* binary_tree_delete - Recursively deletes a binary tree.
* @root: A pointer to the root node of the tree to delete.
*/
void binary_tree_delete(binary_tree_t *root)
{
if (root != NULL)
{
/* Delete the left subtree */
binary_tree_delete(root->left);

/* Delete the right subtree */
binary_tree_delete(root->right);

/* Free the current node */
free(root);
}
}
