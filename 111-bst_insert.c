#include "binary_trees.h"
bst_t *bst_insert(bst_t **tree, int value)
{ 
    if(tree)
    {
    if (*tree == NULL)
    return((bst_t *)binary_tree_node(*tree, value));
    if(value < (*tree)->n)
    *tree = bst_insert(&((*tree)->left), value);
    else if (value >= (*tree)->n)
    *tree = bst_insert(&((*tree)->right), value);
return(*tree);
}
        return NULL;
}
