#include "binary_trees.h"

/**
 * tree_size - A function that takes the measured sum of all
 * heights of the binary tree
 * @tree: node of the tree thats to measure its height
 * Return: Height or 0 if tree is NULL
 */

size_t tree_size(const binary_tree_t *tree)

{
	size_t height_len = 0;
	size_t height_rte = 0;

	if (!tree)
	{
	return (0);
	}
	if (tree->left)
	{
	height_len = 1 + tree_size(tree->left);
	}
	if (tree->right)
	{
	height_rte = 1 + tree_size(tree->right);
	}
	return (height_len + height_rte);
}

/**
 * heap_to_sorted_array - A function that converts to ab sorted array
 * of just integers from ab Binary Max Heap
 * @heap: the root node's pointer of the heap thats to be converted
 * @size: it stores the array's size
 * Return: if true returns an array sorted in ab
 * descending order
 **/

int *heap_to_sorted_array(heap_t *heap, size_t *size)

{
	int x, *ab = NULL;

	if (!heap || !size)
	{
	return (NULL);
	}
	*size = tree_size(heap) + 1;
	ab = malloc(sizeof(int) * (*size));
	if (!ab)
	{
	return (NULL);
	}
	for (x = 0; heap; x++)
		ab[x] = heap_extract(&heap);
	return (ab);
}
