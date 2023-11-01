#include "binary_trees.h"

/**
 * binary_tree_is_full - a function that checks if a binary tree is full
 * @tree:  a pointer to the root node of the tree to check
 * Return: 1 on success
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int l_full, r_full;

	if (!tree || (!tree->left && tree->right) || (!tree->right && tree->left))
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	l_full = (binary_tree_is_full(tree->left));
	r_full = (binary_tree_is_full(tree->right));

	return (l_full && r_full);

}
