#include "binary_trees.h"

/**
 * binary_tree_insert_left - A function that inserts the node as the
 * left-child in the binary tree.
 * @parent: the node pointer that insert the left-child into.
 * @value: The value that stores in the neww node.
 * Return: If error occurs - NULL.
 *         Otherwise - the neww node pointer.
 * Description: If the parent has a left-child, then the neww node
 *              replaces and then the old left-child is to be set as
 *              the  neww node's left-child.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)

{
	binary_tree_t *neww;

	if (parent == NULL)
	{
	return (NULL);
	}
	neww = binary_tree_node(parent, value);
	if (neww == NULL)
	{
	return (NULL);
	}
	if (parent->left != NULL)
	{
	neww->left = parent->left;
	parent->left->parent = neww;
	}
	parent->left = neww;

	return (neww);
}
