#include <assert.h>
#include "linked_list.h"

void test_list_insert_next() {
    List *list;
    Node *node;
    int i1 = 100, i2 = 200, i3 = 300;

    list = list_create();
    assert(list_size(list) == 0);

    list_insert_next(list, NULL, &i1);
    assert(list_size(list) == 1);
    assert((list_head(list))->data == &i1);

    list_insert_next(list, NULL, &i2);
    assert(list_size(list) == 2);
    assert((list_head(list))->data == &i2);

    node = (list_head(list))->next;
    list_insert_next(list, node, &i3);
    assert(list_size(list) == 3);
    assert((list_tail(list))->data == &i3);

    list_destroy(list);
}

void test_list_remove_next() {
    List *list;
    void *data;
    int i1 = 100, i2 = 200, i3 = 300;

    list = list_create();
    list_insert_next(list, NULL, &i1);
    list_insert_next(list, NULL, &i2);
    list_insert_next(list, NULL, &i3);
    assert(list_size(list) == 3);

    list_remove_next(list, NULL, (void **)&data);
    assert(list_size(list) == 2);

    list_remove_next(list, list_head(list), (void **)&data);
    assert(list_size(list) == 1);

    list_destroy(list);
}

void test_list_reverse() {
    List *list;
    int i1 = 100, i2 = 200, i3 = 300;

    list = list_create();
    list_insert_next(list, NULL, &i1);
    list_insert_next(list, NULL, &i2);
    list_insert_next(list, NULL, &i3);
    assert((list_head(list))->data == &i3);
    assert((list_tail(list))->data == &i1);

    list_reverse(list);
    assert((list_head(list))->data == &i1);
    assert((list_tail(list))->data == &i3);

    list_destroy(list);
}


int main() {
    test_list_insert_next();
    test_list_remove_next();
    test_list_reverse();

    return 0;
}
