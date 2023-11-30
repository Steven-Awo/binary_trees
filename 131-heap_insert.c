#include "binary_trees.h"

/**
 * heap_insert - A function that inserts into the Max Binary Heap a valuee
 * @root: the root node's double pointer of the Heap that's
 * to just insert the value
 * @value: the value that's stored in the node thaat's to be inserted
 * Return: if true return the created node or return NULL if false
 */

heap_t *heap_insert(heap_t **root, int value)

{
	heap_t *tres, *newer, *flippd;
	int siz, levs, subb, bitt, lvl, tmpr;

	if (!root)
	{
	return (NULL);
	}
	if (!(*root))
	{
	return (*root = binary_tree_node(NULL, value));
	}
	tres = *root;
	siz = binary_tree_size(tres);
	levs = siz;
	for (lvl = 0, subb = 1; levs >= subb; subb *= 2, lvl++)
		levs -= subb;
	for (bitt = 1 << (lvl - 1); bitt != 1; bitt >>= 1)
		tres = levs & bitt ? tres->right : tres->left;
	newer = binary_tree_node(tres, value);
	levs & 1 ? (tres->right = newer) : (tres->left = newer);
	flippd = newer;
	for (; flippd->parent && (flippd->n > flippd->parent->n);
			flippd = flippd->parent)
	{
	tmpr = flippd->n;
	flippd->n = flippd->parent->n;
	flippd->parent->n = tmpr;
	newer = newer->parent;
	}
	return (newer);
}

/**
 * binary_tree_size - A function that the binary tree size is measured
 * @tree: trees thats its size is to be measured
 * Return: siz of the trees or 0 if NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)

{
	if (!tree)
	{
	return (0);
	}
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
