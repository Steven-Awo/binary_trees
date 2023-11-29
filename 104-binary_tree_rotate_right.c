#include "binary_trees.h"

/**
 * binary_tree_rotate_right - A function that rotates the binary
 * tree to the right.
 * @tree: the root node's pointer of the tree to be rotated.
 * Return: the new root's node after the rotation.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)

{
	binary_tree_t *stand, *tmpr;

	if (tree == NULL || tree->left == NULL)
	{
	return (NULL);
	}
	stand = tree->left;
	tmpr = stand->right;
	stand->right = tree;
	tree->left = tmpr;
	if (tmpr != NULL)
	{
	tmpr->parent = tree;
	}
	tmpr = tree->parent;
	tree->parent = stand;
	stand->parent = tmpr;
	if (tmpr != NULL)
	{
	if (tmpr->left == tree)
	{
	tmpr->left = stand;
	}
	else
		tmpr->right = stand;
	}
	return (stand);
}
