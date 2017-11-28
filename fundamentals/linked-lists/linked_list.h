/*
 * linked_list.h
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

/*
 * Structure for list node
 */
typedef struct Node {
    int value;
    struct Node *next;
} Node;


/*
 * Structure for list
 */
typedef struct List {
    int size;
    Node *head;
    Node *tail;
} List;


void list_init(List *list);
void list_destroy(List *list);
void list_insert_next(List *list, Node *node, int value);
void list_remove_next(List *list, Node *node);
int list_size(List *list);
Node *list_head(List *list);
Node *list_tail(List *list);

#endif
