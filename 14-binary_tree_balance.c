#include "binary_trees.h"

/**
 * binary_tree_balance - A function that measures all the factors
 * balanced of a binary tree.
 * @tree: the root node's pointer of the tree measureed number
 * to the balance factor.
 * Return: NULL return 0, else return the balance factor.
 */

int binary_tree_balance(const binary_tree_t *tree)

{
	if (tree)
	{
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
	return (0);
}

/**
 * binary_tree_height - A function that measures the binary tree's height.
 * @tree: the root node's pointer of the tree's measured height.
 * Return:  NULL return 0, else return the height.
 */

size_t binary_tree_height(const binary_tree_t *tree)

{
	if (tree)
	{
	size_t ll = 0, rr = 0;

	ll = tree->left ? 1 +
		binary_tree_height(tree->left) : 1;
	rr = tree->right ? 1 +
		binary_tree_height(tree->right) : 1;
	return ((ll > rr) ? ll : rr);
	}
	return (0);
}
