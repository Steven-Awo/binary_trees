#include "limits.h"
#include "binary_trees.h"

size_t height(const binary_tree_t *tree);

int binary_tree_is_avl(const binary_tree_t *tree);

int is_avl_helper(const binary_tree_t *tree, int lo, int hi);

/**
 * height - A function that measures the binary tree's height.
 * @tree: the root node's pointer of the tree that's to be
 * measured for the height.
 * Return: If NULL, return 0, else return the height.
 */

size_t height(const binary_tree_t *tree)

{
	if (tree)
	{
	size_t lh = 0, rh = 0;

	lh = tree->left ? 1 + height(tree->left) : 1;
	rh = tree->right ? 1 + height(tree->right) : 1;
	return ((lh > rh) ? lh : rh);
	}
	return (0);
}

/**
 * is_avl_helper - A function that checks if the binary tree
 * is actaually a valid AVL tree.
 * @tree: the root node's pointer of the tree
 * that's to bedfore its checked.
 * @lo: The smallest node value thaat was visited
 * @hi:the largest node valuethat was visited.
 * Return: If valid AVL tree true, rreturn 1, otherwise,return 0.
 */

int is_avl_helper(const binary_tree_t *tree, int lo, int hi)

{
	size_t lihgt, rhgtt, diffr;

	if (tree != NULL)
	{
	if (tree->n < lo || tree->n > hi)
	{
	return (0);
	}
	lihgt = height(tree->left);
	rhgtt = height(tree->right);
	diffr = lihgt > rhgtt ? lihgt - rhgtt : rhgtt - lihgt;
	if (diffr > 1)
	{
	return (0);
	}
	return (is_avl_helper(tree->left,
				lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - A function that checks if the binary tree
 * is actaually a valid AVL tree.
 * @tree: the root node's pointer of the tree
 * that's to be check for bfor e
 * Retrun: If valid AVL tree true, rreturn 1, otherwise,return 0.
 */

int binary_tree_is_avl(const binary_tree_t *tree)

{
	if (tree == NULL)
	{
	return (0);
	}
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
