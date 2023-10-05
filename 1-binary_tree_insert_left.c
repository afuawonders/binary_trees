#include "binary_trees.h"

/**
* binary_tree_insert_left - Inserts a node as a left-child of
*                                  another in a binary tree.
* @p: A pointer to the node to insert the left-child in.
* @v: The value to store in the new node.
*
* Return: If p is NULL or an error occurs - NULL.
*         Otherwise - a pointer to the new node.
*
* Description: If p already has a left-child, the new node
*              takes its place, and the old left-child is set as
*              the left-child of the new node.
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *p, int v)
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

/* If the parent node already has a left-child, adjust the links */
if (p->left != NULL)
{
new_node->left = p->left;
p->left->parent = new_node;
}

/* Set the new node as the left-child of the parent node */
p->left = new_node;

return (new_node);
}
