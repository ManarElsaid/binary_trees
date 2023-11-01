#include "binary_trees.h"

int tree_is_full(const binary_tree_t *tree);
size_t tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);

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
 * tree_balance - a function that measures the balance
 * factor of a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: meeasurement of balance factor
 */
int tree_balance(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (!tree)
		return (0);

	l_height = tree_height(tree->left);
	r_height = tree_height(tree->right);


	return (!(l_height - r_height));
}

/**
 * tree_is_full - a function that checks if a binary tree is full
 * @tree:  a pointer to the root node of the tree to check
 * Return: 1 on success
 */

int tree_is_full(const binary_tree_t *tree)
{
	int l_full, r_full;

	if (!tree || (!tree->left && tree->right) || (!tree->right && tree->left))
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	l_full = (tree_is_full(tree->left));
	r_full = (tree_is_full(tree->right));

	return (l_full && r_full);

}

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 on perfect tree
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l_perfect, r_perfect;

	if (!tree)
		return (0);

	l_perfect = (tree_is_full(tree->left) && tree_balance(tree->left));
	r_perfect = (tree_is_full(tree->right) && tree_balance(tree->right));

	return (l_perfect && r_perfect);
}
