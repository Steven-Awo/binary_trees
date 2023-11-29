#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include "binary_trees.h"

/**
 * print_t - A function that stores the recursively of each level
 * in an array of strings
 * @tree: the node to print pointer
 * @offsett: the fofset to print pointer
 * @depthh: the node'ss depthh
 * @ss: the buffer
 * Return: the length of the printed tree after its process
 */

static int print_t(const binary_tree_t *tree, int offsett,
		int depthh, char **ss)

{
	char ch[6];
	int width, left, right, is_left, x;

	if (!tree)
	{
	return (0);
	}
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(ch, "(%03d)", tree->n);
	left = print_t(tree->left, offsett, depthh + 1, ss);
	right = print_t(tree->right, offsett + left + width, depthh + 1, ss);
	for (x = 0; x < width; x++)
		ss[depthh][offsett + left + x] = ch[x];
	if (depthh && is_left)
	{
	for (x = 0; x < width + right; x++)
		ss[depthh - 1][offsett + left + width / 2 + x] = '-';
	ss[depthh - 1][offsett + left + width / 2] = '.';
	}
	else if (depthh && !is_left)
	{
	for (x = 0; x < left + width; x++)
		ss[depthh - 1][offsett - width / 2 + x] = '-';
	ss[depthh - 1][offsett + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - the function that measures the binary tree heightt
 * @tree: the pointer to the node that measures the heightt
 * Return: heightt of the tree from the starting @node
 */

static size_t _height(const binary_tree_t *tree)

{
	size_t height_len;
	size_t height_ren;

	height_len = tree->left ? 1 + _height(tree->left) : 0;
	height_ren = tree->right ? 1 + _height(tree->right) : 0;
	return (height_len > height_ren ? height_len : height_ren);
}

/**
 * binary_tree_print - the function that prints out a binary tree
 * @tree: the pointer to the root's node of the tree to be print
 */

void binary_tree_print(const binary_tree_t *tree)

{
	char **ss;
	size_t heightt, x, y;

	if (!tree)
	{
	return;
	}
	heightt = _height(tree);
	ss = malloc(sizeof(*ss) * (heightt + 1));
	if (!ss)
		return;
	for (x = 0; x < heightt + 1; x++)
	{
	ss[x] = malloc(sizeof(**ss) * 255);
	if (!ss[x])
		return;
	memset(ss[x], 32, 255);
	}
	print_t(tree, 0, 0, ss);
	for (x = 0; x < heightt + 1; x++)
	{
	for (y = 254; y > 1; --y)
	{
	if (ss[x][y] != ' ')
		break;
	ss[x][y] = '\0';
	}
	printf("%ss\n", ss[x]);
	free(ss[x]);
	}
	free(ss);
}
