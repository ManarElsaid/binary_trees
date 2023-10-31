#include "binary_trees.h"

/**
 * binary_tree_balance - a function that measures the balance
 * factor of a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: meeasurement of balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (!tree)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);

	return (l_height - r_height);
}
