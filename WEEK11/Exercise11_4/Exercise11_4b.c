#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <semaphore.h>

#define MSG_FILE "data.txt"
#define BUFFER_SIZE 256
#define MESSAGE_OUT "Hello A"
#define MESSAGE_IN "Hello B"
#define SEMAPHORE_NAME "Exercise11_4"

#define O_NONBLOCK 04000

int main()
{
    int msgFile;
    int count;
    char buffer[BUFFER_SIZE];
    sem_t *sem;

    sem = sem_open(SEMAPHORE_NAME, O_CREAT, 0644, 0);

    if(sem == SEM_FAILED)
    {
        printf("ERROR: Cannot open semaphore.\n");
        exit(1);
    }

    if ((msgFile = open(MSG_FILE, O_RDWR | O_CREAT | O_NONBLOCK, S_IRWXU)) == -1)
    {
        printf("ERROR: Unable to open %s\n%d", MSG_FILE, errno);
    }

    while(1)
    {
        //obtain the semaphore with sem_wait()
        sem_wait(sem);

        memset(buffer, 0, sizeof(buffer));

        lseek(msgFile, 0, SEEK_SET);

        //read any messages in file
        count = read(msgFile, buffer, sizeof(buffer));

        //if received message, print message, lseek to beginning, and send message to B
        if (count > 0)
        {
            if (strlen(buffer) == strlen(MESSAGE_IN))
            {
                printf("%s\n", MESSAGE_OUT);
                lseek(msgFile, 0, SEEK_SET);
                write(msgFile, MESSAGE_OUT, strlen(MESSAGE_OUT));
            }
        }

        //signal semaphore with sem_post()
        sem_post(sem);
        sleep(1);
    }

    sem_close(sem);
    close(msgFile);

    return 0;
}