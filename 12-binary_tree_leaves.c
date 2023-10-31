#include "binary_trees.h"

/**
 * binary_tree_leaves -  a function that counts the
 * leaves in a binary tree
 * @tree: the pointer to the root node
 * Return: count of leaves or zero if tree = null
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t l_size, r_size;

	if (!tree)
		return (0);

	l_size = binary_tree_leaves(tree->left);
	r_size = binary_tree_leaves(tree->right);

	if (tree->left == NULL && tree->right == NULL)
		return (l_size + r_size + 1);
	return (l_size + r_size);
}
