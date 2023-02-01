/*****************************************************
 *
 *  CSCV352 - Program5_2.c
 *
 *  Student:  <Cortland Diehm>
 *
******************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////

/*****************************************************
 *
 *  Function:  main()
 *
 *  Parameters:
 *
 *      argc - main parameter for argument count
 *      argv - main parameter for argument values
 *
******************************************************/

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        printf("ERROR. Invalid or missing parameters.\n");
    }
    else
    {
    FILE *fp;
    char buffer[1000];
    long offset = atoi(argv[2]);
    int count = atoi(argv[3]);

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Invalid file.");
        exit(0);
    }

    while ( (fp = fopen(argv[1], "r")) != NULL)
        {
        fseek(fp, offset, SEEK_SET);
        fread(buffer, 1, count, fp);
        }
        printf("%s", buffer);
    }





    return 0;
}