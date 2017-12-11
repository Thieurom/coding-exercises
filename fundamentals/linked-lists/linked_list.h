/*
 * linked_list.h
 * Header for Link List data structure
 */


#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdbool.h>


/*
 * Node (list element) definition
 */
typedef struct LinkedListNode {
    int value;
    struct LinkedListNode *next;
} Node;


/*
 * List definition
 */
typedef struct LinkedList {
    int size;
    Node *head;
    Node *tail;
} List;


void list_init(List *list);
void list_insert_next(List *list, Node *node, int value);
void list_remove_next(List *list, Node *node);
void list_remove_all(List *list);
int list_size(List *list);
Node *list_head(List *list);
Node *list_tail(List *list);
Node *list_next(Node *node);
int list_value(Node *node);
bool list_is_empty(List *list);
void list_reverse(List *list);

#endif  /* LINKED_LIST_H */
