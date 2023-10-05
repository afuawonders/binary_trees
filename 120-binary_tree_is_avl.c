#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
* height - Measures the height of a binary tree.
* @tree: A pointer to the root node of the tree to measure the height.
*
* Return: If tree is NULL, your function must return 0, else return height.
*/
size_t height(const binary_tree_t *tree)
{
if (tree)
{
size_t LEFT = 0, RIGHT = 0;

LEFT = tree->left ? 1 + height(tree->left) : 1;
RIGHT = tree->right ? 1 + height(tree->right) : 1;
return ((LEFT > RIGHT) ? LEFT : RIGHT);
}
return (0);
}

/**
* is_avl_helper - Checks if a binary tree is a valid AVL tree.
* @tree: A pointer to the root node of the tree to check.
* @LOW: The value of the smallest node visited thus far.
* @HIGH: The value of the largest node visited this far.
*
* Return: If the tree is a valid AVL tree, 1, otherwise, 0.
*/
int is_avl_helper(const binary_tree_t *tree, int LOW, int HIGH)
{
size_t LEFTHEIGHT, RIGHTHEIGHT, diff;

if (tree != NULL)
{
if (tree->n < LOW || tree->n > HIGH)
return (0);
LEFTHEIGHT = height(tree->left);
RIGHTHEIGHT = height(tree->right);
diff = LEFTHEIGHT > RIGHTHEIGHT ? LEFTHEIGHT - RIGHTHEIGHT :
RIGHTHEIGHT - LEFTHEIGHT;
if (diff > 1)
return (0);
return (is_avl_helper(tree->left, LOW, tree->n - 1) &&
is_avl_helper(tree->right, tree->n + 1, HIGH));
}
return (1);
}

/**
* binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
* @tree: A pointer to the root node of the tree to check.
*
* Return: 1 if tree is a valid AVL tree, and 0 otherwise
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
