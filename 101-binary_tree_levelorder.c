#include "binary_trees.h"

size_t tree_height(const binary_tree_t *tree);
void levelorder_display(const binary_tree_t *tree,  void (*func)(int), size_t height);

/**
 * tree_height - calculate the height of a node
 * @tree: pointer to the tree root
 * Return: the height of the tree
*/
size_t tree_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	l_height = tree_height(tree->left);
	r_height = tree_height(tree->right);

	if (l_height >= r_height)
		return (l_height + 1);
	return (r_height + 1);

}

/**
 * levelorder_display - calculate the level order of the tree
 * @tree:  a pointer to the tree
 * @height: the height of the tree
 * @func: a pointer to a function to call for each node
 * Retrun: if tree or func return null
 */

void levelorder_display(const binary_tree_t *tree,  void (*func)(int), size_t height)
{
    if (!tree)
    return;

    if (height == 1)
        func(tree->n);
    else if (height > 1)
  {
    levelorder_display(tree->left, func, height - 1);
    levelorder_display(tree->right, func, height - 1);
  }
}

/**
 * binary_tree_levelorder - a function that goes through a binary tree
 * using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 * Return: NULL if tree or function
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
        return;
    size_t i, height;

    height = tree_height(tree);
    for(i = 1; i <= height + 1; i++)
    levelorder_display(tree, func, i);
}
