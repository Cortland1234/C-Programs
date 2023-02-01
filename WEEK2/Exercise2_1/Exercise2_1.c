/*****************************************************
 *
 *  CSCV352 - Program2_1.c
 *
 *  Student:  <Cortland Diehm>
 *
******************************************************/
#include <stdio.h>

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

void Nineties()
{
    printf("Counting Crows, Matchbox Twenty");
}

void Eighties()
{
    printf("U2, R.E.M.");
}

int main()
{
    Eighties();
    printf(", ");
    Nineties();
    printf("\n");
    Nineties();
    printf("\n");
    Eighties();


    return 0;
}