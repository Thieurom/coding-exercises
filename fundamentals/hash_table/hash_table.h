/*
 * hash_table.h
 * Header for Hash Table data structure
 */



#ifndef HTABLE_H
#define HTABLE_H

#include <stdlib.h>
#include "linked_list.h"

typedef struct Entry {
    char *key;
    char *value;
} Entry;

typedef struct Hashtable {
    int buckets;
    int size;
    List *table;
} Hashtable;

Hashtable *hashtable_create(int buckets);
void hashtable_destroy(Hashtable *ht);
void hashtable_insert(Hashtable *ht, char *key, char *value);
void hashtable_remove(Hashtable *ht, char *key);
char *hashtable_value(Hashtable *ht, char *key);
int hash(char *key);
int match(const char *s1, const char *s2);
#define hashtable_size(ht) ((ht)->size)

#endif    /* HTABLE_H */
