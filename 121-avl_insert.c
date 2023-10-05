#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
* height - Measures the height of a binary tree.
* @tree: A pointer to the root node of the tree to measure the height.
*
* Return: If tree is NULL, your function must return 0, else return height.
*/
size_t height(const binary_tree_t *tree)
{
if (tree != NULL)
{
size_t LEFT = 0, RIGHT = 0;

LEFT = tree->left ? 1 + binary_tree_height(tree->left) : 1;
RIGHT = tree->right ? 1 + binary_tree_height(tree->right) : 1;
return ((LEFT > RIGHT) ? LEFT : RIGHT);
}
return (0);
}

/**
* balance - Measures the balance factor of a binary tree.
* @tree: A pointer to the root node of the tree to measure the balance factor.
*
* Return: If tree is NULL, return 0, else return balance factor.
*/
int balance(const binary_tree_t *tree)
{
return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
* avl_insert_recursive - Inserts a value into an AVL tree recursively.
* @tree: A double pointer to the root node of the AVL tree to insert into.
* @parent: The parent node of the current working node.
* @fresh: A double pointer to store the new node.
* @value: The value to insert into the AVL tree.
*
* Return: A pointer to the new root after insertion, or NULL on failure.
*/
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
avl_t **fresh, int value)
{
int bfactor;

if (*tree == NULL)
return (*fresh = binary_tree_node(parent, value));

if ((*tree)->n > value)
{
(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, fresh, value);
if ((*tree)->left == NULL)
return (NULL);
}
else if ((*tree)->n < value)
{
(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, fresh, value);
if ((*tree)->right == NULL)
return (NULL);
}
else
return (*tree);

bfactor = balance(*tree);
if (bfactor > 1 && (*tree)->left->n > value)
*tree = binary_tree_rotate_right(*tree);
else if (bfactor < -1 && (*tree)->right->n < value)
*tree = binary_tree_rotate_left(*tree);
else if (bfactor > 1 && (*tree)->left->n < value)
{
(*tree)->left = binary_tree_rotate_left((*tree)->left);
*tree = binary_tree_rotate_right(*tree);
}
else if (bfactor < -1 && (*tree)->right->n > value)
{
(*tree)->right = binary_tree_rotate_right((*tree)->right);
*tree = binary_tree_rotate_left(*tree);
}

return (*tree);
}

/**
* avl_insert - Inserts a value into an AVL tree.
* @tree: A double pointer to the root node of the AVL tree to insert into.
* @value: The value to insert into the AVL tree.
* Return: A pointer to the inserted node, or NULL on failure.
*/
avl_t *avl_insert(avl_t **tree, int value)
{
avl_t *fresh = NULL;

if (tree == NULL)
return (NULL);
if (*tree == NULL)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}
avl_insert_recursive(tree, *tree, &fresh, value);
return (fresh);
}
