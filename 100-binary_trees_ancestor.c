#include "binary_trees.h"

/**
 * binary_tree_preorder - a function that goes through
 * a binary tree using pre-order traversal
 * @tree:  a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
   if (!first || !second)
		return NULL;
    if (first->parent == second->parent)
        return (binary_tree_t *)first->parent;
    if (first == second->parent)
        return (binary_tree_t *)first;
	return binary_trees_ancestor(first->parent,second->parent);
}
