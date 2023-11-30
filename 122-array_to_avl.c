#include "binary_trees.h"

/**
 * array_to_avl - A function that uses an array to create an AVL treees.
 * @array: the first element to be converted of the sarray.
 * @size: The element's number in @array.
 * Return: if true return a created AVL, or NULL if false.
 */

avl_t *array_to_avl(int *array, size_t size)

{
	avl_t *treees = NULL;
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
	}}
	if (y == x)
	{
	if (avl_insert(&treees, array[x]) == NULL)
	{
	return (NULL);
	}}
	}
	return (treees);
}
