#include "binary_trees.h"

/**
 * create_tree - A function that uses recursion to create an AVL tree
 * @node: the node's pointer
 * @array: the int for the input array 
 * @size: the array's size
 * @mode: to add to left return 1, to add to left return 2
 * Return: void
 */

void create_tree(avl_t **node, int *array, size_t size, int mode)

{
	size_t mid_dlee;

	if (size == 0)
	{
	return;
	}
	mid_dlee = (size / 2);
	mid_dlee = (size % 2 == 0) ? mid_dlee - 1 : mid_dlee;
	if (mode == 1)
	{
	(*node)->left = binary_tree_node(*node,
			array[mid_dlee]);
	create_tree(&((*node)->left),
			array, mid_dlee, 1);
	create_tree(&((*node)->left), array + mid_dlee + 1,
			(size - 1 - mid_dlee), 2);
	}
	else
	{
	(*node)->right = binary_tree_node(*node,
			array[mid_dlee]);
	create_tree(&((*node)->right), array, mid_dlee, 1);
	create_tree(&((*node)->right), array + mid_dlee + 1,
			(size - 1 - mid_dlee), 2);
	}
}

/**
 * sorted_array_to_avl - A function that just creates the roott node
 * and calls to just create_tree
 * @array: the int for the input array 
 * @size: the array's size
 * Return: the roott's pointer
 */

avl_t *sorted_array_to_avl(int *array, size_t size)

{
	avl_t *roott;
	size_t mid_dlee;

	roott = NULL;

	if (size == 0)
	{
	return (NULL);
	}
	mid_dlee = (size / 2);
	mid_dlee = (size % 2 == 0) ? mid_dlee - 1 : mid_dlee;
	roott = binary_tree_node(roott,
			array[mid_dlee]);
	create_tree(&roott,
			array, mid_dlee, 1);
	create_tree(&roott, array + mid_dlee + 1,
			(size - 1 - mid_dlee), 2);
	return (roott);
}
