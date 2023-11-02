#include "binary_trees.h"

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

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree:  a pointer to the root node of the tree to check
 * Return: 1 on success
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int l_complete, r_complete;

	if (!tree)
		return (0);

	l_complete = binary_tree_balance(tree->left);
	r_complete = binary_tree_balance(tree->right);

	if ((l_complete - r_complete) == 0 || (l_complete - r_complete) == 1)
		return (1);
	else
		return (0);
}
