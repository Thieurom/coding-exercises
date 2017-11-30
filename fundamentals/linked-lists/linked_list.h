/*
 * linked_list.h
 * Header for Link List data structure
 */


#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

/*
 * Node (list element) definition
 */
typedef struct Node {
    void *data;
    struct Node *next;
} Node;


/*
 * List definition
 */
typedef struct List {
    int size;
    Node *head;
    Node *tail;
} List;


List *list_create();
void list_destroy(List *list);
void list_insert_next(List *list, Node *node, void *data);
void list_remove_next(List *list, Node *node, void **data);
void list_reverse(List *list);
int list_size(List *list);
Node *list_head(List *list);
Node *list_tail(List *list);
void *list_data(Node *node);

#endif
