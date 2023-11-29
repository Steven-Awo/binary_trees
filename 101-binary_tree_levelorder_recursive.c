#include "binary_trees.h"

lla *append(lla *head, const binary_tree_t *btnode);

void free_list(lla *head);

lla *get_children(lla *head, const binary_tree_t *parent);

void levels_rec(lla *head, void (*func)(int));

/**
 * binary_tree_levelorder - A function that uses the level-order traversal
 * to go through the binary tree.
 * @tree: the root node's poiter of the bin tree to be traverse.
 * @func: a function pointer used to call each node.
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))

{
	lla *childrenn = NULL;

	func(tree->n);
	childrenn = get_children(childrenn,
			tree);
	levels_rec(childrenn,
			func);
	free_list(childrenn);
}

/**
 * levels_rec - A function that calls another func for all
 * the nodes at each level.
 * @head: linked list's head with the nodes for one level.
 * @func: a function pointer to call for each of the node.
 * Return: void
 */

void levels_rec(lla *head, void (*func)(int))

{
	lla *childrenn = NULL, *currt = NULL;

	if (!head)
	{
	return;
	}
	for (currt = head; currt != NULL; currt = currt->next)
	{
	func(currt->node->n);
	childrenn = get_children(childrenn,
			currt->node);
	}
	levels_rec(childrenn,
			func);
	free_list(childrenn);
}

/**
 * get_children - A function that appends the childrenn of the
 * parent to the linked list.
 * @head: linked list's head where the childrenn will then be appended.
 * @parent: node's pointer to whose childrenn are to be appended.
 * Return: Pointer to head of linked list of childrenn.
 */

lla *get_children(lla *head, const binary_tree_t *parent)

{
	if (parent->left)
	{
	head = append(head,
			parent->left);
	}
	if (parent->right)
	{
	head = append(head,
			parent->right);
	}
	return (head);
}

/**
 * append - A function that adds at the end a neww node to a linkedlist
 * @head: head's pointer for linked list
 * @btnode: the const binary tree's node to be append
 * Return: head if true, or NULL if false
 */

lla *append(lla *head, const binary_tree_t *btnode)

{
	lla *neww = NULL, *lastt = NULL;

	neww = malloc(sizeof(*neww));
	if (neww)
	{
	neww->node = btnode;
	neww->next = NULL;
	if (!head)
	{
	head = neww;
	}
	else
	{
	lastt = head;
	while (lastt->next)
		lastt = lastt->next;
	lastt->next = neww;
	}
	}
	return (head);
}

/**
 * free_list - A function that frees all nodes thats in a linked list
 * @head: the head's pointer of the list_t linked list
 * Return: void
 */

void free_list(lla *head)

{
	lla *potr = NULL;

	while (head)
	{
	potr = head->next;
	free(head);
	head = potr;
	}
}
