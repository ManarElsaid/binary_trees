#include "binary_trees.h"
/**
 *binary_tree_check_bst - check if tree is BST
 *@tree: a pointer to root
 *@min: lower bound minmum
 *@max: upper bound minimum
 * Return: 1 always success
 */
int binary_tree_check_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (binary_tree_check_bst(tree->right, tree->n, max) &&
			binary_tree_check_bst(tree->left, min, tree->n));
}

/**
 *binary_tree_is_bst - check if tree is BST
 *@tree: a pointer to root
 *Return: 1 always success
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_check_bst(tree, INT_MIN, INT_MAX));
}
