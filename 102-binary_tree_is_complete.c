#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
* create_node - Creates a new levelorder_queue_t node.
* @node: The binary tree node for the new node to contain.
*
* Return: If an error occurs, NULL.
*         Otherwise, a pointer to the new node.
*/
levelorder_queue_t *create_node(binary_tree_t *node)
{
levelorder_queue_t *new = malloc(sizeof(levelorder_queue_t));
if (new != NULL)
{
new->node = node;
new->next = NULL;
}
return (new);
}

/**
* free_queue - Frees a levelorder_queue_t queue.
* @head: A pointer to the head of the queue.
*/
void free_queue(levelorder_queue_t *head)
{
levelorder_queue_t *current = head;
while (current != NULL)
{
levelorder_queue_t *next = current->next;
free(current);
current = next;
}
}

/**
* push - Pushes a node to the back of a levelorder_queue_t queue.
* @node: The binary tree node to print and push.
* @head: A double pointer to the head of the queue.
* @tail: A double pointer to the tail of the queue.
*
* Description: Upon malloc failure, exits with a status code of 1.
*/
void push(binary_tree_t *node, levelorder_queue_t *head,
levelorder_queue_t **tail)
{
levelorder_queue_t *new_node = create_node(node);
if (new_node == NULL)
{
free_queue(head);
exit(1);
}

if (*tail == NULL)
{
*tail = new_node;
head = new_node;
}
else
{
(*tail)->next = new_node;
*tail = new_node;
}
}

/**
* pop - Pops the head of a levelorder_queue_t queue.
* @head: A double pointer to the head of the queue.
*/
void pop(levelorder_queue_t **head)
{
if (*head != NULL)
{
levelorder_queue_t *tmp = (*head)->next;
free(*head);
*head = tmp;
}
}

/**
* binary_tree_is_complete - Checks if a binary tree is complete.
* @tree: A pointer to the root node of the tree to traverse.
*
* Return: If the tree is NULL or not complete, 0.
*         Otherwise, 1.
*
* Description: Upon malloc failure, exits with a status code of 1.
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
levelorder_queue_t *queue = NULL;
int is_complete = 1;

if (tree == NULL)
return (0);

enqueue(&queue, &queue, tree);

while (queue != NULL)
{
binary_tree_t *current_node = dequeue(&queue);

if (current_node->left != NULL)
{
if (is_complete)
{
enqueue(&queue, &queue, current_node->left);
}
else
{
free_queue(queue);
return (0);
}
}
else
{
is_complete = 0;
}

if (current_node->right != NULL)
{
if (is_complete)
{
enqueue(&queue, &queue, current_node->right);
}
else
{
free_queue(queue);
return (0);
}
}
else
{
is_complete = 0;
}
}

free_queue(queue);
return (1);
}
