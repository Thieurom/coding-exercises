/*
 * hash_table.c
 * Implementation for Hash Table data structure
 */


#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#include "hash_table.h"


/*
 * Initialize a hash table.
 * Time complexity is O(m), where m is the number of buckets.
 */
Hashtable *hashtable_create(int buckets) {
    Hashtable *ht;
    int i;

    if ((ht = (Hashtable *) malloc(sizeof(Hashtable))) == NULL)
        exit(EXIT_FAILURE);

    ht->buckets = buckets;

    // allocate storage
    if ((ht->table = (List *) (malloc(buckets * sizeof(List)))) == NULL)
        exit(EXIT_FAILURE);

    // init the buckets
    for (i = 0; i < ht->buckets; i++) {
        ht->table = list_create();
        ht->table++;
    }

        ht->table -= (ht->buckets - 1);

    ht->size = 0;

    return ht;
}


/*
 * Destroy the hash table
 * Time complexity is O(m), where m is the number of buckets.
 */
void hashtable_destroy(Hashtable *ht) {
    int i;

    for (i = 0; i < ht->buckets; i++)
        list_destroy(ht->table + i);

    free(ht->table);
}


/*
 * Insert new key-value pair in to hash table.
 * If the key exists, update the with given value, else insert new pair.
 * Time complexity is O(n/m), where n is the number of entries and m is
 * the number of buckets.
 * Assuming uniform hashing, O(n/m) = O(load-factor) = O(1)
 */
void hashtable_insert(Hashtable *ht, char *key, char *value) {
    Entry *entry;
    Node *node;
    int bucket;

    bucket = hash(key) % ht->buckets;
    node = list_head(ht->table + bucket);

    // traverse the bucket to check if the key already exists
    while (node != NULL) {
        entry = node->data;

        if (match(key, entry->key)) {
            // update the value for the existing key
            entry->value = value;
            return;
        }

        node = node->next;
    }

    // allocate storage for new key-value pair
    if ((entry = (Entry *) malloc(sizeof(Entry))) == NULL)
        exit(EXIT_FAILURE);

    entry->key = key;
    entry->value = value;

    // insert the entry into the head of the bucket
    list_insert_next(ht->table + bucket, NULL, entry);
    
    // update size
    ht->size++;
}


/*
 * Remove element from hash table with specified key
 * Time complexity is O(n/m), where n is the number of entries and m is
 * the number of buckets.
 * Assuming uniform hashing, O(n/m) = O(load-factor) = O(1)
 */
void hashtable_remove(Hashtable *ht, char *key) {
    Entry *entry;
    Node *prev, *node;
    void *temp;
    int bucket;

    bucket = hash(key) % ht->buckets;
    prev = NULL;
    node = list_head(ht->table + bucket);

    // traverse the bucket find the target entry
    while (node != NULL) {
        entry = node->data;

        if (match(key, entry->key)) {
            list_remove_next(ht->table + bucket, prev, (void **)&temp);
            ht->size--;
            return;
        }

        prev = node;
        node = node->next;
    } 
}


/*
 * Search the value by the given key, return NULL if not found
 * Time complexity is O(1)
 */
char *hashtable_value(Hashtable *ht, char *key) {
    Entry *entry;
    Node *node;
    int bucket;

    bucket = hash(key) % ht->buckets;
    node = list_head(ht->table + bucket);

    // traverse the bucket to find the target entry
    while (node != NULL) {
        entry = node->data;

        if (match(key, entry->key))
            return entry->value;

        node = node->next;
    }

    return NULL;
}


/*
 * Compare 2 strings, return 1 if match, 0 otherwise
 */
int match(const char *s1, const char *s2) {
    if (strcmp(s1, s2) == 0)
        return 1;
    else
        return 0;
}


/*
 * Universal hash function for string
 */
int hash(char *s) {
    int coding = 0;

    while (*s) {
        coding = coding * 31 + *s;
        s++;
    }

    return coding;
}
