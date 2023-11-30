#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - A function that measures the binary tree's height
 * @tree: the root node's pointer of the tree that the height is measure
 * Return: if true return Height or if NULL return 0
 */

size_t tree_height(const heap_t *tree)

{
	size_t height_len = 0;
	size_t height_rtte = 0;

	if (!tree)
	{
	return (0);
	}
	if (tree->left)
	{
	height_len = 1 + tree_height(tree->left);
	}
	if (tree->right)
	{
	height_rtte = 1 + tree_height(tree->right);
	}
	if (height_len > height_rtte)
	{
	return (height_len);
	}
	return (height_rtte);
}

/**
 * tree_size_h - A function that measures the binary tree's sum of its heights
 * @tree: the tree that's to be measured for its height
 * Return: if true return Height or if NULL return 0
 */

size_t tree_size_h(const binary_tree_t *tree)

{
	size_t height_len = 0;
	size_t height_rtte = 0;

	if (!tree)
	{
	return (0);
	}
	if (tree->left)
	{
	height_len = 1 + tree_size_h(tree->left);
	}
	if (tree->right)
	{
	height_rtte = 1 + tree_size_h(tree->right);
	}
	return (height_len + height_rtte);
}

/**
 * _preorder -  A function that uses pre-order traversal to go through
 * the binary tree
 * @tree: the tree to be traversed
 * @node: its the last node that's in the traverse
 * @height: tree's height
 * Return: void
 */

void _preorder(heap_t *tree, heap_t **node, size_t height)

{
	if (!tree)
	{
	return;
	}
	if (!height)
	{
	*node = tree;
	}
	height--;
	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - A function that heapifies the max binary heap
 * @root: the binary's heap
 */

void heapify(heap_t *root)

{
	int valuee;
	heap_t *tmpr1, *tmpr2;

	if (!root)
	{
	return;
	}
	tmpr1 = root;
	while (1)
	{
	if (!tmpr1->left)
	{
	break;
	}
	if (!tmpr1->right)
		tmpr2 = tmpr1->left;
	else
	{
		if (tmpr1->left->n > tmpr1->right->n)
			tmpr2 = tmpr1->left;
		else
			tmpr2 = tmpr1->right;
	}
	if (tmpr1->n > tmpr2->n)
		break;
	valuee = tmpr1->n;
	tmpr1->n = tmpr2->n;
	tmpr2->n = valuee;
	tmpr1 = tmpr2;
	}
}

/**
 * heap_extract - A function that extracts from the Max Binary Heap
 * its root node.
 * @root: the heap's root
 * Return: the valuee of its extracted node
 **/

int heap_extract(heap_t **root)

{
	int valuee;
	heap_t *heapp_rr, *nod;

	if (!root || !*root)
	{
	return (0);
	}
	heapp_rr = *root;
	valuee = heapp_rr->n;
	if (!heapp_rr->left && !heapp_rr->right)
	{
	*root = NULL;
	free(heapp_rr);
	return (valuee);
	}

	_preorder(heapp_rr, &nod, tree_height(heapp_rr));

	heapp_rr->n = nod->n;
	if (nod->parent->right)
	{
	nod->parent->right = NULL;
	}
	else
		nod->parent->left = NULL;
	free(nod);
	heapify(heapp_rr);
	*root = heapp_rr;
	return (valuee);
}
