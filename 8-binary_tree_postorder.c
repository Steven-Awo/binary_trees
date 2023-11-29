#include "binary_trees.h"

/**
 * binary_tree_postorder - A function that uses the post-order's traversal to
 * tranverse through the binary tree.
 * @tree: the root node's pointer of the tree to be traverse.
 * @func: a function's pointer to call for each of the node.
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))

{
	if (tree && func)
	{
	binary_tree_postorder(tree->left,
			func);
	binary_tree_postorder(tree->right,
			func);
	func(tree->n);
	}
}
