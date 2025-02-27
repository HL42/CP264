/**
 * -------------------------------------
 * @file  queue_linked.c
 * Linked Queue Source Code File
 * -------------------------------------
 * @author name, ID, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
// Includes
#include "queue_linked.h"

// Functions

queue_linked *queue_initialize()
{

    // your code here

    return NULL;
}

void queue_free(queue_linked **source)
{

    // your code here

    return;
}

bool queue_empty(const queue_linked *source)
{

    // your code here

    return true;
}

int queue_count(const queue_linked *source)
{

    // your code here

    return 0;
}

bool queue_insert(queue_linked *source, data_ptr item)
{

    // your code here

    return true;
}

bool queue_peek(const queue_linked *source, data_ptr item)
{

    // your code here

    return true;
}

bool queue_remove(queue_linked *source, data_ptr *item)
{

    // your code here

    return true;
}

void queue_print(const queue_linked *source)
{
    char string[DATA_STRING_SIZE];
    queue_node *current = source->front;

    while (current != NULL)
    {
        data_string(string, sizeof string, current->item);
        printf("%s\n", string);
        current = current->next;
    }
    return;
}