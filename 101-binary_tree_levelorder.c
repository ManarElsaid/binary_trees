#include "binary_trees.h"
/**
 *
 * 
 * 
 * 
*/
size_t binary_tree_heigh(const binary_tree_t *tree)
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

void levelorde_display(const binary_tree_t *tree,  void (*func)(int), size_t height)
{
    if (!tree)
    return;

    if (height == 1)
        func(tree->n);
    else if (height > 1)
  {
    levelorde_display(tree->left, func, height - 1);
    levelorde_display(tree->right, func, height - 1);
  }
}

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
        return;
    size_t i;
    size_t height = binary_tree_heigh(tree); 
    for(i = 1; i <= height + 1; i++)
    levelorde_display(tree, func, i);
}
