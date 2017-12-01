/*
 * test_hash_table.c
 * Test for Hash Table
 */


#include <assert.h>
#include "hash_table.h"

void test_hashtable_insert() {
    Hashtable *ht;
    char *k1 = "David", *v1 = "123";
    char *k2 = "Peter", *v2 = "456";

    ht = hashtable_create(7);
    hashtable_insert(ht, k1, v1);
    assert(hashtable_size(ht) == 1);

    hashtable_insert(ht, k2, v2);
    assert(hashtable_size(ht) == 2);
}

void test_hashtable_value() {
    Hashtable *ht;
    char *k1 = "David", *v1 = "123";
    char *k2 = "Peter", *v2 = "456";

    ht = hashtable_create(7);
    hashtable_insert(ht, k1, v1);
    hashtable_insert(ht, k2, v2);

    assert(hashtable_value(ht, k1) == v1);
    assert(hashtable_value(ht, k2) == v2);
}

void test_hashtable_remove() {
    Hashtable *ht;
    char *k1 = "David", *v1 = "123";
    char *k2 = "Peter", *v2 = "456";

    ht = hashtable_create(7);
    hashtable_insert(ht, k1, v1);
    hashtable_insert(ht, k2, v2);

    hashtable_remove(ht, k1);
    assert(hashtable_size(ht) == 1);

    hashtable_remove(ht, k2);
    assert(hashtable_size(ht) == 0);
}


int main() {
    test_hashtable_insert();
    test_hashtable_value();
    test_hashtable_remove();

    return 0;
}
