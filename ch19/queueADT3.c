#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
    void *data;
    struct node *next;
};

struct queue_type {
    struct node *head;
    struct node *tail;
    int len;
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

    q->head = NULL;
    q->tail = NULL;
    q->len = 0;

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
    return q->len;
}

bool queue_empty(Queue q)
{
    return q->len == 0;
}

bool queue_full(Queue q)
{
    ((void)q);
    return false;
}

void queue_enqueue(Queue q, void *v)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: queue is full.");

    new_node->data = v;
    new_node->next = NULL;
    if (q->tail == NULL) {
        q->head = q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
    q->len++;
}

void *queue_dequeue(Queue q) {
    struct node *old_node;
    void *v;

    if (queue_empty(q))
        terminate("Error in queue_dequeue: queue is empty.");

    old_node = q->head;
    v = old_node->data;
    q->head = old_node->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    q->len--;
    free(old_node);
    return v;
}

void *queue_first(Queue q)
{
    if (queue_empty(q))
        terminate("Error in queue_first: queue is empty.");

    return q->head->data;
}

void *queue_last(Queue q)
{
    if (queue_empty(q))
        terminate("Error in queue_last: queue is empty.");

    return q->tail->data;
}
