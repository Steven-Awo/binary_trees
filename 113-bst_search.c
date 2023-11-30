#include "binary_trees.h"

/**
 * bst_search - A function that searches for the value in the
 * binary search tree.
 * @tree: the root node's pointer of the BST to be searched.
 * @value: The value to be searched for.
 * Return: If NULL or not found, return NULL.
 *         Otherwise, returrn the node that contains the value.
 */

bst_t *bst_search(const bst_t *tree, int value)

{
	if (tree != NULL)
	{
	if (tree->n == value)
	{
	return ((bst_t *)tree);
	}
	if (tree->n > value)
	{	
	return (bst_search(tree->left, value));
	}
	return (bst_search(tree->right, value));
	}
	return (NULL);
}
