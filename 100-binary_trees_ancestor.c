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
	binary_tree_t *tmp;
		if (!first || !second)
		return (NULL);
	while (first)
	{
		tmp = (binary_tree_t *)second;

		while (second)
		{
			if (first == second)
				return ((binary_tree_t *)first);
			second = second->parent;
		}
		second = tmp;
		first = first->parent;
	}
	return (NULL);
}
