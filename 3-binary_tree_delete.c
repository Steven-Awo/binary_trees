#include "binary_trees.h"

/**
 * binary_tree_delete - A function that deletes any binary tree available.
 * @tree: the root node pointer of the tree to be deleted.
 */

void binary_tree_delete(binary_tree_t *tree)

{
	if (tree != NULL)
	{
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
	}
}
