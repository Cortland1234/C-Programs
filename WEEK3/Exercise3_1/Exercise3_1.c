/*****************************************************
 *
 *  CSCV352 - Program3_1.c
 *
 *  Student:  <Cortland Diehm>
 *
******************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>


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


int main()
{

int chCount;
chCount = 0;
int spCount;
spCount =0;
int nlCount;
nlCount = 0;
int i;



printf("Enter a string to get its stats (enter %% or # when complete): \n");
scanf("%d", &i);

while((i=getchar()) != EOF)
{
    if (i != '%' && i !=  '#' && i !=  ' ' && i !=  '\n')
    {
        ++chCount;
    }

    if (i == ' ')
    {
        ++spCount;
    }

    if (i == '\n')
    {
        ++nlCount;
    }

    if (i == '#' || i == '%')
    {
        break;
    }
}

printf("\n");
printf("Number of characters in input: %d\n", chCount);
printf("Number of spaces in the input: %d\n", spCount);
printf("Number of newline characters in the input: %d\n", nlCount);




    return 0;
}