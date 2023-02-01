#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        printf("Usage: %s filename", argv[0]);
    }
    else
    {
        FILE *fp = fopen(argv[1], "r");

        if (fp == 0) 
        {
            printf("Could not open file.");
        }
        else
        {
            Queue *my_queue;
            char buf[100];

            my_queue = CreateQueue(sizeof(buf));

            while (fscanf(fp, "%c", buf) != EOF)
            {
                Enqueue(my_queue, &buf);
            }

            while (Dequeue(my_queue, &buf) != 0)
            {
                printf("%s", buf);
            }

            DestroyQueue(my_queue);

            fclose(fp);
        
            return 0;
        }   
    }
}



/*
*  CreateQueue
*
*  Allocations memory for the queue that will hold elements of size elementSize.
*/
Queue *CreateQueue(size_t elementSize) 
{
    Queue *ptr = malloc(sizeof(Queue));
    if( ptr != NULL ) 
    {
       ptr->elementSize    = elementSize;
       ptr->numberElements = 0;
       ptr->head = NULL;
       ptr->tail = NULL;
    }
    return ptr;
 }

/*
*  DestroyQueue
* 
*  Dequeues any remaining elements on the queue and then frees the queue structure. 
*/
int DestroyQueue(Queue *queue)
{
    int result = 0;

    if( queue != NULL )
    {
        // Create a temporary place to store dequeued elements
        unsigned char element[queue->elementSize];

        // Dequeue all objects
        while(queue->numberElements > 0) Dequeue(queue, (void *)&element);

        free(queue);
        result = 1;
    }

    return result;
}
/*
*  Enqueue
* 
*  Pushes a value onto the queue 
*/
int Enqueue(Queue *queue, void *element)
{
    int  result = 0;
    void *new_element;

    if( queue != NULL )
    {
        new_element = malloc(sizeof(DataNode) + queue->elementSize);
        if( new_element != NULL )
        {
            // Fill the memory of the element
            memcpy(((DataNode *)new_element)->data, element, queue->elementSize);

            // Insert this element to the head of the queue
            if( queue->head == NULL )
            {
                // Empty queue
                queue->head = (void *)new_element;
                queue->tail = queue->head;
                ((DataNode *)new_element)->next = NULL;
            }
            else
            {
                // Queue has elements
                ((DataNode *)new_element)->next = queue->head;
                queue->head = new_element;
            }
            queue->numberElements++;
            result = 1;
        }
    }

    return result;
}

/*
*  Dequeue
* 
*  Removes and element from the queue.  
*
*  element must point to a valid element
*
*/
int Dequeue(Queue *queue, void *element)
{
    DataNode *ptr = NULL;
    int result  = 0;

    if( queue != NULL )
    {
        if( queue->numberElements > 0 )
        {
            if( queue->head == queue->tail )
            {
                memcpy(element, (void *)((DataNode *)queue->tail)->data, queue->elementSize);
                free(queue->tail);
                queue->head = queue->tail = NULL;
                queue->numberElements = 0;
            }
            else
            {
                // Dequeue from the tail for FIFO
                ptr = queue->head;
                if (ptr->next != NULL)
                {
                    ptr = ptr->next;
                    memcpy(element,(void *)((DataNode *)queue->head)->data, queue->elementSize);
                    
                    free(queue->head);

                    queue->head = ptr;
                    queue->numberElements--;      
                }

            }
            result = 1;
        }
    }
    return result;
}