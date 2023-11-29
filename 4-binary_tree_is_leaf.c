#include "binary_trees.h"

/**
 * binary_tree_is_leaf - A function that checks if the node is actually
 * a leaf of the binary tree.
 * @node: the node pointer to be checked.
 * Return: If node is actually a leaf - 1.
 *         Otherwise - 0.
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
	{
	return (0);
	}
	return (1);
}
