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
    queue_linked *queue = malloc(sizeof(queue_linked));

    if (queue == NULL)
    {
        return NULL;
    }

    queue->count = 0;
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

void queue_free(queue_linked **source)
{

    // your code here
    if (source == NULL || *source == NULL)
    {
        return;
    }

    queue_node *current = (*source)->front;

    while (current != NULL)
    {
        queue_node *temp = current;
        data_free(&temp->item);
        current = current->next;
        free(temp);
    }

    free(*source);
    *source = NULL;

    return;
}

bool queue_empty(const queue_linked *source)
{

    // your code here
    return source == NULL || source->front == NULL;
}

int queue_count(const queue_linked *source)
{

    // your code here

    return source == NULL ? 0 : source->count;
}

bool queue_insert(queue_linked *source, data_ptr item)
{

    // your code here
    if (source == NULL)
    {
        return false;
    }

    queue_node *new_node = malloc(sizeof(queue_node));

    if (new_node == NULL)
    {
        return false;
    }

    new_node->item = item;

    if (new_node->item == NULL)
    {
        data_free(&new_node->item);
        return false;
    }

    data_copy(new_node->item, item);
    new_node->next = NULL;

    if (source->rear == NULL)
    {
        source->front = new_node;
        source->rear = new_node;
    }
    else
    {
        source->rear->next = new_node;
        source->rear = new_node;
    }

    source->count++;
    return true;
}

bool queue_peek(const queue_linked *source, data_ptr item)
{

    // your code here
    if (source == NULL || source->front == NULL)
    {
        return false; // 队列为空
    }
    data_copy(item, source->front->item); // 复制头部数据
    return true;
}

bool queue_remove(queue_linked *source, data_ptr *item)
{

    // your code here
    if (source == NULL || source->front == NULL)
    {
        return false;
    }

    queue_node *temp = source->front;

    *item = (data_ptr)malloc(sizeof(**item));

    if (*item == NULL)
    {
        return false;
    }

    data_copy(*item, temp->item);

    source->front = temp->next;

    if (source->front == NULL)
    {
        source->rear = NULL;
    }

    data_free(&temp->item);
    free(temp);
    source->count--;

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