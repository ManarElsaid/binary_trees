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
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		return (bst_insert(&((*tree)->left), value));
	}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
	{
		(*tree)->right = binary_tree_node(*tree, value);
		return ((*tree)->right);
	}
		return (bst_insert(&((*tree)->right), value));
	}
	else
	return (*tree);
}
