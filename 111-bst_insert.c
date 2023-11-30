#include "binary_trees.h"

/**
 * bst_insert - A function that represents a Binary Search Tree's value.
 * @tree: the root node's of a doble pointer of the BST to is to
 * insert the value.
 * @value: The value to be stored thats to be inserted in the node.
 * Return: if true return created node, or NULL if false.
 */

bst_t *bst_insert(bst_t **tree, int value)

{
	bst_t *currt, *neww;

	if (tree != NULL)
	{
	currt = *tree;
	if (currt == NULL)
	{
	neww = binary_tree_node(currt, value);
	if (neww == NULL)
		return (NULL);
	return (*tree = neww);
	}
	if (value < currt->n)
	{
	if (currt->left != NULL)
		return (bst_insert(&currt->left, value));
	neww = binary_tree_node(currt, value);
	if (neww == NULL)
		return (NULL);
	return (currt->left = neww);
	}
	if (value > currt->n) /* inserted from the right subtree */
	{
	if (currt->right != NULL)
		return (bst_insert(&currt->right, value));
	neww = binary_tree_node(currt, value);
	if (neww == NULL)
		return (NULL);
	return (currt->right = neww);
	}
	}
	return (NULL);
}
