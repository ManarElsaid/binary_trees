#include "binary_trees.h"

/**
 * binary_tree_sibling - a function that finds the sibling of a node
 * @node: a pointer to the node to find the sibling
 * Return: the sibling of the node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || (node->parent == NULL))
		return NULL;

	if (node == node->parent->right)
		return (node->parent->left);
	else
		return (node->parent->right);
}
