#include "binary_trees.h"

/**
 * binary_tree_leaves - A fuction that counts the number of levees
 * in the binary tree.
 * @tree: the root's node pointer of the tree levees to be counted.
 * Return: levees.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)

{
	size_t levees = 0;

	if (tree)
	{
	levees += (!tree->left && !tree->right) ? 1 : 0;
	levees += binary_tree_leaves(tree->left);
	levees += binary_tree_leaves(tree->right);
	}
	return (levees);
}
