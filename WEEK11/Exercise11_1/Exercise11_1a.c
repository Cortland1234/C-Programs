#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define IN_FILE "BtoA.txt"
#define OUT_FILE "AtoB.txt"
#define MESSAGE "Hello B"
#define BUFFER_SIZE 256

#define O_NONBLOCK 04000

int main()
{
    int inFile;
    int outFile;
    int count = 0;
    char buffer[BUFFER_SIZE];

    if ( (outFile = open(OUT_FILE, O_CREAT | O_APPEND | O_WRONLY | O_NONBLOCK, 0777)) == -1 )
    {
        printf("ERROR: Unable to open %s\n", OUT_FILE);
        exit(1);
    }


    if ( (inFile = open(IN_FILE, O_CREAT | O_RDWR | O_NONBLOCK, 0777)) == -1 )
    {
        printf("ERROR: Unable to open %s\n", OUT_FILE);
        exit(1);
    }

    write(outFile, MESSAGE, strlen(MESSAGE));

    while(1)
    {
        memset(buffer, 0, sizeof(buffer));
        count = read(inFile, buffer, sizeof(buffer));

        if (count > 0)
        {
            if (strlen(buffer) == strlen(MESSAGE))
            {
                printf("%s\n", MESSAGE);
                write(outFile, MESSAGE, strlen(MESSAGE));
            }
        }
        sleep(1);
    }

    close(outFile);
    close(inFile);
    return 0;
}