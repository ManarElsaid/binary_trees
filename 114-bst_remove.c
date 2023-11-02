#include "binary_trees.h"

/**
 * find_min - Find the node with the minimum value in the tree
 * @root: Pointer to the root node of the tree
 * Return: Pointer to the node with the minimum value
 */
bst_t *find_min(bst_t *root)
{
	if (!root)
		return NULL;
	while (root->left)
		root = root->left;
	return root;
}

/**
 * bst_remove - Remove a node with a specific value from the BST
 * @root: Pointer to the root node of the tree
 * @value: The value to remove
 * Return: Pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return NULL;

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left && !root->right)
		{
			free(root);
			return NULL;
		}
		else if (root->left && !root->right)
		{
			bst_t *temp = root->left;
			free(root);
			return temp;
		}
		else if (!root->left && root->right)
		{
			bst_t *temp = root->right;
			free(root);
			return temp;
		}
		else
		{
			bst_t *successor = find_min(root->right);
			root->n = successor->n;
			root->right = bst_remove(root->right, successor->n);
		}
	}
	return root;
}
