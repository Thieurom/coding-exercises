/*
 * bst.h
 * Header for Binary Search Tree
 */

#ifndef BST_H
#define BST_H

typedef struct Tree {
    int value;
    struct Tree *left;
    struct Tree *right;
} Tree;

void tree_insert(Tree **tree, const int value); 
void tree_delete(Tree **tree, const int value);
Tree *tree_search(Tree *tree, const int value);
Tree *tree_minimum(Tree *tree);
Tree *tree_maximum(Tree *tree);
int tree_nodes(Tree *tree);
void tree_print(Tree *tree);

#endif
