#include "binary_trees.h"

/**
 * bal - A function that measures the AVL's balance factor
 * @tree: the tree to be searched through
 * Return: its balanced factor
 */

void bal(avl_t **tree)

{
	int balcvale;

	if (tree == NULL || *tree == NULL)
	{
	return;
	}
	if ((*tree)->left == NULL && (*tree)->right == NULL)
	{
	return;
	}
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	balcvale =
		binary_tree_balance((const binary_tree_t *)*tree);
	if (balcvale > 1)
		*tree =
			binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balcvale < -1)
		*tree =
			binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - A function that gets the next successor which means the
 * min node thats in the right of the subtree
 * @node: tree to be searched or check
 * Return: if true return the min value or 0 if otherwise
 */

int successor(bst_t *node)

{
	int lefty = 0;

	if (node == NULL)
	{
	return (0);
	}
	else
	{
	lefty = successor(node->left);
	if (lefty == 0)
	{
	return (node->n);
	}
	return (lefty);
	}

}
/**
 * remove_type - A function that removes from a tree a node thats
 * depending of its children
 * @root: node to remove
 * Return: if false (0) or if true (value)
 */

int remove_type(bst_t *root)

{
	int newr_val = 0;

	if (!root->left && !root->right)
	{
	if (root->parent->right == root)
		root->parent->right = NULL;
	else
		root->parent->left = NULL;
	free(root);
	return (0);
	}
	else if ((!root->left && root->right) ||
		       (!root->right && root->left))
	{
	if (!root->left)
	{
	if (root->parent->right == root)
		root->parent->right = root->right;
	else
		root->parent->left = root->right;
	root->right->parent = root->parent;
	}
	if (!root->right)
	{
	if (root->parent->right == root)
		root->parent->right = root->left;
	else
		root->parent->left = root->left;
	root->left->parent = root->parent;
	}
	free(root);
	return (0);
	}
	else
	{
	newr_val = successor(root->right);
	root->n = newr_val;
	return (newr_val);
	}
}

/**
 * bst_remove - A function that only remove from a BST
 * tree a node.
 * @root: the root of this tree
 * @value: the node with this particular value to be removed
 * Return: if true (the tree changed) or IF False (NULL)
 */

bst_t *bst_remove(bst_t *root, int value)

{
	int typees = 0;

	if (root == NULL)
	{
	return (NULL);
	}
	if (value < root->n)
	{
	bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
	bst_remove(root->right, value);
	}
	else if (value == root->n)
	{
	typees = remove_type(root);
	if (typees != 0)
	{
	bst_remove(root->right, typees);
	}}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - A function that removes from the AVL tree's a node
 * @root: the root of the ALV tree
 * @value: node THATS with this particular value to be removed
 * Return: if true (the tree changed) or if false(NULL)
 */

avl_t *avl_remove(avl_t *root, int value)

{
	avl_t *roots_avl = (avl_t *) bst_remove((bst_t *) root, value);

	if (roots_avl == NULL)
	{
	return (NULL);
	}
	bal(&roots_avl);
	return (roots_avl);
}

