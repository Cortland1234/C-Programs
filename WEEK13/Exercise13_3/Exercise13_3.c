#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void *Ping(void *a)
{
    int i = 0;
    char buffer[] = "Ping";

    while (1)
    {
        putc(buffer[i], stdout);
        i = (i + 1) % strlen(buffer);
        sleep(.1);
    }

    return NULL;
}

void *Pong(void *a)
{
    int i = 0;
    char buffer[] = "Pong";

    while (1)
    {
        putc(buffer[i], stdout);
        i = (i + 1) % strlen(buffer);
        sleep(.1);
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL, Ping, NULL);
    pthread_create(&thread2, NULL, Pong, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

