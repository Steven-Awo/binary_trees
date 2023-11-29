#include "binary_trees.h"

/**
 * binary_tree_size - A function that measures the binary tree's sizez.
 * @tree: the root node pointer that measure the sizez.
 * Return: sizez
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t sizez = 0;

	if (tree)
	{
	sizez += 1;
	sizez += binary_tree_size(tree->left);
	sizez += binary_tree_size(tree->right);
	}
	return (sizez);
}
