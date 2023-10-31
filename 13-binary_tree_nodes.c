#include "binary_trees.h"

/**
 * binary_tree_nodes -  a function that counts the nodes
 * with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: counts of node or zero
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t l_count, r_count;

	if (!tree)
		return (0);

	l_count = binary_tree_nodes(tree->left);
	r_count = binary_tree_nodes(tree->right);

	if (tree->left || tree->right)
		return (l_count + r_count + 1);
	else
		return (l_count + r_count);
}
