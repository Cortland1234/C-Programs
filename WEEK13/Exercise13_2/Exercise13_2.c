#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>


void *Ping(void *a)
{
    int i;

    while(1)
    {
        sleep(1);
        printf("Ping!\n");
    }
    return NULL;
}

void *Pong(void *a)
{
    int i;

    while(1)
    {
        sleep(1);
        printf("Pong!\n");   
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL, Ping, NULL); 
    pthread_create(&thread2, NULL, Pong, NULL);

    pthread_join(thread2, NULL);
    pthread_join(thread1, NULL);
}