#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original source code from http://stackoverflow.com/a/13755911/5184480 */

/**
* print_t - Stores recursively each level in an array of strings
*
* @tree: Pointer to the node to print
* @offset: Offset to print
* @depth: Depth of the node
* @s: Buffer
*
* Return: length of printed tree after process
*/
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
char b[6];
int width, left, right, is_left, index;

if (!tree)
return (0);
is_left = (tree->parent && tree->parent->left == tree);
width = sprintf(b, "(%03d)", tree->n);
left = print_t(tree->left, offset, depth + 1, s);
right = print_t(tree->right, offset + left + width, depth + 1, s);
for (index = 0; index < width; index++)
s[depth][offset + left + index] = b[index];
if (depth && is_left)
{
for (index = 0; index < width + right; index++)
s[depth - 1][offset + left + width / 2 + index] = '-';
s[depth - 1][offset + left + width / 2] = '.';
}
else if (depth && !is_left)
{
for (index = 0; index < left + width; index++)
s[depth - 1][offset - width / 2 + index] = '-';
s[depth - 1][offset + left + width / 2] = '.';
}
return (left + width + right);
}

/**
* _height - Measures the height of a binary tree
*
* @tree: Pointer to the node to measures the height
*
* Return: The height of the tree starting at @node
*/
static size_t _height(const binary_tree_t *tree)
{
size_t heightLeft;
size_t heightRight;

heightLeft = tree->left ? 1 + _height(tree->left) : 0;
heightRight = tree->right ? 1 + _height(tree->right) : 0;
return (heightLeft > heightRight ? heightLeft : heightRight);
}

/**
* binary_tree_print - Prints a binary tree
*
* @tree: Pointer to the root node of the tree to print
*/
void binary_tree_print(const binary_tree_t *tree)
{
char **character;
size_t height, x, y;

if (!tree)
return;
height = _height(tree);
character = malloc(sizeof(*character) * (height + 1));
if (!character)
return;
for (x = 0; x < height + 1; x++)
{
character[x] = malloc(sizeof(**character) * 255);
if (!character[x])
return;
memset(character[x], 32, 255);
}
print_t(tree, 0, 0, character);
for (x = 0; x < height + 1; x++)
{
for (y = 254; y > 1; --y)
{
if (character[x][y] != ' ')
break;
character[x][y] = '\0';
}
printf("%s\n", character[x]);
free(character[x]);
}
free(character);
}
