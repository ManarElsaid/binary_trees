#include "binary_trees.h"
/**
 *array_to_bst - Write a function that builds a
 * Binary Search Tree from an array
 *@array: is a pointer to the first element of the array to be converted
 *@size: is the number of element in the array
 *Return: apointer
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *tree;

	if (!array || size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
		bst_insert(&tree, array[i]);
	return (tree);
}
