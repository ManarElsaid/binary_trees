#include "binary_trees.h"
/**
 * bst_insert - Insert a value into a Binary Search Tree (BST)
 * @tree: A double pointer to the root node of the BST
 * @value: The value to insert
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
	return (NULL);

	if (*tree == NULL)
	return ((bst_t *)binary_tree_node(*tree, value));
	if (value == (*tree)->n)
	return (NULL);
	if (value < (*tree)->n)
	*tree = bst_insert(&((*tree)->left), value);
	if (value > (*tree)->n)
	*tree = bst_insert(&((*tree)->right), value);
	return (*tree);
}
