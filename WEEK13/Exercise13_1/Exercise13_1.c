#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void *Hello(void *a)
{
    int i;

    while(1)
    {
        sleep(1);
        printf("Hello World!\n");
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t thread1;

    pthread_create(&thread1, NULL, Hello, NULL);

    pthread_join(thread1, NULL);


    return 0;
}