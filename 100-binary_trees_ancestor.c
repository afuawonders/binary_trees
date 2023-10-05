#include "binary_trees.h"

/**
* binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
* @first: Pointer to the first node.
* @second: Pointer to the second node.
*
* Return: If no common ancestors return NULL, else return common ancestor.
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
binary_tree_t *mom = first, *pop = second;

if (!first || !second)
return (NULL);

if (first == second)
return ((binary_tree_t *)first);

while (mom != pop)
{
if (mom)
mom = mom->parent;
else
mom = second;

if (pop)
pop = pop->parent;
else
pop = first;
}

return (mom);
}
