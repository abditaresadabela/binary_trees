#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* Basic binary tree structure */
typedef struct binary_tree_s binary_tree_t;
struct binary_tree_s
{
    int n;
    binary_tree_t *parent;
    binary_tree_t *left;
    binary_tree_t *right;
};

/* Binary search tree structure */
typedef struct bst_s bst_t;
struct bst_s
{
    binary_tree_t *tree;
    bst_t *left;
    bst_t *right;
};

/* AVL tree structure */
typedef struct avl_s avl_t;
struct avl_s
{
    binary_tree_t *tree;
    int balance;
    avl_t *left;
    avl_t *right;
};

/* Max Binary Heap structure */
typedef struct heap_s heap_t;
struct heap_s
{
    binary_tree_t *root;
    size_t size;
};

/* Function prototypes */

/* Binary tree function prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);

/* Binary search tree function prototypes */
bst_t *bst_insert(bst_t **tree, int value);

/* AVL tree function prototypes */
avl_t *avl_insert(avl_t **tree, int value);

/* Max Binary Heap function prototypes */
heap_t *heap_create(void);
binary_tree_t *heap_insert(heap_t *heap, int value);
void heap_delete(heap_t *heap);
void heap_extract(heap_t *heap);
void heapify_down(heap_t *heap, binary_tree_t *node);
void heapify_up(heap_t *heap, binary_tree_t *node);
void heap_delete_tree(binary_tree_t *node);
int *heap_to_sorted_array(heap_t *heap, size_t *size);

#endif /* BINARY_TREES_H */ 
