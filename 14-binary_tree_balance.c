#include "binary_trees.h"

/**
* binary_tree_balance - Measures the balance factor of a binary tree.
* @tree: A pointer to the root node of the tree to measure the balance factor.
*
* Return: If tree is NULL, return 0, else return balance factor.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
if (tree != NULL)
return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

return (0);
}

/**
* binary_tree_height - Measures the height of a binary tree.
* @tree: A pointer to the root node of the tree to measure the height.
*
* Return: If tree is NULL, your function must return 0, else return height.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree != NULL)
{
size_t LEFT = 0, RIGHT = 0;
if (tree->left)
{
LEFT = 1 + binary_tree_height(tree->left);
}
else
{
LEFT = 1;
}

if (tree->right)
{
RIGHT = 1 + binary_tree_height(tree->right);
}
else
{
RIGHT = 1;
}
return ((LEFT > RIGHT) ? LEFT : RIGHT);
}
return (0);
}
