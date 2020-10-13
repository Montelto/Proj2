//
// Created by Joseph McFarland on 06-Oct-20.
//

#ifndef PROJ2_QUEUE_H
#define PROJ2_QUEUE_H

#include <pthread.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    char * line;
    int lineSize;
    struct node *next;
};

typedef struct
{
    pthread_mutex_t *lock;
    pthread_cond_t *full;
    pthread_cond_t *empty;

    struct node *first;
    struct node *last;
    int maxSize;
    int size;

    int enqueueCount;
    int dequeueCount;
    time_t enqueueTime;
    time_t dequeueTime;
} Queue;

Queue *CreateStringQueue(int size);

void EnqueueString(Queue *q, char *string);

char * DequeueString(Queue *q);

void PrintQueueStats(Queue *q);

#endif //PROJ2_QUEUE_H
