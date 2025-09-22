#include <stdio.h>
#include <stdlib.h>
#include "queueADT2.h"

#define QUEUE_SIZE 100

struct queue_type {
    void **data;
    int top;
    int size;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue queue_create(int size)
{
    Queue q = malloc(sizeof(struct queue_type));

    if (q == NULL)
        terminate("Error in create: queue could not be created.");

    q->data = malloc(size * sizeof(void *));
    if (q == NULL) {
        free(q);
        terminate("Error in create: queue could not be created.");
    }
    q->top = 0;
    q->size = size;

    return q;
}

void queue_destroy(Queue q)
{
    free(q->data);
    free(q);
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
    return q->top == q->size;
}

void queue_enqueue(Queue q, void *v)
{
    if (queue_full(q))
        terminate("Error in queue_enqueue: queue is full.");

    q->data[q->top++] = v;
}

void *queue_dequeue(Queue q) {
    int i;
    void *v;

    if (queue_empty(q))
        terminate("Error in queue_dequeue: queue is empty.");

    v = q->data[0];

    for (i = 1; i < q->top; i++)
        q->data[i - 1] = q->data[i];

    q->top--;

    return v;
}

void *queue_first(Queue q)
{
    if (queue_empty(q))
        terminate("Error in queue_first: queue is empty.");

    return q->data[0];
}

void *queue_last(Queue q)
{
    if (queue_empty(q))
        terminate("Error in queue_last: queue is empty.");

    return q->data[q->top - 1];
}
