#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


#define MSG_FILE "data.txt"
#define MESSAGE "Message from B: "
#define MESSAGE_IN "Hello A"
#define MESSAGE_OUT "Hello B"
#define BUFFER_SIZE 256

int main()
{
    int msgFile;
    int count;
    char buffer[BUFFER_SIZE];
    int retv;
    int counter = 1;

    if( (msgFile = open(MSG_FILE, O_CREAT | O_RDWR)) == -1 )
    {
        printf("ERROR: Unable to open file.\n");
        exit(1);
    }

    write(msgFile, MESSAGE_OUT, strlen(MESSAGE_OUT));

    while (1)
    {
        int lockResult;
        //lock file
        lockResult = lockf(msgFile, F_LOCK, 0);
        if (lockResult == 0)
        {
            memset(buffer, 0, sizeof(buffer));

            lseek(msgFile, 0, SEEK_SET);

            //read any messages in file
            count = read(msgFile, buffer, sizeof(buffer));

            //if received message, print message, lseek to beginning, and send message to B
            if (count > 0)
            {
                if (strlen(buffer) == strlen(MESSAGE_IN))
                {
                    printf("%s%s\n", MESSAGE, MESSAGE_OUT);
                    lseek(msgFile, 0, SEEK_SET);
                    write(msgFile, MESSAGE_OUT, strlen(MESSAGE_OUT));
                }
            }

            lockf(msgFile, F_ULOCK, 0); 
        }

        sleep(1);

    }

    close(msgFile);
    return 0;
}