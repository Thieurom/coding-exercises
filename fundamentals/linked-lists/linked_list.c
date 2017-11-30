/*
 * linked_list.c
 * Implementation for Link List
 */

#include <stdlib.h>
#include "linked_list.h"


/*
 * Initialize the linked list specified by `list`.
 * Time complexity is O(1).
 */
List *list_create() {
    List *list;

    if ((list = (List *) (malloc(sizeof(List)))) == NULL)
        exit(EXIT_FAILURE);

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}


/*
 * Destroy the list
 * Time complexity is O(n), where n is the number of nodes in the list.
 */
void list_destroy(List *list) {
    void *data;

    while (list_size(list) > 0) {
        list_remove_next(list, NULL, (void **)&data);
    }
}


/*
 * Insert new node with given data, right after to given node.
 * If insert at the head of the list, pass NULL as second parameter.
 * Time complexity is O(1)
 */
void list_insert_next(List *list, Node *node, void *data) {
    Node *new_node;

    if ((new_node = (Node *)malloc(sizeof(Node))) == NULL)
        exit(EXIT_FAILURE);

    new_node->data = data;

    if (node == NULL) {
        // insert at the head of the list
        if (list_size(list) == 0)
            // if the list is currently empty, new node will be the list's tail
            list->tail = new_node;

        new_node->next = list->head;
        list->head = new_node;
    
    } else {
        // insert at other than the head of the list
        if (node->next == NULL)
            // if insert after the last node of the list, update the tail
            list->tail = new_node;

        new_node->next = node->next;
        node->next = new_node;
    }

    list->size++;
}


/*
 * Remove the node after the specified node.
 * Pass NULL as second parameter if remove the node at the head of the list.
 * Time complexity is O(1).
 */
void list_remove_next(List *list, Node *node, void **data) {
    Node *old_node;

    // remove from an empty list
    if (list_size(list) == 0)
        return;

    if (node == NULL) {
        // remove from the head of the list
        *data = list->head->data;
        old_node = list->head;
        list->head = list->head->next;

        if (list_size(list) == 1)
            list->tail = NULL;

    } else {
        // remove from other than the head
        *data = node->next->data;
        old_node = node->next;
        node->next = node->next->next;

        if (node->next == NULL)
            list->tail = node;
    }

    free(old_node);
    list->size--;
}


/*
 * Reverse the list
 * Time complexity is O(n)
 */
void list_reverse(List *list) {
    Node *prev = NULL;
    Node *current = list->head;
    Node *next;

    list->tail = list->head;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list->head = prev;
}


/*
 * Return the size of the list
 */
int list_size(List *list) {
    return list->size;
}


/*
 * Return the list's head
 */
Node *list_head(List *list) {
    return list->head;
}


/*
 * Return the list's tail
 */
Node *list_tail(List *list) {
    return list->tail;
}


/*
 * Return the data of the specified node
 */
void *list_data(Node *node) {
    return node->data;
}
