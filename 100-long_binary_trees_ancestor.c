#include "binary_trees.h"

size_t depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - A funcctiong that finds ancestor with the lowest
 * common btwn two nodes.
 * @first: the first node.
 * @second: the second node.
 * Return: If there's no common ancestors, return NULL,
 * else return common ancestor.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t first_deppth, second_deppth;

	if (first == NULL || second == NULL)
	{
	return (NULL);
	}
	if (first == second)
	{
	return ((binary_tree_t *)first);
	}
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
	{
	return ((binary_tree_t *)first);
	}
	if (first->parent == second)
		return ((binary_tree_t *)second);
	for (first_deppth = depth(first); first_deppth > 1; first_deppth--)
		first = first->parent;
	for (second_deppth = depth(second); second_deppth > 1; second_deppth--)
		second = second->parent;
	if (first == second)
	{
	return ((binary_tree_t *)first);
	}
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
	{
	return ((binary_tree_t *)first);
	}
	if (first->parent == second)
	{
	return ((binary_tree_t *)second);
	}
	else
		return (NULL);
}

/**
 * depth - A function that measures the  node's depth in the binary tree.
 * @tree: the node's pointer that measures the depth.
 * Return: If NULL return 0, else return the depth.
 */

size_t depth(const binary_tree_t *tree)

{
	return ((tree->parent != NULL) ? 1 +
			depth(tree->parent) : 0);
}
