#ifndef BINARY_TREES_H_
#define BINARY_TREES_H_

#include <stdio.h>

#include <stddef.h>

#include <string.h>

#include <stdlib.h>

/**
 * struct binary_tree_s - the structure of the binary tree node
 * @n: the int to be stored
 * @parent: the parent's node pointer
 * @left: the left child's node pointer
 * @right: the right child's node pointer
 */

struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s bst_t;

typedef struct binary_tree_s avl_t;

typedef struct binary_tree_s heap_t;

/**
 * struct levelorder_queue_s - the  structure function of the level's order
 * traversal queue.
 * @node: the binary tree's node.
 * @next: The next node to the move to in the binary tree.
 */

typedef struct levelorder_queue_s
{
	binary_tree_t *node;
	struct levelorder_queue_s *next;
} levelorder_queue_t;

/**
 * struct node_s - A function of a singly linked list
 * @node: the const binary tree's node
 * @next: the next node
 */

typedef struct node_s

{
	const binary_tree_t *node;
	struct node_s *next;
} lla;

void binary_tree_print(const binary_tree_t *);

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

void binary_tree_delete(binary_tree_t *tree);

int binary_tree_is_leaf(const binary_tree_t *node);

int binary_tree_is_root(const binary_tree_t *node);

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

size_t binary_tree_height(const binary_tree_t *tree);

size_t binary_tree_depth(const binary_tree_t *tree);

size_t binary_tree_size(const binary_tree_t *tree);

size_t binary_tree_leaves(const binary_tree_t *tree);

size_t binary_tree_nodes(const binary_tree_t *tree);

int binary_tree_balance(const binary_tree_t *tree);

int binary_tree_is_full(const binary_tree_t *tree);

int binary_tree_is_perfect(const binary_tree_t *tree);

binary_tree_t *binary_tree_sibling(binary_tree_t *node);

binary_tree_t *binary_tree_uncle(binary_tree_t *node);

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

int binary_tree_is_complete(const binary_tree_t *tree);

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

int binary_tree_is_bst(const binary_tree_t *tree);

bst_t *bst_insert(bst_t **tree, int value);

bst_t *array_to_bst(int *array, size_t size);

bst_t *bst_search(const bst_t *tree, int value);

bst_t *bst_remove(bst_t *root, int value);

int binary_tree_is_avl(const binary_tree_t *tree);

avl_t *avl_insert(avl_t **tree, int value);

avl_t *array_to_avl(int *array, size_t size);

avl_t *avl_remove(avl_t *root, int value);

avl_t *sorted_array_to_avl(int *array, size_t size);

int binary_tree_is_heap(const binary_tree_t *tree);

heap_t *heap_insert(heap_t **root, int value);

heap_t *array_to_heap(int *array, size_t size);

int heap_extract(heap_t **root);

int *heap_to_sorted_array(heap_t *heap, size_t *size);

#endif /* BINARY_TREES_H */
