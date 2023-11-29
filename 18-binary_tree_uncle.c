#include "binary_trees.h"

/**
 * binary_tree_uncle - A function thatt finds the nodes uncle in a binary tree.
 * @node: the node's pointer to find its uncle.
 * Return: If NULL or no uncle, return NULL.
 *         Otherwise, the uncle node's pointer.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)

{
	if (node == NULL ||
			node->parent->parent == NULL ||
			node->parent == NULL)
	{
	return (NULL);
	}
	if (node->parent->parent->left ==
			node->parent)
	{
	return (node->parent->parent->right);
	}
	return (node->parent->parent->left);
}
