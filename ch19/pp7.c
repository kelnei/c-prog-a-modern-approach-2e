#include <stdio.h>
#include "queueADT.h"

int main(void)
{
    Queue q1, q2;
    char *s = NULL;

    q1 = queue_create();
    q2 = queue_create();

    queue_enqueue(q1, "hello");
    queue_enqueue(q1, "world");
    printf("Head of q1: %s\n", (char *)queue_first(q1));
    printf("Tail of q1: %s\n", (char *)queue_last(q1));

    s = queue_dequeue(q1);
    printf("Popped %s from q1\n", s);
    queue_enqueue(q2, s);
    s = queue_dequeue(q1);
    printf("Popped %s from q1\n", s);
    queue_enqueue(q2, s);

    queue_destroy(q1);

    while (!queue_empty(q2))
        printf("Popped %s from q2\n", (char *)queue_dequeue(q2));

    queue_enqueue(q2, "foobar");
    queue_clear(q2);
    if (queue_empty(q2))
        printf("q2 is empty\n");
    else
        printf("q2 is not empty\n");

    queue_destroy(q2);

    return 0;
}
