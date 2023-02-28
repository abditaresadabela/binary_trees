#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *current;

    if (!root)
        return (NULL);

    /* Create new node */
    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    /* If root is NULL, new node becomes root */
    if (!*root)
        return (*root = new_node);

    /* Traverse tree to find appropriate place to insert new node */
    current = *root;
    while (current)
    {
        /* If value of new node is greater than value of current node, swap */
        if (value > current->n)
        {
            new_node->n = current->n;
            current->n = value;
        }

        /* If current node is a leaf node, insert new node as its child */
        if (!current->left)
            return (current->left = new_node);
        else if (!current->right)
            return (current->right = new_node);

        /* Traverse tree in top-down fashion */
        if (!current->left->left || !current->left->right)
            current = current->left;
        else if (!current->right->left || !current->right->right)
            current = current->right;
        else
            current = current->left;
    }

    return (NULL);
}
