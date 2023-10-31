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

	binary_trees_ancestor((binary_tree_t *)first->parent,(binary_tree_t *)second->parent);
    return (binary_tree_t *)first;
    binary_trees_ancestor(second->left, second->right);
    return (binary_tree_t *)second->parent;

}
