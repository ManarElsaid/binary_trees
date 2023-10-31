#include "binary_trees.h"

/**
 * binary_tree_inorder - a function that goes through
 * a binary tree using in-order traversal
 * @tree:  a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
   if (!first || !second)
		return NULL;
	if (first == second)
		return (binary_tree_t *)second;
	if (first == second->parent)
		return (binary_tree_t *)first;
	if(first->parent == second->parent)
		return first->parent;
	
	binary_trees_ancestor((binary_tree_t *)first->parent,(binary_tree_t *)second->parent);

    return (binary_tree_t *)binary_trees_ancestor((binary_tree_t *)first->parent,(binary_tree_t *)second->parent);
}
