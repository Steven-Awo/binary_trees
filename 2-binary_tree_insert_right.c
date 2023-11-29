#include "binary_trees.h"

/**
 * binary_tree_insert_right - A function that inserts the node as the
 * right-child in the binary tree.
 * @parent: the node pointer that insert the right-child into.
 * @value: The value that stores in the neww node.
 * Return: If error occurs - NULL.
 *         Otherwise - the neww node pointer.
 * Description: If the parent has a right-child, then the neww node
 *              replaces and then the old right-child is to be set as
 *              the  neww node's right-child.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)

{
	binary_tree_t *newwtree;

	if (parent == NULL)
	{
	return (NULL);
	}
	newwtree = binary_tree_node(parent, value);
	if (newwtree == NULL)
	{
	return (NULL);
	}
	if (parent->right != NULL)
	{
	newwtree->right = parent->right;
	parent->right->parent = newwtree;
	}
	parent->right = newwtree;
	return (newwtree);
}
