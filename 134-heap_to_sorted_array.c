#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify_down - Fixes a Max Heap tree by moving a node down
 * @node: Pointer to the node to move down
 *
 * Return: Pointer to the new position of the node
 */
heap_t *heapify_down(heap_t *node)
{
    heap_t *largest = node;
    heap_t *left = node->left;
    heap_t *right = node->right;

    if (left && left->n > largest->n)
        largest = left;

    if (right && right->n > largest->n)
        largest = right;

    if (largest != node)
    {
        int temp = node->n;
        node->n = largest->n;
        largest->n = temp;
        return (heapify_down(largest));
    }

    return (node);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last, *parent;

    if (!root || !*root)
        return (0);

    value = (*root)->n;

    if (binary_tree_size(*root) == 1)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    last = *root;
    while (last->right)
    {
        parent = last;
        last = last->right;
        if (last->left)
            parent = last;
    }

    (*root)->n = last->n;

    if (parent->left == last)
        parent->left = NULL;
    else
        parent->right = NULL;

    free(last);

    *root = heapify_down(*root);

    return (value);
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array;
    size_t i = 0;

    if (!heap || !size)
        return (NULL);

    *size = binary_tree_size(heap);

    array = malloc(sizeof(int) * *size);
    if (!array)
        return (NULL);

    while (heap)
    {
        array[i++] = heap_extract(&heap);
    }

    return (array);
}
