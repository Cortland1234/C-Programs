#include "circular.h"
#include <stdio.h>

void CircularInitialize(CircularQueue * q)
{
    q->count = 0;
}

void CircularEnqueue(CircularQueue * q, int value)
{
    if (q->count < QUEUE_SIZE)
    {
        q->head = (q->head + 1) % QUEUE_SIZE;
        q->data[q->head] = value;
        q->count++;
    }
    else
    {
        q->tail =  (q->tail + 1) % QUEUE_SIZE;
        q->data[q->head++] = value;

    }
}

int CircularDequeue(CircularQueue * q, int * pValue)
{
    int retValue = 0;

    if (q->count > 0)
    {
        q->tail = (q->tail + 1) % QUEUE_SIZE;
        *pValue = q->data[q->tail];
        q->count--;
    }

    return retValue;
}