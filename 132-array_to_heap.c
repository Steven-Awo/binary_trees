#include "binary_trees.h"

/**
 * array_to_heap - A function that uses an array to build up
 * a Max Binary Heap tree.
 * @array: the 1st element of the array thats to be converted
 * @size: the array's element number
 * Return: if true return created Binary Heap
 *         return NULL if false
 */

heap_t *array_to_heap(int *array, size_t size)

{
	unsigned int x;
	heap_t *roott = NULL;

	for (x = 0; x < size; x++)
		heap_insert(&roott, array[x]);
	return (roott);
}
