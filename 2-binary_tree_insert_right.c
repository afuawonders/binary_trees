#include "binary_trees.h"

/**
* binary_tree_insert_right - Inserts a node as the right-child
*                                 of another in a binary tree.
* @p: A pointer to the node to insert the right-child in.
* @v: The value to store in the new node.
*
* Return: If p is NULL or an error occurs - NULL.
*         Otherwise - a pointer to the new node.
*
* Description: If p already has a right-child, the new node
*              takes its place, and the old right-child is set as
*              the right-child of the new node.
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *p, int v)
{
binary_tree_t *new_node;

/* Check if the parent node is NULL */
if (p == NULL)
return (NULL);

/* Create a new binary tree node with the provided value */
new_node = binary_tree_node(p, v);

/* Check if memory allocation for the new node failed */
if (new_node == NULL)
return (NULL);

/* If the parent node already has a right-child, adjust the links */
if (p->right != NULL)
{
new_node->right = p->right;
p->right->parent = new_node;
}

/* Set the new node as the right-child of the parent node */
p->right = new_node;

return (new_node);
}
