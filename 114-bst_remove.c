#include "binary_trees.h"
/**
 *bst_min_node - find minimum value in the tree
 *@root: pointer
 *Return: pointer
 */
bst_t *bst_min_node(bst_t *root)
{
	bst_t *tmp;

	/* Assign the address of the root node to the tmp pointer. */
	tmp = root;

	/* Loop until the left node of the tmp pointer is NULL. */
	while (tmp->left != NULL)
		tmp = tmp->left;
	/* Return the address of the tmp pointer. */
	return (tmp);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: The value to remove
 * Return: Pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

		if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (!root->right)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}

		tmp = bst_min_node(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}
