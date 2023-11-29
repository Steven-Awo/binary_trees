#include "binary_trees.h"

/**
 * binary_tree_node - A function that creates a binary tree's node.
 * @parent: A pointer that's to the parent of the node that's to create.
 * @value: The value inserted in the neww node.
 * Return: If error occurs - NULL.
 *         Otherwise - the neww node pointer.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)

{
	binary_tree_t *neww;

	neww = malloc(sizeof(binary_tree_t));
	if (neww == NULL)
	{
	return (NULL);
	}
	neww->n = value;
	neww->parent = parent;
	neww->left = NULL;
	neww->right = NULL;
	return (neww);
}
