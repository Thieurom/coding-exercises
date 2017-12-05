/*
 * bst.c
 * Implementation for Binary Search Tree
 */


#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

/*
 * Insert a new node with specified value in to the tree
 * Time complexity is O(h), h is the height of the tree
 */
void tree_insert(Tree **tree, const int value) {
    Tree *t;  // temporary pointer

    if (*tree == NULL) {
        if ((t = (Tree *) malloc(sizeof(Tree))) == NULL)
            exit(EXIT_FAILURE);

        t->value = value;
        t->left = t->right = NULL;
        *tree = t;
        return;
    }

    if (value < (*tree)->value)
        tree_insert(&((*tree)->left), value);
    else if (value > (*tree)->value)
        tree_insert(&((*tree)->right), value);
}


/*
 * Delete a node from the tree
 * Time complexity is O(h), h is the height of the tree
 */
void tree_delete(Tree **tree, const int value) {
    Tree *t;  // temporary pointer

    if (*tree != NULL) {
        if (value < ((*tree)->value)) {
            // the node is on left subtree
            tree_delete(&((*tree)->left), value);

        } else if (value > ((*tree)->value)) {
            // the node is on right subtree
            tree_delete(&((*tree)->right), value);

        } else {
            if (((*tree)->left == NULL) && ((*tree)->right == NULL)) {
                // delete tree without children
                free(*tree);
                *tree = NULL;

            } else if ((*tree)->left == NULL) {
                // delete tree with only right child
                t = *tree;
                *tree = (*tree)->right;
                free(t);

            } else if ((*tree)->right == NULL) {
                // delete tree with only left child
                t = *tree;
                *tree = (*tree)->left;
                free(t);

            } else {
                // delete with two children
                t = tree_minimum((*tree)->right);
                (*tree)->value = t->value;
                free(t);
                t = NULL;
            }
        }
    }
}


/*
 * Search the value in the tree
 * Time complexity is O(h), h is the height of the tree
 */
Tree *tree_search(Tree *tree, const int value) {
    if (tree == NULL) return NULL;
    
    if (tree->value == value) return tree;

    if (value < tree->value)
        return tree_search(tree->left, value);
    else
        return tree_search(tree->right, value);
}


/*
 * Find the minimum value in the tree
 * Time complexity is O(h), h is the height of the tree
 */
Tree *tree_minimum(Tree *tree) {
    Tree *min;

    if (tree == NULL) return NULL;

    min = tree;
    while (min->left != NULL)
        min = min->left;

    // for (min = tree; min->left != NULL; min = min->left)
    // ;

    return min;
}


/*
 * Find the maximum in the tree
 * Time complexity is O(h), h is the height of the tree
 */
Tree *tree_maximum(Tree *tree) {
    Tree *max;

    if (tree == NULL) return tree;

    max = tree;
    while (max->right != NULL)
        max = max->right;

    return max;
}


/*
 * Return the number of tree's nodes
 * Time complexity is O(n), where n is the number of nodes
 */
int tree_nodes(Tree *tree) {
    if (tree == NULL)
        return 0;

    return 1 + tree_nodes(tree->left) + tree_nodes(tree->right);
}


/*
 * Traverse the tree and print all nodes' values
 * Time complexity is O(n), where n is the number of nodes
 */
void tree_print(Tree *tree) {
    if (tree != NULL) {
        tree_print(tree->left);
        printf("%d ", tree->value);
        tree_print(tree->right);
    }

    printf("\n");
}
