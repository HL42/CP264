/**
 * -------------------------------------
 * @file  graph_am.c
 * Adjacency Matrix Graph Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "graph_am.h"

// Initializes an adjacency matrix graph.
graph_am *graph_am_initialize(int size)
{
    graph_am *source = malloc(sizeof *source);
    source->size = size;
    // Initialize values to zeroes.
    source->values = calloc(size * size, sizeof *source->values);
    return source;
}

void graph_am_free(graph_am **source)
{
    // Free up the data array.
    free((*source)->values);
    (*source)->values = NULL;
    free(*source);
    *source = NULL;
    return;
}

int graph_am_add_vertice(graph_am *source, const graph_am_pair *pair)
{
    int added = 0;

    // your code here
    // check if pair is valid
    if (pair->row < 0 || pair->row >= source->size || pair->col < 0 || pair->col >= source->size)
    {
        return 0;
    }

    int index = pair->row * source->size + pair->col;
    if (pair->row == pair->col)
    {
        source->values[index] = 2;
        added = 1;
    }
    else
    {
        source->values[index] = 1;
        source->values[pair->col * source->size + pair->row] = 1;
        added = 1;
    }

    return added;
}

int graph_am_remove_vertice(graph_am *source, const graph_am_pair *pair)
{
    int removed = 0;

    // your code here
    if (pair->row < 0 || pair->row >= source->size || pair->col < 0 || pair->col >= source->size)
    {
        return removed;
    }

    int index = pair->row * source->size + pair->col;
    if (source->values[index] == 0)
    {
        return removed;
    }

    source->values[index] = 0;
    source->values[pair->col * source->size + pair->row] = 0;
    removed = 1;
    return removed;
}

graph_am *graph_am_create(int size, const graph_am_pair pairs[], int count)
{
    graph_am *source = graph_am_initialize(size);

    // your code here
    for (int i = 0; i < count; i++)
    {
        graph_am_add_vertice(source, &pairs[i]);
    }

    return source;
}

void graph_am_neighbours(const graph_am *source, int vertex, int vertices[], int *count)
{

    // your code here
    *count = 0;

    if (vertex < 0 || vertex >= source->size)
    {
        return;
    }

    // find all connected vertices
    for (int i = 0; i < source->size; i++)
    {
        int index = vertex * source->size + i;

        if (source->values[index] > 0)
        {
            vertices[*count] = i;
            (*count)++;
        }
    }

    return;
}

int graph_am_degree(const graph_am *source, int vertex)
{
    int connected = 0;

    // your code here
    if (source == NULL || vertex < 0 || vertex >= source->size)
    {
        return 0;
    }

    for (int i = 0; i < source->size; i++)
    {
        if (source->values[vertex * source->size + i] > 0)
        {
            if (vertex == i)
            {
                connected += 2; // 自环度数加 2
            }
            else
            {
                connected++;
            }
        }
    }

    return connected;
}

void graph_am_breadth_traversal(const graph_am *source, int vertex, int vertices[], int *count)
{

    // your code here
    int visited[source->size];
    for (int i = 0; i < source->size; i++)
    {
        visited[i] = 0;
    }

    int queue[source->size], front = 0, rear = 0;
    queue[rear++] = vertex;
    visited[vertex] = 1;

    *count = 0;

    while (front < rear)
    {
        int current = queue[front++];
        vertices[(*count)++] = current;

        int neighbours[source->size];
        int count_1 = 0;
        graph_am_neighbours(source, current, neighbours, &count_1);

        for (int i = 0; i < count_1; i++)
        {
            int neighbour = neighbours[i];
            if (!visited[neighbour])
            {
                queue[rear++] = neighbour;
                visited[neighbour] = 1;
            }
        }
    }
    return;
}

void graph_am_depth_traversal(const graph_am *source, int vertex, int vertices[], int *count)
{

    // your code here
    if (source == NULL || vertex < 0 || vertex >= source->size)
    {
        *count = 0;
        return;
    }

    int visited[source->size];
    for (int i = 0; i < source->size; i++)
        visited[i] = 0;

    int stack[source->size];
    int top = -1;

    // Push the starting vertex onto the stack
    stack[++top] = vertex;
    visited[vertex] = 1;

    *count = 0;

    while (top >= 0)
    {
        int current = stack[top--];
        vertices[(*count)++] = current;

        int neighbours[source->size];
        int n_count = 0;
        graph_am_neighbours(source, current, neighbours, &n_count);

        for (int i = 0; i < n_count; i++)
        {
            int next = neighbours[i];
            if (!visited[next])
            {
                stack[++top] = next;
                visited[next] = 1;
            }
        }
    }
}

// Prints the contents of an adjacency matrix graph.
void graph_am_print(const graph_am *source)
{
    // Print the column numbers.
    printf("    ");

    for (int i = 0; i < source->size; i++)
        printf("%3d", i);
    printf("\n");
    printf("    ");
    for (int i = 0; i < source->size; i++)
        printf("---");
    printf("\n");

    // Print the row numbers and rows.
    for (int i = 0; i < source->size; i++)
    {
        printf("%3d|", i);

        for (int j = 0; j < source->size; j++)
        {
            // find item using offsets
            printf("%3d", *(source->values + i * source->size + j));
        }
        printf("\n");
    }
}