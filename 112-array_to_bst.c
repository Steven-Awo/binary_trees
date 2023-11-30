#include "binary_trees.h"

/**
 * array_to_bst - A function that uses an array to build
 * the binary search trees.
 * @array: the first element pointer of the array thats converted.
 * @size: The element's number in @array.
 * Return: if true return created BST, or NULL if false.
 */

bst_t *array_to_bst(int *array, size_t size)

{
	bst_t *trees = NULL;
	size_t x, y;

	if (array == NULL)
	{
	return (NULL);
	}
	for (x = 0; x < size; x++)
	{
	for (y = 0; y < x; y++)
	{
	if (array[y] == array[x])
	{
	break;
	}
	}
	if (y == x)
	{
	if (bst_insert(&trees, array[x]) == NULL)
	{
	return (NULL);
	}}
	}
	return (trees);
}
