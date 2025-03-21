/**
 * -------------------------------------
 * @file  hash.c
 * file description
 * -------------------------------------
 * @author HunterLin, 169061939, linx1939@mylaurier
 *
 * @version 2025-02-28
 *
 * -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

HNODE *hashtable_search(HASHTABLE *ht, char *name)
{
    // your code
    if (!ht || !name)
    {
        return NULL;
    }

    // Calculate the Hash value
    int index = hash(name, ht->size);
    HNODE *current = ht->hna[index];

    while (current)
    {
        // Find the node with the same name
        if (strcmp(current->data.name, name) == 0)
        {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

int hashtable_insert(HASHTABLE *ht, DATA data)
{
    // your code
    if (!ht)
    {
        return 0;
    }

    // Calculate the Hash value
    int index = hash(data.name, ht->size);
    HNODE *current = ht->hna[index];

    while (current)
    {
        // Double check if the value is already in the hash table
        if (strcmp(current->data.name, data.name) == 0)
        {
            current->data.value = data.value;
            return 0;
        }

        current = current->next;
    }

    // Create a new node
    HNODE *new_node = (HNODE *)malloc(sizeof(HNODE));
    new_node->data = data;
    new_node->next = ht->hna[index];
    ht->hna[index] = new_node;

    ht->count++;
    return 1;
}

int hashtable_delete(HASHTABLE *ht, char *name)
{
    // your code
    if (!ht || !name)
    {
        return 0;
    }

    // Calculate the Hash value
    int index = hash(name, ht->size);
    HNODE *current = ht->hna[index];
    HNODE *prev = NULL;

    while (current)
    {
        // Find the node with the same name
        if (strcmp(current->data.name, name) == 0)
        {
            if (prev)
            {
                prev->next = current->next;
            }
            else
            {
                ht->hna[index] = current->next;
            }

            free(current);
            ht->count--;
            return 1;
        }

        prev = current;
        current = current->next;
    }

    return 0;
}

int hash(char *key, int size)
{
    unsigned int hash = 0;
    while (*key)
    {
        hash += *key++;
    }
    return hash % size;
}

HASHTABLE *new_hashtable(int size)
{
    HASHTABLE *ht = (HASHTABLE *)malloc(sizeof(HASHTABLE));
    ht->hna = (HNODE **)malloc(sizeof(HNODE **) * size);
    int i;
    for (i = 0; i < size; i++)
        *(ht->hna + i) = NULL;

    ht->size = size;
    ht->count = 0;
    return ht;
}

void hashtable_clean(HASHTABLE **htp)
{
    if (*htp == NULL)
        return;
    HASHTABLE *ht = *htp;
    HNODE *p, *temp;
    int i;
    for (i = 0; i < ht->size; i++)
    {
        p = ht->hna[i];
        while (p)
        {
            temp = p;
            p = p->next;
            free(temp);
        }
        ht->hna[i] = NULL;
    }
    free(ht->hna);
    ht->hna = NULL;
    *htp = NULL;
}
