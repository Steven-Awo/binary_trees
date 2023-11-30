#include "limits.h"
#include "binary_trees.h"

/**
 * is_bst_helper - A function that checks  of the validity of the binary
 * tree being a search tree.
 * @tree:the root node's pointer of the tree to be checked.
 * @lo: The smallest node that was visited.
 * @hi: The largest node that was visited.
 * Return: If valid BST, return 1, otherwise, return 0.
 */

int is_bst_helper(const binary_tree_t *tree, int lo, int hi)

{
	if (tree != NULL)
	{
	if (tree->n < lo || tree->n > hi)
	{
	return (0);
	}
	return (is_bst_helper(tree->left,
				lo, tree->n - 1) &&
			is_bst_helper(tree->right,
				tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - A function that checks  of the validity of the binary
 * tree being a search tree.
 * @tree:the root node's pointer of the tree to be checked.
 * Return: If valid BST, return 1, otherwise, return 0.
 */

int binary_tree_is_bst(const binary_tree_t *tree)

{
	if (tree == NULL)
	{
	return (0);
	}
	return (is_bst_helper(tree,
				INT_MIN, INT_MAX));
}
