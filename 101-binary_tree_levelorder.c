#include "binary_trees.h"

/**
 * binary_tree_height - calculate the height of the a binary tree
 * @tree: a pointer to the tree
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);

	if (l_height >= r_height)
		return (l_height + 1);
	return (r_height + 1);

}
/**
 * levelorde_dis - gives the level order
 * @tree: a pointer to the tree
 * @func: a pointer to a function to call for each node
 * @height: the height of the tree
 */
void levelorde_dis(const binary_tree_t *tree, void (*func)(int), size_t height)
{
	if (!tree)
		return;

	if (height == 1)
		func(tree->n);
	else if (height > 1)
	{
	levelorde_dis(tree->left, func, height - 1);
	levelorde_dis(tree->right, func, height - 1);
	}
}

/**
 * binary_tree_levelorder -  a function that goes through
 * a binary tree using level-order traversal
 * @tree: a pointer to the tree
 * @func:  a pointer to the root node of the tree to traverse
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i, height;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);
	for (i = 1; i <= height + 1; i++)
	levelorde_dis(tree, func, i);
}

