#include <assert.h>
#include "linked_list.h"

void test_list_insert_next() {
    List list;
    Node *node;

    list_init(&list);
    assert(list_size(&list) == 0);

    list_insert_next(&list, NULL, 100);
    assert(list_size(&list) == 1);
    assert((list_head(&list))->value == 100);

    list_insert_next(&list, NULL, 200);
    assert(list_size(&list) == 2);
    assert((list_head(&list))->value == 200);

    node = (list_head(&list))->next;
    list_insert_next(&list, node, 300);
    assert(list_size(&list) == 3);
    assert((list_tail(&list))->value == 300);

    list_destroy(&list);
}

void test_list_remove_next() {
    List list;

    list_init(&list);
    list_insert_next(&list, NULL, 100);
    list_insert_next(&list, NULL, 200);
    list_insert_next(&list, NULL, 300);
    assert(list_size(&list) == 3);

    list_remove_next(&list, NULL);
    assert(list_size(&list) == 2);

    list_remove_next(&list, list_head(&list));
    assert(list_size(&list) == 1);

    list_destroy(&list);
}


int main() {
    test_list_insert_next();
    test_list_remove_next();

    return 0;
}
