#include "binary_trees.h"

/**
 * is_full_recursive - A function that checks if the binary tree
 * is actually a full recursively.
 * @tree: the root node's pointer to the tree to be checked.
 * Return: If its not full,returm 0.
 *         Otherwise, return 1.
 */

int is_full_recursive(const binary_tree_t *tree)

{
	if (tree != NULL)
	{
	if ((tree->left != NULL && tree->right == NULL) ||
	    (tree->left == NULL && tree->right != NULL) ||
	    is_full_recursive(tree->left) == 0 ||
	    is_full_recursive(tree->right) == 0)
	{
	return (0);
	}
	}
	return (1);
}

/**
 * binary_tree_is_full - A function that checks if the binary
 * tree is actually full.
 * @tree: the root node's pointer to the tree to be checked.
 * Return: If NULL or its not full,returm 0.
 *         Otherwise, return 1.
 */

int binary_tree_is_full(const binary_tree_t *tree)

{
	if (tree == NULL)
	{
	return (0);
	}
	return (is_full_recursive(tree));
}
