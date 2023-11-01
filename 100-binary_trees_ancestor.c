#include "binary_trees.h"

/**
 * binary_trees_ancestor - Find the lowest common ancestor
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node, or NULL if none found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *ancestor;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	if ((first->parent == second))
		return (first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return (first->parent);

	ancestor = (binary_tree_t *)binary_trees_ancestor(
	(binary_tree_t *)first->parent,
	(binary_tree_t *)second->parent);
	if (!ancestor && first->parent)
	return (first->parent);
	if (!ancestor && second->parent)
	return (second->parent);
return (ancestor);
}
