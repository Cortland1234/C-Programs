/*****************************************************
 *
 *  CSCV352 - Program2_2.c
 *
 *  Student:  <Cortland Diehm>
 *
******************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
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
int a,b,c;
int numRead;
int numRead2;

    printf("Enter an integer: ");
    numRead = scanf("%d", &a);
    if (numRead != 1)
    {
        printf("Not a valid integer. Shutting Down.");
        return -1;

    }

    printf("Enter a second integer: ");
    numRead2 = scanf("%d", &b);
    if (numRead2 != 1)
    {
        printf("Not a valid integer. Shutting Down.");
        return -1;

    }
    else
    {

        c = pow(a, 3) + b;

        printf("The result is %d", c);

    }

return 0;
}