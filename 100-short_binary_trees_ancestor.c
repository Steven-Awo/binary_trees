#include "binary_trees.h"

/**
 * binary_trees_ancestor -  A function that finds the ancestor with the
 * lowest common btwn two nodes.
 * @first: the first node.
 * @second: the second node.
 * Return: If no common ancestors return NULL, else return common ancestor.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *momm, *popp;

	if (!first || !second)
	{
	return (NULL);
	}
	if (first == second)
	{
	return ((binary_tree_t *)first);
	}
	momm = first->parent, popp = second->parent;
	if (first == popp || !momm || (!momm->parent && popp))
	{
	return (binary_trees_ancestor(first, popp));
	}
	else if (momm == second || !popp || (!popp->parent && momm))
	{
	return (binary_trees_ancestor(momm, second));
	}
	return (binary_trees_ancestor(momm, popp));
}
