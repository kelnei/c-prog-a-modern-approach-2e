#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

#define QUEUE_SIZE 100

struct queue_type {
    void *contents[QUEUE_SIZE];
    int top;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue queue_create(void)
{
    Queue q = malloc(sizeof(struct queue_type));

    if (q == NULL)
        terminate("Error in create: queue could not be created.");

    q->top = 0;

    return q;
}

void queue_destroy(Queue q)
{
    queue_clear(q);
    free(q);
}

void queue_clear(Queue q)
{
    while (!queue_empty(q))
        queue_dequeue(q);
}

int queue_length(Queue q)
{
    return q->top;
}

bool queue_empty(Queue q)
{
    return q->top == 0;
}

bool queue_full(Queue q)
{
    return q->top == QUEUE_SIZE;
}

void queue_enqueue(Queue q, void *v)
{
    if (queue_full(q))
        terminate("Error in queue_enqueue: queue is full.");

    q->contents[q->top++] = v;
}

void *queue_dequeue(Queue q) {
    int i;
    void *v;

    if (queue_empty(q))
        terminate("Error in queue_dequeue: queue is empty.");

    v = q->contents[0];

    for (i = 1; i < q->top; i++)
        q->contents[i - 1] = q->contents[i];

    q->top--;

    return v;
}

void *queue_first(Queue q)
{
    if (queue_empty(q))
        terminate("Error in queue_first: queue is empty.");

    return q->contents[0];
}

void *queue_last(Queue q)
{
    if (queue_empty(q))
        terminate("Error in queue_last: queue is empty.");

    return q->contents[q->top - 1];
}
