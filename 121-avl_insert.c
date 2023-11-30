#include "binary_trees.h"

size_t height(const binary_tree_t *tree);

avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **neww, int value);

int balance(const binary_tree_t *tree);

avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - A function that measures the binary tree's height.
 * @tree: the tree thats to be measured for its height.
 * Return: If NULL, return 0, else return its height.
 */

size_t height(const binary_tree_t *tree)

{
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance - A function that measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 * Return: if true return balance factor or NULL otherwise.
 */

int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - A function thats to nserts into
 * an AVL tree recursively a value
 * @tree: the AVL tree thats to insert the value into
 * @parent: The current working parent node.
 * @neww: stores the neww node.
 * @value: The value to be inserted.
 * Return: if true return value or NULL otherwise.
 */

avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **neww, int value)

{
	int brfactor;

	if (*tree == NULL)
	{
	return (*neww = binary_tree_node(parent, value));
	}
	if ((*tree)->n > value)
	{
	(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, neww, value);
	if ((*tree)->left == NULL)
		return (NULL);
	}
	else if ((*tree)->n < value)
	{
	(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, neww, value);
	if ((*tree)->right == NULL)
		return (NULL);
	}
	else
		return (*tree);
	brfactor = balance(*tree);
	if (brfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (brfactor < -1 && (*tree)->right->n < value)
	{
	*tree = binary_tree_rotate_left(*tree);
	}
	else if (brfactor > 1 && (*tree)->left->n < value)
	{
	(*tree)->left = binary_tree_rotate_left((*tree)->left);
	*tree = binary_tree_rotate_right(*tree);
	}
	else if (brfactor < -1 && (*tree)->right->n > value)
	{
	(*tree)->right = binary_tree_rotate_right((*tree)->right);
	*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - A function that inserts into an AVL
 * tree a value.
 * @tree: the AVL tree thats to insert the value into.
 * @value: The value.
 * Return: if true return the inserted node,
 * or if false return NULL.
 */

avl_t *avl_insert(avl_t **tree, int value)

{
	avl_t *neww = NULL;

	if (tree == NULL)
	{
	return (NULL);
	}
	if (*tree == NULL)
	{
	*tree = binary_tree_node(NULL, value);
	return (*tree);
	}
	avl_insert_recursive(tree, *tree, &neww, value);
	return (neww);
}
