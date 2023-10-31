#include "binary_trees.h"

size_t tree_height(const binary_tree_t *tree);

/**
 * tree_height - calculate the height of a node
 * @tree: pointer to the tree root
 * Return: the height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (!tree)
		return (0);

	l_height = tree_height(tree->left);
	r_height = tree_height(tree->right);

	if (l_height >= r_height)
		return (l_height + 1);
	else
		return (r_height + 1);
}

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

	l_height = tree_height(tree->left);
	r_height = tree_height(tree->right);

	return (l_height - r_height);
}
