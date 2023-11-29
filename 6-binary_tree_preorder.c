#include "binary_trees.h"

/**
 * binary_tree_preorder - A function that uses the pre-order's traversal to
 * go through the binary tree.
 * @tree: the root node's pointer of the tree to be traverse.
 * @func: a function's pointer to call for each of the node.
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))

{
	if (tree && func)
	{
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
	}
}
