#include "binary_trees.h"

/**
 * binary_tree_is_root - A function that checks if the node is a root
 * of the binary tree.
 * @node: the node's pointer to be checked.
 * Return: If node is actually a root - 1.
 *         Otherwise - 0.
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
	{
	return (0);
	}
	return (1);
}
