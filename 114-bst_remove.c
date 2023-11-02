#include "binary_trees.h"
/**
 * Where root is a pointer to the root node of the tree where you will remove a node
And value is the value to remove in the tree
Once located, the node containing a value equals to value must be removed and freed
If the node to be deleted has two children, it must be replaced with its first in-order successor (not predecessor)
Your function must return a pointer to the new root node of the tree after removing the desired value
*/
bst_t *find_min(bst_t *root);
bst_t *find_max(bst_t *root);
/**
 *find_min - find minimum value in the tree
 *@root: pointer
 *Return: pointer
*/
bst_t *find_min(bst_t *root)
{
    if(!root)
    return (NULL);
    else if(root->left == NULL)
    return (root);
    else
    return (find_min(root->left));
}


/**
 *find_max - find maximum value in the tree
 *@root: pointer
 *Return: pointer
*/
bst_t *find_max(bst_t *root)
{
    if(!root)
    return (NULL);
    else if(root->right == NULL)
    return (root);
    else
    return (find_min(root->right));
}

/**
 *bst_remove -  remove the pointer
 *@root: is a pointer to the root node of the tree where you will remove a node
 *@value: is the value to remove in the tree
 *Return: a pointer to the new root node of the tree after removing the desired value 
*/
bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *suc = NULL;

    if(!root)
        return (NULL);

    if(value < root->n)
        root->left = bst_remove(root->left, value);
    else if(value > root->n)
        root->right = bst_remove(root->right, value);
    else{
        if(!root->left && !root->right)
        {
            root = NULL;
        }
        else if (root->left && !root->right)
        {
        root = root->left;
        free(root->left);
        }
        else if (!root->left && root->right)
        {
        root = root->right;
        free(root->right);
        }
        else
        {
        suc = find_min(root->right);
        root->n = suc->n;
        root->right =  bst_remove(root->right, suc->n);
        }
    }
return (root);



}
