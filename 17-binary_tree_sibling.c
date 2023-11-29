#include "binary_trees.h"

/**
 * binary_tree_sibling - A function to find a node's sibling
 * in a binary tree.
 * @node: the node's pointer to find its sibling.
 * Return: If  NULL or no sibling - return NULL.
 *         Otherwise - the sibling node pointer.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)

{
	if (node == NULL || node->parent == NULL)
	{
	return (NULL);
	}
	if (node->parent->left == node)
	{
	return (node->parent->right);
	}
	return (node->parent->left);
}
