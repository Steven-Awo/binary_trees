#include "binary_trees.h"

/**
 * binary_tree_nodes - A function that counts the noddess with 1 child at
 * least in the binary tree.
 * @tree: the root node's pointer of the tree number of counted noddess.
 * Return:  NULL return 0, else return noddess counted.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)

{
	size_t noddess = 0;

	if (tree)
	{
	noddess += (tree->left ||
			tree->right) ? 1 : 0;
	noddess += binary_tree_nodes(tree->left);
	noddess += binary_tree_nodes(tree->right);
	}
	return (noddess);
}
