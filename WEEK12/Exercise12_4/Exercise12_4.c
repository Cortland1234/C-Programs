#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
    FILE *fp;

    fp = fopen("nonexistentfile.txt", "r");

    if (fp == NULL)
    {
        printf("ERRNO: %d\n", errno);
        perror("PERROR: ");
        return(-1);
    }
    fclose(fp);

    return 0;
}