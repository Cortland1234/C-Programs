/*****************************************************
 *
 *  CSCV352 - Program5_1.c
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
    
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Invalid file.");
        exit(0);
    }
    char buff[256];
    size_t i;

    if (argc != 3)
    {
        printf("ERROR. Invalid or missing arguments."); 
    }
    else
    {
        while(!feof(fp)){

            fgets(buff, 256, fp);
        }

        for (i = 0; i < 256; i++)
        {
            buff[i] = tolower(buff[i]);
        }


        FILE *fp2;
        fp2 = fopen(argv[2], "w+");
        fputs(buff, fp2);

        printf("The new file has been converting to lowercase.\n");
        fclose(fp2);

    }
    fclose(fp);

    return 0;
}