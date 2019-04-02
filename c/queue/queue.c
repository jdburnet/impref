#include <assert.h>
#include <stdlib.h>
#include "queue.h"

struct Queue *init(int size)
{
    struct Queue *queue = (struct Queue *)
        malloc(sizeof(struct Queue) + sizeof(int) * size);
    queue->head = 0;
    queue->tail = 0;
    queue->size = size;
    return queue;
}

int empty(struct Queue *queue)
{
    return queue->head == queue->tail;
}

/* allows overflow, need to fix check for full */
int full(struct Queue *queue)
{
    return queue->head == queue->tail + 1;
}

int wouldwrap(int location, int size)
{
    return location + 1 == size;
}

int enqueue(int val, struct Queue *queue)
{
    if (full(queue))
    {
        return -1;
    }

    queue->arr[queue->tail] = val;

    wouldwrap(queue->tail, queue->size)
        ? queue->tail = 0
        : queue->tail++;

    return 0;
}

int dequeue(struct Queue *queue)
{
    //    check is broken, need to fix
//    if (empty(queue))
//    {
//        return -1;
//    }

    int val = queue->arr[queue->head];

    wouldwrap(queue->head, queue->size)
        ? queue->head = 0
        : queue->head++;

    return val;
}

int main(int argc, char **argv)
{
    struct Queue *queue = init(3);
//    assert(empty(queue));
//    assert(dequeue(queue) == -1);
    enqueue(42, queue);
    assert(queue->arr[queue->tail - 1] == 42);
    enqueue(74, queue);
    enqueue(128, queue);
    assert(dequeue(queue) == 42);
}
