#ifndef QUEUE_H
#define QUEUE_H

typedef struct 
{
    size_t elementSize;
    size_t numberElements;
    void *head;
    void *tail;
} Queue;

typedef struct NODE_TYPE 
{
    struct NODE_TYPE *next;
    unsigned char data[0];
} DataNode;


Queue *CreateQueue(size_t elementSize);
int Enqueue(Queue *queue, void *element);
int Dequeue(Queue *queue, void *element);
int DestroyQueue(Queue *queue);

#endif
