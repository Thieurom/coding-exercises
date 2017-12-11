/*
 * test_linked_list.c
 * Test for Linked List
 */


#include <assert.h>
#include <stdio.h>
#include "linked_list.h"


int main() {
    List list;
    Node *node;

    list_init(&list);
    assert(list_is_empty(&list) == true);

    // insert the first node
    list_insert_next(&list, NULL, 100);           // 100
    assert(list_is_empty(&list) == false);
    assert(list_size(&list) == 1);
    assert(list_value(list_head(&list)) == 100);
    assert(list_value(list_tail(&list)) == 100);

    node = list_head(&list);                      // [100]
    // insert new node at the end of the list
    list_insert_next(&list, node, 200);           // 100 -> 200
    assert(list_size(&list) == 2);
    assert(list_value(list_tail(&list)) == 200);

    // insert new node at the middle of the list
    list_insert_next(&list, node, 300);           // 100 -> 300 -> 200
    assert(list_size(&list) == 3);
    list_insert_next(&list, node, 400);           // 100 -> 400 -> 300 -> 200
    assert(list_size(&list) == 4);

    // remove node at the head of the list
    list_remove_next(&list, NULL);                // 400 -> 300 -> 200
    assert(list_size(&list) == 3);
    assert(list_value(list_head(&list)) == 400);

    node = list_next(list_head(&list));           // [300]
    // remove node at the end of the list
    list_remove_next(&list, node);                // 400 -> 300
    assert(list_size(&list) == 2);
    assert(list_value(list_tail(&list)) == 300);

    // reverse
    list_reverse(&list);                          // 300 -> 400
    assert(list_value(list_head(&list)) == 300);
    assert(list_value(list_tail(&list)) == 400);

    // remove all
    list_remove_all(&list);
    assert(list_is_empty(&list) == true);

    printf("Tested OK.\n");

    return 0;
}
