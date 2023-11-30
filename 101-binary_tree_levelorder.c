#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);

void pop(levelorder_queue_t **head);

void free_queue(levelorder_queue_t *head);

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));

/**
 * create_node - A function that used to creates the neww
 * levelorder_queue_t node.
 * @node: The node for neww node to be contained in.
 * Return: If error, return NULL.
 *         Otherwise, return neww node.
 */

levelorder_queue_t *create_node(binary_tree_t *node)

{
	levelorder_queue_t *neww;

	neww = malloc(sizeof(levelorder_queue_t));
	if (neww == NULL)
	{
	return (NULL);
	}
	neww->node = node;
	neww->next = NULL;
	return (neww);
}

/**
 * free_queue - A function that frees up the
 * levelorder_queue_t queue.
 * @head: the queue's head pointer.
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
 * pint_push - A function that runs another function on the given binary tree
 * node and which pushes the children into the levelorder_queue_t queue.
 * @node: The node to be printed and pushed.
 * @head: the queue's head.
 * @tail: the queue's tail.
 * @func: the function node thats call/ on @node.
 * Description: Upon the malloc failure, just exits with the status
 * code of 1.
 */

void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *neww;

	func(node->n);
	if (node->left != NULL)
	{
	neww = create_node(node->left);
	if (neww == NULL)
	{
	free_queue(head);
	exit(1);
	}
	(*tail)->next = neww;
	*tail = neww;
	}
	if (node->right != NULL)
	{
	neww = create_node(node->right);
	if (neww == NULL)
	{
	free_queue(head);
	exit(1);
	}
	(*tail)->next = neww;
	*tail = neww;
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
 * binary_tree_levelorder - A function that uses the level-order traversal
 * traverses the binary tree.
 * @tree: the root node's pointer of the tree to be traversed.
 * @func: the function pointer to call out for each of the node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))

{
	levelorder_queue_t *headd, *taill;

	if (tree == NULL || func == NULL)
	{
	return;
	}
	headd = taill = create_node((binary_tree_t *)tree);
	if (headd == NULL)
	{
	return;
	}
	while (headd != NULL)
	{
	pint_push(headd->node, headd, &taill, func);
	pop(&headd);
	}
}
