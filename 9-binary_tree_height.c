#include "binary_trees.h"

/**
 * binary_tree_height - A function that measures the binary tree's height.
 * @tree: the root pointer node of the tree to be measure for its height.
 * Return: If  NULL return 0, else return the height.
 */

size_t binary_tree_height(const binary_tree_t *tree)

{
	if (tree)
	{
	size_t ll = 0, rr = 0;

	ll = tree->left ? 1 +
		binary_tree_height(tree->left) : 0;
	rr = tree->right ? 1 +
		binary_tree_height(tree->right) : 0;
	return ((ll > rr) ? ll : rr);
	}
	return (0);
}
