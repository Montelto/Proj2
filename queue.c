//
// Created by Joseph McFarland on 06-Oct-20.
//

#include "queue.h"

Queue *CreateStringQueue(int size)
{
    // unsure if malloc is correct or if + node * size
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->first = NULL;
    q->last = NULL;
    q->maxSize = size;
    q->size = 0;
    q->enqueueCount = 0;
    q->dequeueCount = 0;
    q->enqueueTime = 0.0;
    q->dequeueTime = 0.0;
    return q;
}

void EnqueueString(Queue *q, char *string)
{
    pthread_mutex_lock(q->lock);
    time_t start = time(NULL);

    while (q->size == q->maxSize)
    {
        pthread_cond_wait(q->full, q->lock);
    }

    struct node *n = malloc(sizeof(struct node));
    n->line = string;
    n->lineSize = 0;
    n->next = NULL;

    if (q->size == 0)
    {
        q->first = n;
        q->last = n;
    } else {
        q->last->next = n;
        q->last = n;
    }

    q->size += 1;
    q->enqueueCount += 1;

    q->enqueueTime = time(NULL) - start;
    pthread_cond_signal(q->empty);
    pthread_mutex_unlock(q->lock);
}

char * DequeueString(Queue *q)
{
    pthread_mutex_lock(q->lock);
    time_t start = time(NULL);

    while (q->size == 0)
    {
        pthread_cond_wait(q->empty, q->lock);
    }

    char *line;
    struct node *temp;
    temp = q->first;
    q->first = q->first->next;
    line = temp->line;
    free(temp);
    q->size -= 1;
    q->dequeueCount += 1;

    q->dequeueTime = time(NULL) - start;
    pthread_cond_signal(q->full);
    pthread_mutex_unlock(q->lock);

    return line;
}

void PrintQueueStats(Queue *q)
{
    printf("Enqueue Count: %d\n", q->enqueueCount);
    printf("Dequeue Count: %d\n", q->dequeueCount);
    printf("Enqueue Time: %ld\n", q->enqueueTime);
    printf("Dequeue Time: %ld\n", q->dequeueTime);
}


