/*****************************************************
 *
 *  CSCV352 - Program4_2.c
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

    int yearInput;

    printf("Enter a year: \n");
    scanf("%d", &yearInput);

    if ((yearInput % 4) != 0)
    {
        printf("You entered a common year.");
    }
    else if ((yearInput % 100) != 0)
    {
        printf("You entered a leap year!");
    }
    else if ((yearInput % 400) != 0)
    {
        printf("You entered a common year.");
    }
    else
    {
        printf("You entered a leap year!");
    }




    return 0;
}