#include "binary_trees.h"

/**
 * binary_tree_rotate_left - A function that rotates the binary
 * tree to the left.
 * @tree: the root node's pointer of the tree to be rotated.
 * Return: the new root's node after the rotation.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *stand, *tmpr;

	if (tree == NULL || tree->right == NULL)
	{
	return (NULL);
	}
	stand = tree->right;
	tmpr = stand->left;
	stand->left = tree;
	tree->right = tmpr;
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
