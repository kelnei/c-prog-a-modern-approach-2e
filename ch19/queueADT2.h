#ifndef QUEUEADT2_H
#define QUEUEADT2_H

#include <stdbool.h>

typedef struct queue_type *Queue;

Queue queue_create(int size);
void queue_destroy(Queue q);
int queue_length(Queue q);
bool queue_empty(Queue q);
bool queue_full(Queue q);
void queue_enqueue(Queue q, void *);
void *queue_dequeue(Queue q);
void *queue_first(Queue q);
void *queue_last(Queue q);

#endif
