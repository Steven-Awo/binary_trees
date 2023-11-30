#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);

bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);

bst_t *bst_delete(bst_t *root, bst_t *node);

bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - A function that returns the binary search
 * tree's minimum value .
 * @root: the root node's pointer of the BST to be searched for.
 * Return: root
 */

bst_t *inorder_successor(bst_t *root)

{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: the root node's pointer of the BST.
 * @node: the node's pointer to delete from the BST.
 * Return: the new root after its deletion.
 */

bst_t *bst_delete(bst_t *root, bst_t *node)

{
	bst_t *parental = node->parent, *successors = NULL;

	if (node->left == NULL)
	{
	if (parental != NULL &&
			parental->left == node)
	{
	parental->left = node->right;
	}
	else if (parental != NULL)
		parental->right = node->right;
	if (node->right != NULL)
		node->right->parent = parental;
	free(node);
	return (parental == NULL ? node->right : root);
	}
	if (node->right == NULL)
	{
	if (parental != NULL &&
			parental->left == node)
	{
	parental->left = node->left;
	}
	else if (parental != NULL)
		parental->right = node->left;
	if (node->left != NULL)
		node->left->parent = parental;
	free(node);
	return (parental == NULL ? node->left : root);
	}
	successors = inorder_successor(node->right);
	node->n = successors->n;
	return (bst_delete(root, successors));
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @root: the root node's pointer of the BST to remove a node from.
 * @node: the current node's pointer in the BST.
 * @value: The value to remove from the BST.
 * Return: the root node's pointer after deletion.
 */

bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)

{
	if (node != NULL)
	{
	if (node->n == value)
	{
	return (bst_delete(root, node));
	}
	if (node->n > value)
	{
	return (bst_remove_recursive(root, node->left, value));
	}
	return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - A function that removes from the binary search
 * tree a node.
 * @root: the root node's pointer of the BST just to remove
 * a node from.
 * @value: The value to be remove in the BST.
 * Return: the new root's node after its deletion.
 * Description: If node thats to be deleted actually has two children,
 * it is then replaced with its own first in-order successors.
 */

bst_t *bst_remove(bst_t *root, int value)

{
	return (bst_remove_recursive(root,
				root, value));
}
