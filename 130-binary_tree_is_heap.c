#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - A function that goes through a binary tree by checking
 * ropt as the max value
 * @tree: the root's pointer
 * Return: 1 if nodes are all max return 1, else 0
 **/

int check_max(const binary_tree_t *tree)
{
	int tmpr1 = 1, tmpr2 = 1;

	if (!tree)
	{
	return (0);
	}
	if (!tree->left && !tree->right)
	{
	return (1);
	}
	if (tree->left)
	{
	if (tree->n <= tree->left->n)
	{
	return (0);
	}
	tmpr1 = check_max(tree->left);
	}
	if (tree->right)
	{
	if (tree->n <= tree->right->n)
	{
	return (0);
	}
	tmpr2 = check_max(tree->right);
	}
	return (tmpr1 && tmpr2);
}
/**
 * binary_tree_is_heap - A function that checks if the binary
 * tree is actually a heap
 * @tree: the node's pointer
 * Return: returns 1 in case its BTS or return 0 otherwise
 **/

int binary_tree_is_heap(const binary_tree_t *tree)

{
	int tmpr;

	if (!tree)
	{
	return (0);
	}
	tmpr = binary_tree_is_complete(tree);
	if (!tmpr)
	{
	return (0);
	}
	return (check_max(tree));
}
