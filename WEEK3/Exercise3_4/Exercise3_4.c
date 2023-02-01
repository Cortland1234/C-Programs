/*****************************************************
 *
 *  CSCV352 - Program3_4.c
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

float initialD;
float interestRate;
float timeSaved;

printf("Hello! What is your initial deposit amount? \n");
scanf("%f", &initialD);

printf("What is the annual interest rate? \n");
scanf("%f", &interestRate);

printf("How many years have you saved? \n");
scanf("%f", &timeSaved);

float futureValue = initialD * (1 + interestRate * timeSaved);

printf("The future value of your deposit is: %f\n", futureValue);



    return 0;
}