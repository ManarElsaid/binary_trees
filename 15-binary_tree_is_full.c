#include "binary_trees.h"

/**
 * binary_tree_is_full - a function that checks if a binary tree is full
 * @tree:  a pointer to the root node of the tree to check
 * Return: 1 on success
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	binary_tree_is_full(tree->right);
	binary_tree_is_full(tree->right);

	if (tree->left && tree->right)
		return (1);
	else
		return(0);
}
