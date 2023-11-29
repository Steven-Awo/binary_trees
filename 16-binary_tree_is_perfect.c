#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);

const binary_tree_t *get_leaf(const binary_tree_t *tree);

size_t depth(const binary_tree_t *tree);

int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - A fuction that checks if the node is actually a leaf
 * of a binary tree.
 * @node: the node's pointer used to check.
 * Return: If true return 1, otherwise, 0.
 */

unsigned char is_leaf(const binary_tree_t *node)

{
	return ((node->left == NULL &&
				node->right == NULL) ? 1 : 0);
}

/**
 * get_leaf - A fuction that returns a leaf thats of the binary tree.
 * @tree: the root node's ppointer to find the leaf in the tree.
 * Return: first leaf that was encountered.
 */

const binary_tree_t *get_leaf(const binary_tree_t *tree)

{
	if (is_leaf(tree) == 1)
	{
	return (tree);
	}
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * depth -A fuction that returns the given node's depth of a binary tree.
 * @tree: the node's poiter to measure its depth.
 * Return: node's depth.
 */

size_t depth(const binary_tree_t *tree)

{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}


/**
 * is_perfect_recursive - A fuction that checks if the binary tree
 * is actually perfect recursively.
 * @tree: the root node's pointer of the tree used to check.
 * @leaf_depth: depth of a single leaf in a binary tree.
 * @level: the current node's level.
 * Return: If perfect, 1, otherwise return 0.
 */

int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
	{
	return (level == leaf_depth ? 1 : 0);
	}
	if (tree->left == NULL || tree->right == NULL)
	{
	return (0);
	}
	return (is_perfect_recursive(tree->left,
				leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth,
			level + 1));
}

/**
 * binary_tree_is_perfect - A fuction that checks if the binary tree
 * is actually perfect.
 * @tree: the root node's pointer of the tree used to check.
 * Return: If NULL or not perfect return 0.
 *         Otherwise, return 1.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
	return (0);
	}
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
