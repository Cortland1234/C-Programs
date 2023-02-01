#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

#define BUFFER_SIZE 256

#define OUT_FIFO "/tmp/FIFO_BA"
#define IN_FIFO "/tmp/FIFO_AB"
#define MESSAGE_OUT "Hello A"
#define MESSAGE_IN "Hello B"

#define O_NONBLOCK 04000

int main()
{
    int outFifo;
    int inFifo;
    int count;
    char buffer[BUFFER_SIZE];


    if(mkfifo(IN_FIFO, 0666) != 0)
    {
        if (errno != EEXIST)
        {
            printf("ERROR: Unable to create %s\n", IN_FIFO);
            printf("ERROR: errno %d\n", errno);
            exit(1);
        }
    }

    if(mkfifo(OUT_FIFO, 0666) != 0)
    {
        if (errno != EEXIST)
        {
            printf("ERROR: Unable to create %s\n", OUT_FIFO);
            printf("ERROR: errno %d\n", errno);
            exit(1);
        }
    }


    while(1)
    {
        outFifo = open(OUT_FIFO, O_WRONLY | O_NONBLOCK);

        if (outFifo == -1)
        {
            sleep(1);
        }
        else
        {
            break;
        }
        
        if( (inFifo = open(IN_FIFO, O_RDONLY | O_NONBLOCK)) == -1)
        {
            printf("ERROR: Unable to open inFifo A fifo.\n");
            printf("ERROR: errno %d\n", errno);
        }
    }

    while(1)
    {
        memset(buffer, 0, sizeof(buffer));
        count = read(inFifo, buffer, sizeof(buffer));
        

        if (count > 0)
        {
            if (strlen(buffer) == strlen(MESSAGE_IN))
            {
                printf("%s\n", MESSAGE_OUT);
                write(outFifo, MESSAGE_OUT, strlen(MESSAGE_OUT));
            }
        }
        sleep(1);
    }

}