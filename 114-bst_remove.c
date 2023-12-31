#include "binary_trees.h"
/**
 *find_min - find minimum value in the tree
 *@root: pointer
 *Return: pointer
 */
bst_t *find_min(bst_t *root)
{
	if (!root)
		return (NULL);
	else if (root->left == NULL)
		return (root);
	else
		return (find_min(root->left));
}


/**
 *bst_remove -  remove the pointer
 *@root: is a pointer to the root node of the tree where you will remove a node
 *@value: is the value to remove in the tree
 *Return: a pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *right;

	right = NULL;
	tmp = NULL;

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
			right = root->right;
				free(root);
			return (right);
		}
		else if (!root->right)
		{
			right = root->left;
			free(root);
			return (right);
		}
		tmp = find_min(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
	}
