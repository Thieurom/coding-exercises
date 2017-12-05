/*
 * test_bst.c
 * Test for Binary Search Tree
 */


#include <stdlib.h>
#include <assert.h>
#include "bst.h"


int main() {
    Tree *tree = NULL;

    tree_insert(&tree, 1);
    tree_insert(&tree, 2);
    tree_insert(&tree, 3);
    tree_insert(&tree, 4);
    tree_insert(&tree, 5);

    assert(tree_nodes(tree) == 5);
    assert((tree_minimum(tree))->value == 1);
    assert((tree_maximum(tree))->value == 5);
    assert((tree_search(tree, 1))->value == 1);
    assert((tree_search(tree, 2))->value == 2);

    tree_delete(&tree, 1);
    tree_delete(&tree, 3);
    tree_delete(&tree, 5);

    assert(tree_nodes(tree) == 2);
    assert((tree_minimum(tree))->value == 2);
    assert((tree_maximum(tree))->value == 4);

    return 0;
}
