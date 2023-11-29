#include "binary_trees.h"

/**
 * binary_trees_ancestor - A function that finds the ancestor thats the
 * lowest common between the two nodes.
 * @first: the first node.
 * @second: the second node.
 * Return: If there's no common ancestors return NULL,
 * else return the common ancestor.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mom, *pop;

	if (!first || !second)
	{
	return (NULL);
	}
	if (first == second)
	{
	return ((binary_tree_t *)first);
	}
	mom = first->parent,
	    pop = second->parent;
	if (first == pop || !mom || (!mom->parent && pop))
	{
	return (binary_trees_ancestor(first, pop));
	}
	else if (mom == second || !pop ||
			(!pop->parent && mom))
	{
	return (binary_trees_ancestor(mom, second));
	}
	return (binary_trees_ancestor(mom, pop));
}
