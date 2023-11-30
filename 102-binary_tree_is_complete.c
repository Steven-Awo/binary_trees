#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);

int binary_tree_is_complete(const binary_tree_t *tree);

void free_queue(levelorder_queue_t *head);

void pop(levelorder_queue_t **head);

void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);

/**
 * create_node - A function that creates the neww
 * levelorder_queue_t node.
 * @node: The node for the neww node to be contained in.
 * Return: If error true, return NULL.
 *         Otherwise, return the neww node.
 */

levelorder_queue_t *create_node(binary_tree_t *node)

{
	levelorder_queue_t *neww;

	neww = malloc(sizeof(levelorder_queue_t));
	if (neww == NULL)
		return (NULL);

	neww->node = node;
	neww->next = NULL;

	return (neww);
}

/**
 * free_queue - A function that frees the
 * levelorder_queue_t queue.
 * @head: the queue's head.
 */

void free_queue(levelorder_queue_t *head)

{
	levelorder_queue_t *tmpr;

	while (head != NULL)
	{
		tmpr = head->next;
		free(head);
		head = tmpr;
	}
}

/**
 * pop - A function that pops or removes the head of the
 * levelorder_queue_t queue.
 * @head: the queue's head.
 */

void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmpr;

	tmpr = (*head)->next;
	free(*head);
	*head = tmpr;
}

/**
 * push - A function that pushes to the back the node of a
 * levelorder_queue_t queue.
 * @node: the node to be printed and pushed.
 * @head: the head's double pointer of the queue.
 * @tail: the tail's double pointer of the queue.
 * Description: Upon the malloc's failure, then exits with a
 * status code of 1.
 */

void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)

{
	levelorder_queue_t *neww;

	neww = create_node(node);
	if (neww == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = neww;
	*tail = neww;
}

/**
 * binary_tree_is_complete - A function that checks if the binary tree
 * is actually complete.
 * @tree: the root node's pointer of the tree to be traversed.
 * Return: If NULL or is not complete, return 0.
 *         Otherwise, return 1.
 * Description: * Description: Upon the malloc's failure, then exits with a
 * status code of 1.
 */

int binary_tree_is_complete(const binary_tree_t *tree)

{
	levelorder_queue_t *headd, *taills;
	unsigned char flaggs = 0;

	if (tree == NULL)
	{
	return (0);
	}
	headd = taills = create_node((binary_tree_t *)tree);
	if (headd == NULL)
	{
	exit(1);
	}
	while (headd != NULL)
	{
	if (headd->node->left != NULL)
	{
	if (flaggs == 1)
	{
	free_queue(headd);
	return (0);
	}
	push(headd->node->left, headd, &taills);
	}
	else
		flaggs = 1;
	if (headd->node->right != NULL)
	{
	if (flaggs == 1)
	{
	free_queue(headd);
	return (0);
	}
	push(headd->node->right, headd, &taills);
	}
	else
		flaggs = 1;
	pop(&headd);
	}
	return (1);
}
