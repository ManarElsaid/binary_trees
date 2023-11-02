#include "binary_trees.h"

/**
 * bst_insert - Insert a value into a Binary Search Tree (BST) using recursion
 * @tree: A double pointer to the root node of the BST
 * @value: The value to insert
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    if (!tree)
        return NULL;

    if (!*tree)
    {
        *tree = binary_tree_node(NULL, value);
        return *tree;
    }

    if (value < (*tree)->n)
    {
        // Recursively insert into the left subtree
        (*tree)->left = bst_insert(&((*tree)->left), value);
        (*tree)->left->parent = *tree;
    }
    else if (value > (*tree)->n)
    {
        // Recursively insert into the right subtree
        (*tree)->right = bst_insert(&((*tree)->right), value);
        (*tree)->right->parent = *tree;
    }

    return *tree;
}
